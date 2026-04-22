/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:48:02 by alphbarr          #+#    #+#             */
/*   Updated: 2025/04/13 20:14:58 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	process_signals(int status)
{
	if (WIFEXITED(status))
		g_err = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			ft_putstr_fd("Quit: 3\n", 2);
		else if (WTERMSIG(status) == SIGINT)
			ft_putstr_fd("\n", 2);
		g_err = WTERMSIG(status) + 128;
	}
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_err = 1;
	}
}

void	handle_sigint_hdoc(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		ft_putendl_fd("", 1);
		g_err = 1;
		exit(1);
	}
}

void	reset_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
