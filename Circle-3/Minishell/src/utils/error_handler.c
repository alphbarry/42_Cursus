/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:02:08 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 22:31:32 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	process_exit_handler(t_data *data, int exit_code)
{
	clear_shell_status(data);
	free(data->hdoc_id);
	exit(exit_code);
}

static void	print_critical_error(t_data *data, t_error error)
{
	if (data->aux_error == LEFT_Q_ERR)
		ft_putstr_fd("minishell: un-closed quotations left\n", 2);
	else if (data->aux_error == MALLOC_ERR || error == MALLOC_ERR)
		print_perror("minishell: malloc error", -1);
	else if (data->aux_error == PIPE_ERR || error == PIPE_ERR)
		print_perror("minishell: pipe error", -1);
	else if (data->aux_error == FORK_ERR || error == FORK_ERR)
		print_perror("minishell: fork error", -1);
	else if (data->aux_error == DUP2_ERR || error == DUP2_ERR)
		print_perror("minishell: dup2 error", -1);
}

static int	is_critical_error(t_data *data, t_error error)
{
	return (data->aux_error == LEFT_Q_ERR || data->aux_error == MALLOC_ERR
		|| data->aux_error == PIPE_ERR || data->aux_error == FORK_ERR
		|| data->aux_error == DUP2_ERR || error == MALLOC_ERR
		|| error == PIPE_ERR || error == FORK_ERR || error == DUP2_ERR);
}

static void	handle_syntax_error(t_data *data)
{
	if (data->tokens[data->sp_hdoc].token)
		display_token_error(data->tokens[data->sp_hdoc].token);
	else
		ft_putstr_fd("minishell: syntax error near unexpected"
			"token `newline'\n", 2);
}

void	error_handler(t_data *data, t_error error)
{
	if (error == SYNTAX_ERR)
		handle_syntax_error(data);
	else if (error == HDOC_LIMIT_ERR)
	{
		ft_putstr_fd("minishell: maximum here-document count exceeded\n", 2);
		process_exit_handler(data, 2);
	}
	else if (is_critical_error(data, error))
		print_critical_error(data, error);
	else
		return ;
	g_err = 1;
}
