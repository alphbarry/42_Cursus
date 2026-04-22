/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:10:15 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 22:28:12 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

static int	check_operator(char *s, int *i)
{
	char	tmp;

	if (!s[*i + 1])
		return (0);
	if (s[*i] == '&')
	{
		(*i)++;
		if (s[*i] == '&')
		{
			(*i)++;
			return (1);
		}
		(*i)--;
		return (0);
	}
	tmp = s[*i];
	(*i)++;
	if (s[*i] == tmp)
		(*i)++;
	return (1);
}

static int	additional_token_check(char *s, char *sep, int *iq, int i)
{
	int	count;

	count = 0;
	if ((!*iq && !ft_strchr(sep, s[i]) && s[i] != '\'' && s[i] != '"')
		|| (*iq == 1 && s[i] == '\'') || (*iq == 2 && s[i] == '"'))
	{
		if (i >= 2)
		{
			if (ft_strchr(sep, s[i - 1]) || (ft_strchr("|<>", s[i - 1]) || (s[i
							- 2] == '&' && s[i - 1] == '&')))
				count++;
		}
		else
		{
			if (ft_strchr(sep, s[i - 1]) || ft_strchr("|<>", s[i - 1]))
				count++;
		}
	}
	return (count);
}

static int	tokenize_count(char *s, char *sep, int *iq, int i)
{
	int	count;

	count = 0;
	while (s[i])
	{
		if ((*iq == 1 && s[i] == '\'') || (*iq == 2 && s[i] == '"'))
			*iq = 0;
		else if (!*iq && (s[i] == '\'' || s[i] == '"'))
			*iq = (s[i] == '"') + 1;
		if (!*iq && (ft_strchr("|<>", s[i]) || (s[i] == '&' && s[i + 1] == '&'))
			&& check_operator(s, &i))
			count++;
		else
		{
			count += additional_token_check(s, sep, iq, i);
			i++;
		}
	}
	return (count);
}

int	count_tokens(char *s, char *sep)
{
	int	i;
	int	iq;
	int	count;

	i = 0;
	iq = 0;
	count = 0;
	if (!s[i])
		return (0);
	if (s[i] == '\'' || s[i] == '"')
	{
		i++;
		count++;
		iq = 1 + (s[i - 1] == '"');
	}
	else if (ft_strchr("|&<>", s[i]) && check_operator(s, &i))
		count++;
	else if (!ft_strchr(sep, s[i++]))
		count++;
	count += tokenize_count(s, sep, &iq, i);
	if (!iq)
		return (count);
	return (-2);
}
