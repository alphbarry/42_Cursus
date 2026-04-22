/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:19:41 by alphbarr          #+#    #+#             */
/*   Updated: 2025/04/13 19:08:38 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*find_unquoted_sep(t_token *t, int k, char *sep)
{
	int	in_q;

	in_q = 0;
	while (t->token[k])
	{
		if (!t->literal[k])
		{
			if ((in_q == 1 && t->token[k] == '\'') || (in_q == 2
					&& t->token[k] == '"'))
				in_q = 0;
			else if (!in_q && (t->token[k] == '\'' || t->token[k] == '"'))
				in_q = (t->token[k] == '"') + 1;
		}
		if (!in_q && ft_strchr(sep, t->token[k]) && !t->literal[k])
			return (&(t->token[k]));
		k++;
	}
	return (NULL);
}

static int	allocate_new_token_memory(t_token *ret, int i, size_t wlen)
{
	ret[i].token = malloc(wlen + 1);
	if (!ret[i].token)
	{
		perror("malloc failed for token\n");
		return (1);
	}
	ret[i].literal = malloc(sizeof(int) * (wlen + 1));
	if (!ret[i].literal)
	{
		perror("malloc failed for literal\n");
		return (1);
	}
	return (0);
}

int	allocate_new_token(t_token *t, int *k, t_token *ret, int *i)
{
	size_t	wlen;
	char	*sep;

	sep = find_unquoted_sep(t, *k, " \t\f\v");
	if (sep)
		wlen = (size_t)(sep - &(t->token[*k]));
	else
		wlen = ft_strlen(&(t->token[*k]));
	ret[*i].type = t->type;
	if (allocate_new_token_memory(ret, *i, wlen) != 0)
	{
		free_tokens(ret);
		return (1);
	}
	ft_memcpy(ret[*i].literal, &t->literal[*k], wlen * sizeof(int));
	ret[*i].literal[wlen] = 0;
	fill_tokens_without_q(wlen, t, *k, ret + *i);
	(*i)++;
	*k += wlen;
	return (0);
}
