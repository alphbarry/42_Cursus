/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:19:29 by alpha             #+#    #+#             */
/*   Updated: 2025/01/03 13:27:15 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strjoin_free(char *b1, char *b2);
char	*gnl_strchr(const char *s, int c);
void	gnl_bzero(void *s, size_t n);
void	*gnl_calloc(size_t count, size_t size);
char	*get_next_line(int fd);

#endif
