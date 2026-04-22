/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:42:23 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 19:11:56 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	process_hdoc_input(int fd, char *eof)
{
	int		eoflen;
	char	*hline;

	eoflen = ft_strlen(eof);
	hline = NULL;
	while (1)
	{
		if (hline && !ft_strncmp(hline, eof, eoflen + 1))
			break ;
		if (hline && write(fd, hline, ft_strlen(hline)) == -1)
			return (free(hline), 1);
		if (hline && write(fd, "\n", 1) == -1)
			return (free(hline), 1);
		if (hline)
			free(hline);
		hline = readline("> ");
		if (!hline)
		{
			free(hline);
			return (0);
		}
	}
	free(hline);
	return (0);
}

static int	exec_hdoc(t_data *data, int *i)
{
	int		fd;
	char	*fname;

	if (data->hdcs[i[0]][i[1]].curr)
	{
		fname = build_temp_hdoc_filename(data, i);
		fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			exit(1);
		if (process_hdoc_input(fd, data->hdcs[i[0]][i[1]].str))
		{
			close(fd);
			free(fname);
			exit(1);
		}
		close(fd);
		free(fname);
	}
	else if (simulate_hdoc(data->hdcs[i[0]][i[1]].str))
		exit(1);
	return (0);
}

static int	fork_process(t_data *data, int *i)
{
	signal(SIGINT, handle_sigint_hdoc);
	signal(SIGQUIT, SIG_IGN);
	i[0] = 0;
	while (data->hdcs[i[0]])
	{
		i[1] = 0;
		while (data->hdcs[i[0]][i[1]].str)
		{
			if (exec_hdoc(data, i))
				exit(1);
			i[1]++;
		}
		i[0]++;
	}
	exit(0);
}

static void	check_exit_status(t_data *data, int status)
{
	if (WIFEXITED(status))
	{
		if (status == 256)
		{
			g_err = 1;
			data->exit_status = 1;
		}
	}
	else if (WIFSIGNALED(status) && (WTERMSIG(status) == SIGINT))
	{
		g_err = 1;
		data->exit_status = 1;
	}
}

t_error	manage_hdocs_processing(t_data *data)
{
	int		i[2];
	pid_t	pid;
	int		status;

	if (data->total_hdocs == 0)
		return (NULL_ERR);
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (FORK_ERR);
	}
	if (pid == 0)
		fork_process(data, i);
	else
		signal(SIGINT, SIG_IGN);
	wait(&status);
	check_exit_status(data, status);
	return (NULL_ERR);
}
