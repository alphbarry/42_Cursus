/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hdocs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:48:15 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 22:24:41 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	count_hdoc_chars(char *s)
{
	int	i;
	int	c;
	int	in_q;

	i = -1;
	c = 0;
	in_q = 0;
	while (s[++i])
	{
		update_quote_status(&in_q, s[i]);
		if (!((in_q == 1 && s[i] == '\'') || (in_q == 2 && s[i] == '"')
				|| (!in_q && ft_strchr("'\"", s[i]))))
			c++;
	}
	return (c);
}

static int	parse_hdoc_token(t_data *data, char **s, t_token t)
{
	int	i;
	int	j;
	int	in_q;

	(*s) = malloc(count_hdoc_chars(t.token) + 1);
	if (!(*s))
		return (1);
	i = 0;
	j = 0;
	in_q = 0;
	while (t.token[i] && i != data->sp_hdoc)
	{
		update_quote_status(&in_q, t.token[i]);
		if (!((in_q == 1 && t.token[i] == '\'') || (in_q == 2
					&& t.token[i] == '"') || (!in_q && ft_strchr("'\"",
						t.token[i]))))
			(*s)[j++] = t.token[i];
		i++;
	}
	(*s)[j] = 0;
	return (0);
}

static int	init_hdoc_data(t_data *d)
{
	int	j;
	int	i;
	int	hd_c;

	i = 0;
	j = 0;
	hd_c = 0;
	while (d->tokens[i].token && i != d->sp_hdoc)
	{
		if (d->tokens[i].type == HDOC)
		{
			if (parse_hdoc_token(d, &(d->hdcs[j][hd_c].str), d->tokens[i + 1]))
				return (1);
			d->hdcs[j][hd_c].curr = check_latest_hdoc(&d->tokens[i + 1]);
			d->hdcs[j][hd_c++].expand = token_break(d->tokens[i + 1].token,
					"'\"") == NULL;
		}
		if (d->tokens[i].type == OR || d->tokens[i].type == AND)
			d->hdcs[j++][hd_c].str = NULL;
		hd_c -= hd_c * (d->tokens[i].type == OR || d->tokens[i].type == AND);
		i++;
	}
	d->hdcs[j][hd_c].str = NULL;
	return (0);
}

t_error	init_hdocs(t_data *data)
{
	int	i;
	int	cmd_c;

	i = 0;
	cmd_c = 0;
	while (data->tokens[i].token && i != data->sp_hdoc)
	{
		cmd_c += data->tokens[i].type == OR || data->tokens[i].type == AND;
		i++;
	}
	cmd_c++;
	data->hdcs = malloc(sizeof(t_hdoc) * (cmd_c + 1));
	if (!data->hdcs || allocate_hdocs(data) || init_hdoc_data(data))
	{
		free_hdocs(data->hdcs);
		return (MALLOC_ERR);
	}
	data->hdcs[cmd_c] = NULL;
	return (NULL_ERR);
}
