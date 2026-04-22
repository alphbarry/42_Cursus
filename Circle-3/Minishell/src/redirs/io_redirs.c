/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:03:13 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 20:11:21 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	handle_infile(t_data *data, int *i, int *fdio)
{
	if (fdio[0] != -42)
		close(fdio[0]);
	if (data->cmds[i[0]].redir_info[i[1]].dup_fd)
	{
		if (data->hdcs[data->curr_cmd][data->hdoc_count].curr)
			fdio[0] = handle_hdoc_expansion(data);
		data->hdoc_count++;
	}
	else
		fdio[0] = open(data->cmds[i[0]].redir_info[i[1]].filename, O_RDONLY);
	if (fdio[0] == -1)
		return (g_err = 1, -2);
	else if (fdio[0] == -2)
		return (g_err = 1, -1);
	return (0);
}

static int	handle_outfile(t_data *data, int *i, int *fdio)
{
	int	flags;

	if (fdio[1] != -42)
		close(fdio[1]);
	if (data->cmds[i[0]].redir_info[i[1]].dup_fd)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	fdio[1] = open(data->cmds[i[0]].redir_info[i[1]].filename, flags, 0644);
	if (fdio[1] == -1)
		return (g_err = 1, -2);
	return (0);
}

static int	decide_io_handling(t_data *data, int *i, int *fdio)
{
	int	retcode;

	if (data->cmds[i[0]].redir_info[i[1]].in)
	{
		retcode = handle_infile(data, i, fdio);
		if (retcode)
			return (retcode);
	}
	else
	{
		retcode = handle_outfile(data, i, fdio);
		if (retcode)
			return (retcode);
	}
	return (0);
}

static void	init_open_context(t_data *data, int *i, int *fdio)
{
	data->cmds[i[0]].input_fd = -42;
	data->cmds[i[0]].output_fd = -42;
	i[1] = 0;
	fdio[0] = -42;
	fdio[1] = -42;
}

int	open_all_files(t_data *data)
{
	int	i[2];
	int	fdio[2];
	int	retcode;

	i[0] = 0;
	if (!data->cmds)
		return (0);
	data->hdoc_count = 0;
	while (data->cmds[i[0]].cmd)
	{
		init_open_context(data, i, fdio);
		while (data->cmds[i[0]].redir_info[i[1]].filename)
		{
			retcode = decide_io_handling(data, i, fdio);
			if (retcode)
				return (open_error(data->cmds[i[0]].redir_info[i[1]].filename),
					retcode);
			i[1]++;
		}
		assign_or_close_fds(data, i, fdio);
		i[0]++;
	}
	return (0);
}
