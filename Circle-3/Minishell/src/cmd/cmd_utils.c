/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:09:16 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 18:57:11 by alpha            ###   ########.fr       */
/*   Updated: 2024/12/22 20:36:38 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	find_and_exec_cmd(t_data *data, char **splited_path, int i,
		char **env)
{
	int		j;
	char	*path;

	j = 0;
	while (splited_path[j])
	{
		path = ft_strjoin3(splited_path[j], "/", data->cmds[i].cmd[0]);
		if (!path)
			return (1);
		if (!access(path, F_OK))
			break ;
		free(path);
		j++;
	}
	if (splited_path[j])
	{
		free_double(splited_path);
		if (execve(path, data->cmds[i].cmd, env) < 0)
			return (free(path), 0);
	}
	return (1);
}

static int	run_cmd_with_path(t_data *data, int i, char **env)
{
	char	*path;
	char	**splited_path;

	path = get_env(data, "PATH");
	if (!path)
		path = data->aux_path;
	if (path)
	{
		splited_path = ft_split(path, ':');
		free(path);
		if (!splited_path)
			return (1);
		if (find_and_exec_cmd(data, splited_path, i, env))
			free_double(splited_path);
	}
	print_error(NULL, data->cmds[i].cmd[0], "command not found");
	free_tokens(data->tokens);
	return (127);
}

static int	exec_absolute_path(t_data *data, int i, char **env)
{
	int	err;

	err = 1;
	if (!access(data->cmds[i].cmd[0], F_OK))
	{
		if (access(data->cmds[i].cmd[0], X_OK))
			print_error(NULL, data->cmds[i].cmd[0], "Permission denied");
		else if (execve(data->cmds[i].cmd[0], data->cmds[i].cmd, env))
			print_error(NULL, data->cmds[i].cmd[0], "is a directory");
		err = 126;
	}
	else
	{
		print_error(NULL, data->cmds[i].cmd[0], "No such file or directory");
		err = 127;
	}
	return (err);
}

static int	exec_relative_path(t_data *data, int i, char **env)
{
	char	*pwd;
	char	*path;
	int		err;

	err = 1;
	pwd = getcwd(NULL, 0);
	path = ft_strjoin3(pwd, "/", data->cmds[i].cmd[0]);
	if (!path)
		return (1);
	if (!access(path, F_OK))
	{
		if (access(path, X_OK))
			print_error(NULL, data->cmds[i].cmd[0], "Permission denied");
		else if (execve(path, data->cmds[i].cmd, env))
			print_error(NULL, data->cmds[i].cmd[0], "is a directory");
		err = 126;
	}
	else
	{
		print_error(NULL, data->cmds[i].cmd[0], "No such file or directory");
		err = 127;
	}
	free(path);
	free(pwd);
	return (err);
}

void	exec_cmd(t_data *data, int i)
{
	char	**env;
	int		err;

	err = 0;
	env = conv_to_execv_format(data);
	if (!env)
		exit(1);
	if (data->cmds[i].cmd[0][0] == '/')
		err = exec_absolute_path(data, i, env);
	else if (is_path(data->cmds[i].cmd[0]))
		err = exec_relative_path(data, i, env);
	else
		err = run_cmd_with_path(data, i, env);
	free_double(env);
	exit(err);
}
