/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:50:00 by alphbarr          #+#    #+#             */
/*   Updated: 2025/04/13 18:41:01 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			g_err;

void	init_basic_data(t_data *data, char **envp)
{
	data->tokens = NULL;
	data->tokens_list = NULL;
	data->tokens_count = 0;
	data->error_tok_name = NULL;
	data->cmds = NULL;
	data->curr_cmd = 0;
	data->hdcs = NULL;
	data->hdoc_count = 0;
	data->error_tok_pos = 0;
	data->aux_error = 0;
	data->total_hdocs = 0;
	data->exit_status = 0;
	data->sp_hdoc = -1;
	data->aux_path = ft_strdup("PATH=/usr/bin:/bin:/usr/sbin:/sbin");
	if (envp && *envp)
		data->env_copy = envp;
	else
		data->env_copy = create_env();
}

static int	init_data(t_data *data, char **envp)
{
	init_basic_data(data, envp);
	data->hdoc_id = ft_itoa(getpid());
	if (!data->hdoc_id)
		return (perror("Failed to allocate hdoc_id"), 1);
	data->in_fd = dup(0);
	if (data->in_fd < 0)
		return (free(data->hdoc_id), perror("dup in_fd failed"), 1);
	data->out_fd = dup(1);
	if (data->out_fd < 0)
		return (free(data->hdoc_id), perror("dup out_fd failed"), 1);
	if (data->in_fd < 0 || data->out_fd < 0)
		return (free(data->hdoc_id), 1);
	if (!data->env_copy)
		return (free(data->hdoc_id), close(data->in_fd), close(data->out_fd),
			1);
	data->env = allocate_env_struct(data->env_copy);
	if (!data->env)
	{
		close(data->in_fd);
		close(data->out_fd);
		return (free(data->hdoc_id), 1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	g_err = 0;
	if (init_data(&data, envp))
		return (1);
	exec_shell(&data);
	return (0);
}
