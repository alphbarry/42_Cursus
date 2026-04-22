/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:55:24 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 20:11:47 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	assign_or_close_fds(t_data *data, int *i, int *fdio)
{
	if (data->cmds[i[0]].error_redir_pos < 0)
	{
		data->cmds[i[0]].input_fd = fdio[0];
		data->cmds[i[0]].output_fd = fdio[1];
	}
	else
	{
		if (fdio[0] != -42)
			close(fdio[0]);
		if (fdio[1] != -42)
			close(fdio[1]);
	}
}
