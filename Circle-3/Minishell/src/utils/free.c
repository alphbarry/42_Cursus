/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:26:44 by alphbarr          #+#    #+#             */
/*   Updated: 2025/04/13 20:24:26 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_tokens(t_token *tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i].token)
	{
		free(tokens[i].token);
		if (tokens[i].literal)
			free(tokens[i].literal);
		i++;
	}
	free(tokens);
}

void	free_double(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

void	free_token_list(t_token **token_list)
{
	int	i;

	if (!token_list)
		return ;
	i = 0;
	while (token_list[i])
		free(token_list[i++]);
	free(token_list);
}

void	free_cmds(t_cmd *cmds)
{
	int	i;
	int	j;

	if (!cmds)
		return ;
	i = 0;
	while (cmds[i].cmd)
	{
		if (cmds[i].input_fd != -42 && close(cmds[i].input_fd) < 0)
			print_perror("Close infd data cleaner", -1);
		if (cmds[i].output_fd != -42 && close(cmds[i].output_fd) < 0)
			print_perror("Close outfd data cleaner", -1);
		j = 0;
		while (cmds[i].redir_info[j].filename)
			free(cmds[i].redir_info[j++].filename);
		free(cmds[i].redir_info);
		if (cmds[i].cmd)
			free_double(cmds[i++].cmd);
	}
	free(cmds);
}
