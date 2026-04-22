/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:21:07 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 18:55:22 by alpha            ###   ########.fr       */
/*   Updated: 2024/12/27 19:38:47 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	count_io_redirs(t_cmd *cmds, t_token *tokens, int u)
{
	int	i;
	int	c;
	int	finished;

	i = 0;
	c = 0;
	finished = 0;
	while (tokens[i].token && i < u)
	{
		c += tokens[i].type == HDOC || tokens[i].type == REDIR
			|| tokens[i].type == REDIR_ERROR;
		if (!finished && (tokens[i].type == REDIR_ERROR))
		{
			finished = 1;
			cmds->error_redir_pos = c - 1;
		}
		i++;
	}
	return (c);
}

int	setup_cmd_io(t_cmd *cmds, t_token *tokens, int i)
{
	int	io_num;

	cmds->error_redir_pos = -42;
	io_num = count_io_redirs(cmds, tokens, i);
	cmds->redir_info = malloc(sizeof(t_redir_io) * (io_num + 1));
	if (!cmds->redir_info)
		return (1);
	return (0);
}
