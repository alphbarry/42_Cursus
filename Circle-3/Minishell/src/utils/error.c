/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:27:50 by alphbarr          #+#    #+#             */
/*   Updated: 2025/04/13 20:23:26 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_error(char *cmd, char *var, char *error)
{
	if (cmd)
		ft_putstr_fd(cmd, 2);
	else
		ft_putstr_fd("minishell", 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(var, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
}

void	print_perror(char *msg, int error)
{
	perror(msg);
	if (error >= 0)
		exit(error);
}

void	open_error(char *filename)
{
	ft_putstr_fd("minishell: ", 2);
	perror(filename);
}

void	display_token_error(char *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putendl_fd("'", 2);
}
