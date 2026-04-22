/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:11:20 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 20:10:54 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	expand_hdoc_line(t_data *data, char **filename, int hdocfd)
{
	int		susfd;
	char	*currline;

	*filename = ft_strjoin_free(*filename, "_exp");
	if (!*filename)
		return (-1);
	susfd = open(*filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (susfd == -1)
		return (-2);
	currline = get_next_line(hdocfd);
	while (currline)
	{
		currline = expand_dollar_variables(currline, data);
		if (!currline)
			return (-1);
		if (write(susfd, currline, ft_strlen(currline)) == -1)
			return (-2);
		free(currline);
		currline = get_next_line(hdocfd);
	}
	if (currline)
		free(currline);
	close(susfd);
	return (0);
}

char	*build_temp_hdoc_filename(t_data *data, int *i)
{
	char	*fname;
	char	*cmd_num;
	char	*hdoc_num;

	cmd_num = ft_itoa(i[0]);
	if (!cmd_num)
		return (NULL);
	hdoc_num = ft_itoa(i[1]);
	if (!hdoc_num)
		return (free(cmd_num), NULL);
	fname = ft_strjoin3("/tmp/.hdoc_temp_", cmd_num, "-");
	if (!fname)
		return (on_error_free(cmd_num, hdoc_num), NULL);
	fname = ft_strjoin3_free(fname, hdoc_num, "-");
	if (!fname)
		return (on_error_free(cmd_num, hdoc_num), NULL);
	fname = ft_strjoin_free(fname, data->hdoc_id);
	if (!fname)
		return (on_error_free(cmd_num, hdoc_num), NULL);
	free(cmd_num);
	free(hdoc_num);
	return (fname);
}

int	handle_hdoc_expansion(t_data *data)
{
	char	*filename;
	int		hdocfd;
	int		hdi[2];
	int		err;

	hdi[0] = data->curr_cmd;
	hdi[1] = data->hdoc_count;
	filename = build_temp_hdoc_filename(data, hdi);
	hdocfd = open(filename, O_RDONLY);
	if (hdocfd == -1)
		return (-2);
	if (data->hdcs[data->curr_cmd][data->hdoc_count].expand)
	{
		err = expand_hdoc_line(data, &filename, hdocfd);
		if (err)
			return (err);
		close(hdocfd);
		hdocfd = open(filename, O_RDONLY);
		if (hdocfd == -1)
			return (-2);
	}
	free(filename);
	return (hdocfd);
}
