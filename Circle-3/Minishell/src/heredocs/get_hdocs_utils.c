/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hdocs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:24:28 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 19:11:32 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_latest_hdoc(t_token *t)
{
	int	i;

	i = 0;
	while (t[i].token)
	{
		if (t[i].type == PIPE || t[i].type == OR || t[i].type == AND)
			return (1);
		else if (t[i].type == HDOC)
			return (0);
		i++;
	}
	return (1);
}

static int	allocate_hdoc_group(t_data *data, int *j, int heredocs_c)
{
	data->hdcs[*j] = malloc(sizeof(t_hdoc) * (heredocs_c + 1));
	if (!data->hdcs[*j])
	{
		while ((*j)-- > 0)
			free(data->hdcs[*j]);
		free(data->hdcs);
		return (1);
	}
	data->hdcs[*j][heredocs_c].str = NULL;
	(*j)++;
	return (0);
}

int	allocate_hdocs(t_data *data)
{
	int	i;
	int	j;
	int	heredocs_c;

	i = 0;
	j = 0;
	heredocs_c = 0;
	while (data->tokens[i].token && i != data->sp_hdoc)
	{
		if (data->tokens[i].type == HDOC)
			heredocs_c++;
		if (data->tokens[i].type == OR || data->tokens[i].type == AND)
		{
			if (allocate_hdoc_group(data, &j, heredocs_c))
				return (1);
			heredocs_c = 0;
		}
		i++;
	}
	return (allocate_hdoc_group(data, &j, heredocs_c));
}
