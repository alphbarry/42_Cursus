/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:55:21 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 22:27:41 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	extract_tokens(char **str, t_token *tokens, int *i)
{
	size_t	wlen;

	if (ft_strchr("<>|", **str) || (**str == '&' && *(*str + 1) == '&'))
	{
		if (**str != *(*str + 1))
			wlen = 1;
		else
			wlen = 2;
	}
	else
	{
		if (!token_break(*str, " \t\f\v<>|"))
			wlen = ft_strlen(*str);
		else
			wlen = token_break(*str, " \t\f\v<>|") - *str;
	}
	tokens[*i].token = ft_substr(*str, 0, wlen);
	if (!tokens[*i].token)
		return (1);
	(*i)++;
	*str += wlen;
	return (0);
}

static void	init_tokens(t_token *tokens, int len)
{
	int	i;

	i = 0;
	ft_memset(tokens, 0, sizeof(t_token) * (len + 1));
	while (i < len)
	{
		tokens[i].type = TOKEN;
		tokens[i].token = NULL;
		tokens[i].literal = NULL;
		i++;
	}
	tokens[i].token = NULL;
}

static t_token	*tokenize_input(t_data *data, char *str)
{
	t_token	*tokens;
	int		len;
	int		i;

	len = 0;
	data->tokens_count = count_tokens(str, " \t\f\v");
	i = 0;
	len = data->tokens_count;
	if (len == -2)
		return (data->aux_error = LEFT_Q_ERR, NULL);
	tokens = malloc(sizeof(t_token) * (len + 1));
	if (!tokens)
		return (NULL);
	init_tokens(tokens, len);
	while (*str)
	{
		while (ft_strchr(" \t\f\v", *str) && *str)
			str++;
		if (*str)
		{
			if (extract_tokens(&str, tokens, &i))
				return (NULL);
		}
	}
	return (tokens);
}

static int	get_hdoc_count(t_token *t)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (t[i].token)
	{
		c += (t[i].type == HDOC);
		i++;
	}
	return (c);
}

t_error	tokenize(char *s, t_data *data)
{
	int	i;

	data->tokens = tokenize_input(data, s);
	if (!data->tokens)
		return (MALLOC_ERR);
	i = -1;
	while (data->tokens[++i].token)
		data->tokens[i].type = get_token_type(data->tokens[i].token);
	data->total_hdocs = get_hdoc_count(data->tokens);
	if (data->total_hdocs > 16)
		return (HDOC_LIMIT_ERR);
	check_token_syntax(data, data->tokens);
	return (NULL_ERR);
}
