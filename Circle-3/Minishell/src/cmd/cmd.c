/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:10:31 by alphbarr          #+#    #+#             */
/*   Updated: 2025/04/14 15:46:50 by alpha            ###   ########.fr       */
/*   Updated: 2024/12/22 20:46:42 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static pid_t	exec_single_cmd(t_data *data)
{
	pid_t	pid;

	if (!data->cmds[0].cmd[0] || data->cmds[0].error_redir_pos >= 0)
		return (-1);
	if (data->cmds[0].input_fd != -42 && dup2(data->cmds[0].input_fd, 0) < 0)
		return (data->aux_error = DUP2_ERR, -1);
	if (data->cmds[0].output_fd != -42 && dup2(data->cmds[0].output_fd, 1) < 0)
		return (data->aux_error = DUP2_ERR, -1);
	if (!which_built(data, 0, 0))
	{
		pid = fork();
		if (pid < 0)
			return (data->aux_error = FORK_ERR, -1);
		else if (!pid)
		{
			reset_signals();
			exec_cmd(data, 0);
		}
		return (pid);
	}
	return (-1);
}

int	exec_cmds(t_data *data)
{
	int		i;
	int		end[2];
	int		status;
	pid_t	pid;

	signal(SIGINT, SIG_IGN);
	if (!data->cmds[1].cmd)
		pid = exec_single_cmd(data);
	else
	{
		if (data->cmds[0].input_fd != -42 && dup2(data->cmds[0].input_fd,
				0) < 0)
			return (data->aux_error = DUP2_ERR, 1);
		pid = exec_piped_cmds(data, end);
	}
	i = -1;
	while (data->cmds[++i].cmd && pid > 0)
	{
		if (waitpid(-1, &status, 0) == pid)
			g_err = status;
	}
	if (pid != -1)
		process_signals(status);
	if (data->cmds)
		free_cmds(data->cmds);
	return (data->cmds = NULL, g_err);
}
