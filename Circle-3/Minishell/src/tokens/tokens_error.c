/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:16:05 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 22:26:30 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	is_redir(t_token_type type)
{
	if (type == REDIR || type == HDOC)
		return (1);
	return (0);
}

static int	is_ops(t_token_type type)
{
	if (type == PIPE || type == AND || type == OR)
		return (1);
	return (0);
}

static int	is_invalid_token_pair(t_token *tokens, int i)
{
	if (((is_redir(tokens[i].type) || is_ops(tokens[i].type))
			&& is_redir(tokens[i - 1].type)) || (is_ops(tokens[i].type)
			&& is_ops(tokens[i - 1].type)))
		return (1);
	return (0);
}

int	check_token_syntax(t_data *data, t_token *tokens)
{
	int	i;

	if (!tokens || !tokens[0].token)
		return (0);
	if (is_ops(tokens[0].type))
	{
		data->sp_hdoc = 0;
		return (1);
	}
	i = 1;
	while (tokens[i].token)
	{
		if (is_invalid_token_pair(tokens, i))
		{
			data->sp_hdoc = i;
			return (1);
		}
		i++;
	}
	if (is_redir(tokens[i - 1].type) || is_ops(tokens[i - 1].type))
	{
		data->sp_hdoc = i - 1;
		return (1);
	}
	return (0);
}
