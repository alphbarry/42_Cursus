/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:58:14 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 19:05:29 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_error	run_cmd(t_data *data, t_token *tokens)
{
	t_token	*new_tokens;
	int		open_error;

	new_tokens = token_expander(data, tokens);
	if (!new_tokens)
		return (MALLOC_ERR);
	open_error = cmd_exec(data, new_tokens);
	if (!open_error)
	{
		open_error = open_all_files(data);
		if (!open_error)
		{
			exec_cmds(data);
			if (dup2(data->out_fd, 1) < 0 || dup2(data->in_fd, 0) < 0)
				return (free_tokens(new_tokens), DUP2_ERR);
		}
		else if (open_error == -2 || open_error == -1)
			return (free_tokens(new_tokens), OPEN_ERR);
	}
	free_tokens(new_tokens);
	if (open_error == 1)
		return (MALLOC_ERR);
	return (NULL_ERR);
}

t_error	exec_token(t_data *data)
{
	int	i;

	data->tokens_list = create_tokens_list(data->tokens);
	if (!data->tokens_list)
		return (MALLOC_ERR);
	i = 0;
	data->curr_cmd = 0;
	while (data->tokens_list[i])
	{
		if ((data->tokens_list[i][0].type == AND && g_err)
			|| (data->tokens_list[i][0].type == OR && !g_err))
			i++;
		else if (data->tokens_list[i][0].type != AND
			&& data->tokens_list[i][0].type != OR)
		{
			data->curr_cmd = i / 2;
			run_cmd(data, data->tokens_list[i]);
		}
		i++;
	}
	return (NULL_ERR);
}
