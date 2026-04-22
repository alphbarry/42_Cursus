/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:38:57 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 22:18:23 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_token	*allocate_token(int size)
{
	t_token	*tokens;

	if (size < 0)
		return (NULL);
	tokens = malloc(sizeof(t_token) * (size + 1));
	if (!tokens)
		return (NULL);
	tokens[size].token = NULL;
	return (tokens);
}

static t_token	*convert_cmd_to_tokens(char **cmd)
{
	int		i;
	t_token	*tokens;

	if (!cmd)
		return (NULL);
	i = 0;
	while (cmd[i])
		i++;
	tokens = allocate_token(i);
	i = 0;
	while (cmd[i])
	{
		tokens[i].token = ft_strdup(cmd[i]);
		if (!tokens[i].token)
		{
			while (i-- > 0)
				free(tokens[i].token);
			return (free(tokens), NULL);
		}
		tokens[i].type = TOKEN;
		tokens[i].literal = NULL;
		i++;
	}
	tokens[i].token = NULL;
	return (tokens);
}

static int	execute_builtin(char **cmd, t_token *tokens, t_data *data)
{
	if (!tokens)
		return (1);
	if (ft_strncmp(cmd[0], "echo", 5) == 0)
		return (do_echo(tokens));
	else if (ft_strncmp(cmd[0], "cd", 3) == 0)
		return (ft_cd(tokens, data));
	else if (ft_strncmp(cmd[0], "pwd", 4) == 0)
		return (get_pwd());
	else if (ft_strncmp(cmd[0], "export", 7) == 0)
		return (ft_export(tokens, data, 0));
	else if (ft_strncmp(cmd[0], "unset", 6) == 0)
		return (ft_unset(tokens, data));
	else if (ft_strncmp(cmd[0], "env", 4) == 0)
		return (print_env_list(data->env));
	else if (ft_strncmp(cmd[0], "exit", 5) == 0)
		return (do_exit(data, cmd + 1));
	return (-1);
}

int	which_built(t_data *data, int i, int ex)
{
	int		error;
	char	**cmd;
	t_token	*tokens;

	if (!data || !data->cmds || !data->cmds[i].cmd || !data->cmds[i].cmd[0])
		return (0);
	cmd = data->cmds[i].cmd;
	tokens = convert_cmd_to_tokens(cmd);
	if (!tokens)
		return (0);
	error = execute_builtin(cmd, tokens, data);
	if (error == -1)
	{
		free_tokens(tokens);
		return (0);
	}
	if (!ex)
		free_tokens(tokens);
	if (ex)
		exit(error);
	g_err = error;
	return (1);
}
