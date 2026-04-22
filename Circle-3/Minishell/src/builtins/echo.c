/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:44:15 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 18:49:50 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	do_echo(t_token *tokens)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (!tokens)
		return (1);
	while (tokens[i].token && ft_strcmp(tokens[i].token, "-n") == 0)
	{
		n_flag = 1;
		i++;
	}
	while (tokens[i].token)
	{
		printf("%s", tokens[i].token);
		if (tokens[i + 1].token)
			printf(" ");
		i++;
	}
	if (!n_flag)
		printf("\n");
	return (0);
}

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ' || c == '\0');
}

int	is_char(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
