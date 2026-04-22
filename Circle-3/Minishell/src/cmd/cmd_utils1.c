/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:31:42 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 22:21:16 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	save_cmd(t_data *data, int *i, int *j, t_token *ts)
{
	data->cmds[i[0]].cmd[*j] = ft_strdup(ts[i[2] + i[3]].token);
	if (!data->cmds[i[0]].cmd[(*j)++])
		return (1);
	return (0);
}

int	is_path(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

static t_error	exec_intermediate_cmd(t_data *data, int *end, int i, pid_t *pid)
{
	if (pipe(end) < 0)
		return (PIPE_ERR);
	*pid = fork();
	if (*pid < 0)
		return (FORK_ERR);
	else if (!*pid)
	{
		reset_signals();
		if (data->cmds[i].output_fd != -42 && dup2(data->cmds[i].output_fd,
				1) < 0)
			print_perror("Dup out on child redirect", 1);
		else if (data->cmds[i].output_fd == -42 && dup2(end[1], 1) < 0)
			print_perror("Dup out on child pipe", 1);
		if (close(end[0]) < 0 || close(end[1]) < 0)
			print_perror("Close end on child", 1);
		if (!data->cmds[i].cmd[0] || data->cmds[i].error_redir_pos >= 0)
			exit(0);
		if (!which_built(data, i, 1))
			exec_cmd(data, i);
	}
	close(0);
	return (NULL_ERR);
}

static pid_t	exec_last_cmd(t_data *data, int i)
{
	pid_t	pid;

	if (data->cmds[i].output_fd != -42 && dup2(data->cmds[i].output_fd, 1) < 0)
		return (data->aux_error = DUP2_ERR, -1);
	pid = fork();
	if (pid < 0)
		return (print_perror("Fork last", -1), -1);
	else if (!pid)
	{
		reset_signals();
		if (!data->cmds[i].cmd[0] || data->cmds[i].error_redir_pos >= 0)
			exit(0);
		if (!which_built(data, i, 1))
			exec_cmd(data, i);
	}
	close(0);
	return (pid);
}

pid_t	exec_piped_cmds(t_data *data, int *end)
{
	int		i;
	pid_t	pid;
	t_error	err;

	i = 0;
	while (data->cmds[i].cmd && data->cmds[i + 1].cmd)
	{
		err = exec_intermediate_cmd(data, end, i, &pid);
		if (err != NULL_ERR)
			return (data->aux_error = err, -1);
		if (data->cmds[i + 1].input_fd != -42 && dup2(data->cmds[i
					+ 1].input_fd, 0) < 0)
			return (data->aux_error = DUP2_ERR, -1);
		else if (data->cmds[i + 1].input_fd == -42 && dup2(end[0], 0) < 0)
			return (data->aux_error = DUP2_ERR, 1);
		if (close(end[0]) < 0 || close(end[1]) < 0)
			return (data->aux_error = CLOSE_ERR, 1);
		i++;
	}
	pid = exec_last_cmd(data, i);
	return (pid);
}
