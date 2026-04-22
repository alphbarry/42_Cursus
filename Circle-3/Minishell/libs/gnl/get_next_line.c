/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:19:08 by alpha             #+#    #+#             */
/*   Updated: 2025/01/24 21:04:30 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin_free(char *b1, char *b2)
{
	char	*t;

	t = gnl_strjoin(b1, b2);
	free(b1);
	return (t);
}

char	*get_remainder(char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	line = gnl_calloc(gnl_strlen(buf) - i + 1, 1);
	if (!line)
		return (NULL);
	i += 1;
	j = 0;
	while (buf[i])
		line[j++] = buf[i++];
	free(buf);
	return (line);
}

char	*extract_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[0])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = gnl_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_one(int fd, char *here)
{
	char	*buf_ro;
	int		r;

	if (!here)
		here = gnl_calloc(1, 1);
	if (!here)
		return (NULL);
	buf_ro = gnl_calloc(BUFFER_SIZE + 1, 1);
	if (!buf_ro)
		return (NULL);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf_ro, BUFFER_SIZE);
		if (r == -1)
			return (free(buf_ro), free(here), NULL);
		buf_ro[r] = '\0';
		here = gnl_strjoin_free(here, buf_ro);
		if (!here)
			return (free(buf_ro), NULL);
		if (gnl_strchr(here, '\n'))
			break ;
	}
	free(buf_ro);
	return (here);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	buf = read_one(fd, buf);
	if (!buf)
		return (NULL);
	ret = extract_line(buf);
	buf = get_remainder(buf);
	return (ret);
}
