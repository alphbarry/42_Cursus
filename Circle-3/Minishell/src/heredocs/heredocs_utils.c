/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:42:54 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 19:12:10 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	simulate_hdoc(char *eof)
{
	int		eoflen;
	char	*hline;

	eoflen = ft_strlen(eof);
	hline = NULL;
	while (1)
	{
		if (hline && !ft_strncmp(hline, eof, eoflen + 1) && hline[eoflen])
			break ;
		if (hline)
			free(hline);
		hline = readline("> ");
		if (!hline)
		{
			free(hline);
			return (0);
		}
	}
	if (hline)
		free(hline);
	return (0);
}
