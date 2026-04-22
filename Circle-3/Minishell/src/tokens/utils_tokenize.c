/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:57:35 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 22:26:35 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*token_break(char *s, char *sep)
{
	int	iq;

	iq = 0;
	while (*s)
	{
		if ((iq == 1 && *s == '\'') || (iq == 2 && *s == '"'))
			iq = 0;
		else if (!iq && (*s == '\'' || *s == '"'))
			iq = (*s == '"') + 1;
		if (!iq && (ft_strchr(sep, *s) || (*s == '&' && *(s + 1) == '&')))
			return (s);
		s++;
	}
	return (NULL);
}

t_token_type	get_token_type(char *t)
{
	if (!ft_strncmp(t, "|", 2))
		return (PIPE);
	if (!ft_strncmp(t, "<", 2) || !ft_strncmp(t, ">", 2) || !ft_strncmp(t, ">>",
			3))
		return (REDIR);
	if (!ft_strncmp(t, "<<", 3))
		return (HDOC);
	if (!ft_strncmp(t, "&&", 3))
		return (AND);
	if (!ft_strncmp(t, "||", 3))
		return (OR);
	return (TOKEN);
}
