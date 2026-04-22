/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:30:21 by alpha             #+#    #+#             */
/*   Updated: 2025/04/14 15:56:29 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	remove_latest_hd(t_data *data, int *i)
{
	char	*filename;

	if (data->hdcs[i[0]][i[1]].curr)
	{
		filename = build_temp_hdoc_filename(data, i);
		if (!filename)
			return (1);
		unlink(filename);
		if (data->hdcs[i[0]][i[1]].expand)
		{
			filename = ft_strjoin_free(filename, "_exp");
			if (!filename)
				return (1);
			unlink(filename);
		}
		free(filename);
	}
	return (0);
}

static void	clear_all_hds(t_data *data)
{
	int	i[2];

	if (!data->hdcs || !data)
		return ;
	i[0] = 0;
	while (data->hdcs[i[0]])
	{
		i[1] = 0;
		while (data->hdcs[i[0]][i[1]].str)
		{
			if (remove_latest_hd(data, i))
				return ;
			i[1]++;
		}
		i[0]++;
	}
}

static void	clean_tokens_hdcs(t_data *data)
{
	if (data->tokens_list)
	{
		free_token_list(data->tokens_list);
		data->tokens_list = NULL;
	}
	if (data->tokens)
	{
		free_tokens(data->tokens);
		data->tokens = NULL;
		data->tokens_count = 0;
	}
	if (data->hdcs)
	{
		free_hdocs(data->hdcs);
		data->hdcs = NULL;
		data->hdoc_count = 0;
	}
}

void	clear_shell_status(t_data *data)
{
	clean_tokens_hdcs(data);
	clear_all_hds(data);
	data->exit_status = 0;
	data->sp_hdoc = -1;
	data->env_copy = NULL;
	free(data->hdoc_id);
	data->hdoc_id = NULL;
	if (data->env)
	{
		free_env(data->env);
		data->env = NULL;
	}
	if (data->in_fd >= 0)
		close(data->in_fd);
	if (data->out_fd >= 0)
		close(data->out_fd);
	data->in_fd = -1;
	data->out_fd = -1;
}
