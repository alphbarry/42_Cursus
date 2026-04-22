/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:20:14 by alpha             #+#    #+#             */
/*   Updated: 2025/04/14 16:01:25 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	init_shell_steps(t_data *data, char *s)
{
	data->aux_error = NULL_ERR;
	if (s && s[0])
		add_history(s);
}

static int	validate_syntax(t_data *data, int tokens_count)
{
	int	j;

	if (!ft_strcmp(data->tokens[0].token, "|")
		|| !ft_strcmp(data->tokens[tokens_count - 1].token, "|")
		|| !ft_strcmp(data->tokens[0].token, "||")
		|| !ft_strcmp(data->tokens[tokens_count - 1].token, "||"))
		return (SYNTAX_ERR);
	j = 0;
	while (j < tokens_count - 1)
	{
		if ((!ft_strcmp(data->tokens[j].token, "|") && !ft_strcmp(data->tokens[j
						+ 1].token, "|")) || (!ft_strcmp(data->tokens[j].token,
					"||") && !ft_strcmp(data->tokens[j + 1].token, "||")))
			return (SYNTAX_ERR);
		j++;
	}
	return (0);
}

static int	check_redirections(t_data *data, int tokens_count)
{
	int	j;

	j = 0;
	while (j < tokens_count)
	{
		if ((!ft_strcmp(data->tokens[j].token, "<")
				|| !ft_strcmp(data->tokens[j].token, ">")
				|| !ft_strcmp(data->tokens[j].token, ">>")
				|| !ft_strcmp(data->tokens[j].token, "<<")) && (!data->tokens[j
					+ 1].token || !ft_strcmp(data->tokens[j + 1].token, "|")))
		{
			data->error_tok_pos = j;
			data->error_tok_name = data->tokens[j].token;
			return (SYNTAX_ERR);
		}
		j++;
	}
	return (0);
}

static int	exec_shell_steps(t_data *data, char *s)
{
	t_error	error;
	int		tokens_count;

	init_shell_steps(data, s);
	error = tokenize(s, data);
	if (error >= MALLOC_ERR)
		return (error);
	tokens_count = data->tokens_count;
	if (tokens_count == 0 || !data->tokens[0].token)
		return (NULL_ERR);
	error = validate_syntax(data, tokens_count);
	if (error)
		return (error);
	error = check_redirections(data, tokens_count);
	if (error)
		return (error);
	error = init_hdocs(data);
	if (error >= MALLOC_ERR)
		return (error);
	error = manage_hdocs_processing(data);
	if (error >= MALLOC_ERR)
		return (error);
	if (data->sp_hdoc > 0)
		return (SYNTAX_ERR);
	return (exec_token(data));
}

void	exec_shell(t_data *data)
{
	t_error	error;
	char	*s;

	while (1)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		s = readline("minibash $ ");
		if (!s)
		{
			write(1, "exit\n", 5);
			clear_shell_status(data);
			exit(g_err);
		}
		error = exec_shell_steps(data, s);
		error_handler(data, error);
		free(s);
		free_tokens(data->tokens);
		data->tokens = NULL;
		free_token_list(data->tokens_list);
		data->tokens_list = NULL;
		free_hdocs(data->hdcs);
		data->hdcs = NULL;
	}
	clear_shell_status(data);
}
