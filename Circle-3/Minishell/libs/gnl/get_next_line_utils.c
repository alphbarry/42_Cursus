/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:19:57 by alpha             #+#    #+#             */
/*   Updated: 2025/01/03 13:20:00 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_bzero(void *s, size_t n)
{
	unsigned char	*sclone;

	sclone = s;
	while (n)
	{
		*sclone++ = 0;
		n--;
	}
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = (void *)malloc(count * size);
	if (ret)
		gnl_bzero(ret, count * size);
	return (ret);
}

size_t	gnl_strlen(const char *s)
{
	size_t	cur;

	cur = 0;
	while (s[cur])
		cur++;
	return (cur);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char		*ret;
	char		*realret;

	ret = (char *)malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	realret = ret;
	while (*s1)
		*ret++ = *s1++;
	while (*s2)
		*ret++ = *s2++;
	*ret = 0;
	return (realret);
}

char	*gnl_strchr(const char *s, int c)
{
	char	*retme;

	retme = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			retme = (char *)s;
			break ;
		}
		s++;
	}
	if ((unsigned char)c == 0 && *s == 0)
		retme = (char *)s;
	return (retme);
}
