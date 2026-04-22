/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:45:41 by alphbarr          #+#    #+#             */
/*   Updated: 2025/04/13 19:07:23 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	count_tokens_expand(t_token t, char *sep, int *i_q, int i)
{
	int	count;

	i++;
	count = 0;
	while (t.token[i])
	{
		if (!t.literal[i])
		{
			if ((*i_q == 1 && t.token[i] == '\'') || (*i_q == 2
					&& t.token[i] == '"'))
				*i_q = 0;
			else if (!*i_q && (t.token[i] == '\'' || t.token[i] == '"'))
				*i_q = (t.token[i] == '"') + 1;
		}
		if (!t.literal[i - 1] && ft_strchr(sep, t.token[i - 1]) && (t.literal[i]
				|| (*i_q == 1 && t.token[i] == '\'') || (*i_q == 2
					&& t.token[i] == '"')))
			count++;
		i++;
	}
	return (count);
}

static int	count_split_tokens(t_token t)
{
	int	i;
	int	i_q;
	int	count;

	i = 0;
	i_q = 0;
	count = 0;
	if (!t.token[i])
		return (0);
	if ((t.token[i] == '\'' || t.token[i] == '"') && !t.literal[i])
	{
		count++;
		i_q = 1 + (t.token[i] == '"');
	}
	else if (t.literal[i])
		count++;
	count += count_tokens_expand(t, " \t\f\v", &i_q, i);
	if (!i_q)
		return (count);
	return (-2);
}

void	fill_tokens_without_q(size_t wlen, t_token *t, int j, t_token *ret_one)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (i < wlen)
	{
		if (ft_strchr("\"'", t->token[j + i]) && !t->literal[j + i])
		{
			i++;
			continue ;
		}
		ret_one->token[y] = t->token[j + i];
		i++;
		y++;
	}
	ret_one->token[y] = 0;
}

t_token	*split_expanded_token(t_token *t)
{
	t_token	*ret;
	int		i;
	int		k;

	i = 0;
	k = 0;
	ret = malloc(sizeof(t_token) * (count_split_tokens(*t) + 1));
	if (!ret)
		return (NULL);
	while (t->token[k])
	{
		while (ft_strchr(" \t\f\v", t->token[k]) && t->token[k]
			&& !t->literal[k])
			k++;
		if (allocate_new_token(t, &k, ret, &i))
			return (NULL);
	}
	ret[i].token = NULL;
	free(t->token);
	if (t->literal)
		free(t->literal);
	t->literal = NULL;
	return (ret);
}
