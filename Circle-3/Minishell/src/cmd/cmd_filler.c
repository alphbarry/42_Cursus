/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:44:21 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 22:21:33 by alpha            ###   ########.fr       */
/*   Updated: 2024/12/27 20:00:51 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	io_type(t_data *data, int *i, t_token *tokens, int k)
{
	if (!ft_strncmp(tokens[i[2] + i[3]].token, "<", 2))
		data->cmds[i[0]].redir_info[k].dup_fd = 0;
	else if (!ft_strncmp(tokens[i[2] + i[3]].token, ">", 2))
		data->cmds[i[0]].redir_info[k].dup_fd = 0;
	else if (!ft_strncmp(tokens[i[2] + i[3]].token, "<<", 3))
		data->cmds[i[0]].redir_info[k].dup_fd = 1;
	else if (!ft_strncmp(tokens[i[2] + i[3]].token, ">>", 3))
		data->cmds[i[0]].redir_info[k].dup_fd = 1;
}

static int	fill_in_redir(t_data *d, int *i, t_token *ts, int *k)
{
	d->cmds[i[0]].redir_info[*k].in = 1;
	io_type(d, i, ts, *k);
	d->cmds[i[0]].redir_info[*k].filename = ft_strdup(ts[i[2] + i[3]
			+ 1].token);
	if (!d->cmds[i[0]].redir_info[*k].filename)
		return (1);
	(*k)++;
	i[2]++;
	return (0);
}

static int	fill_out_redir(t_data *d, int *i, t_token *ts, int *k)
{
	d->cmds[i[0]].redir_info[*k].in = 0;
	io_type(d, i, ts, *k);
	d->cmds[i[0]].redir_info[*k].filename = ft_strdup(ts[i[2] + i[3]
			+ 1].token);
	if (!d->cmds[i[0]].redir_info[*k].filename)
		return (1);
	(*k)++;
	i[2]++;
	return (0);
}

static int	process_redirs(t_data *data, int *i, t_token *ts, int *k)
{
	if (!ts[i[2] + i[3] + 1].token)
		return (SYNTAX_ERR);
	if (!ft_strncmp(ts[i[2] + i[3]].token, "<", 2) || !ft_strncmp(ts[i[2]
				+ i[3]].token, "<<", 3))
	{
		if (fill_in_redir(data, i, ts, k))
			return (1);
	}
	else if (!ft_strncmp(ts[i[2] + i[3]].token, ">", 2) || !ft_strncmp(ts[i[2]
				+ i[3]].token, ">>", 3))
	{
		if (fill_out_redir(data, i, ts, k))
			return (1);
	}
	return (0);
}

int	fill_cmd(t_data *data, int *i, t_token *ts)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	while (++i[2] < i[4])
	{
		if (ts[i[2] + i[3]].type == REDIR_ERROR)
		{
			g_err = 1;
			i[2] = i[4];
			break ;
		}
		if (ts[i[2] + i[3]].type == REDIR || ts[i[2] + i[3]].type == HDOC)
		{
			if (process_redirs(data, i, ts, &k))
				return (1);
		}
		else if (save_cmd(data, i, &j, ts))
			return (1);
	}
	data->cmds[i[0]].redir_info[k].filename = NULL;
	return (0);
}
