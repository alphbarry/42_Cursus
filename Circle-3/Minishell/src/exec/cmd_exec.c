/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:00:53 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 22:22:21 by alpha            ###   ########.fr       */
/*   Updated: 2024/12/27 20:01:24 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	count_cmd(t_token *tokens)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (tokens[i].token)
	{
		if (tokens[i].type == PIPE)
			count++;
		i++;
	}
	return (count);
}

static int	len_cmd(t_token *tokens, int *i)
{
	int	j;
	int	count;

	i[4] = 0;
	while (tokens[i[4]].token && tokens[i[4]].type != PIPE)
		i[4]++;
	j = 0;
	count = 0;
	while (tokens[j].token && tokens[j].type != PIPE)
	{
		if (tokens[j].type == REDIR_ERROR)
			break ;
		if (tokens[j].type == TOKEN)
		{
			if (!j || (j > 0 && tokens[j - 1].type != REDIR && tokens[j
						- 1].type != HDOC))
				count++;
		}
		j += (tokens[j].type == REDIR || tokens[j].type == HDOC);
		j++;
	}
	i[1] = count;
	return (0);
}

static int	cmd_malloc(t_data *data, int *i)
{
	data->cmds[i[0]].cmd = malloc((i[1] + 1) * sizeof(char *));
	if (!data->cmds[i[0]].cmd)
	{
		free_cmds(data->cmds);
		return (1);
	}
	return (0);
}

int	cmd_exec(t_data *data, t_token *tokens)
{
	int	cmd_c;
	int	i[5];

	cmd_c = count_cmd(tokens);
	data->cmds = malloc((cmd_c + 1) * sizeof(t_cmd));
	if (!data->cmds)
		return (1);
	data->cmds[cmd_c].cmd = NULL;
	i[0] = -1;
	i[3] = 0;
	while (++i[0] < cmd_c)
	{
		if (len_cmd(tokens + i[3], i))
			return (free(data->cmds), 0);
		if (cmd_malloc(data, i))
			return (1);
		if (setup_cmd_io(&(data->cmds[i[0]]), tokens + i[3], i[4]))
			return (free_cmds(data->cmds), 1);
		data->cmds[i[0]].cmd[i[1]] = NULL;
		i[2] = -1;
		if (fill_cmd(data, i, tokens))
			return (free_cmds(data->cmds), 1);
		i[3] += i[2] + 1;
	}
	return (0);
}
