/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:55:59 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 18:51:11 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exit_handler(t_data *data, int exit_code)
{
	rl_clear_history();
	clear_shell_status(data);
	free(data->hdoc_id);
	exit(exit_code);
}

void	exit_handler_null(t_data *data)
{
	rl_clear_history();
	clear_shell_status(data);
	free(data->hdoc_id);
	exit(g_err);
}

static int	numeric_str(char *s)
{
	int	i;

	if (!(ft_isdigit(s[0]) || s[0] == '-' || s[0] == '+'))
		return (1);
	i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

int	do_exit(t_data *data, char **args)
{
	if (!args || !args[0])
	{
		ft_putendl_fd("exit", 1);
		exit_handler_null(data);
	}
	if (numeric_str(args[0]))
	{
		ft_putendl_fd("exit", 1);
		print_error("minishell: exit", args[0], "numeric argument required");
		exit_handler(data, 255);
	}
	else if (ft_strslen(args) > 1)
		return (print_error(NULL, "exit", "too many arguments"), 1);
	else
	{
		ft_putendl_fd("exit", 1);
		exit_handler(data, ft_atoi(args[0]));
	}
	return (0);
}
