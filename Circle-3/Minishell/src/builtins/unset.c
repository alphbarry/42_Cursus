/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:57:58 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 18:52:53 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	update_env_links(t_env **new_env, t_env *prev, t_env *current)
{
	if (prev)
		prev->next = current->next;
	else
		*new_env = current->next;
	free(current->env_key);
	free(current->env_value);
	free(current);
}

static void	remove_env_node(t_env **new_env, const char *token)
{
	t_env	*current;
	t_env	*prev;

	current = *new_env;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->env_key, token) == 0)
		{
			update_env_links(new_env, prev, current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

static void	delete_node(t_env **new_env, const char *token)
{
	if (!new_env || !*new_env || !token)
		return ;
	remove_env_node(new_env, token);
}

int	ft_unset(t_token *tokens, t_data *data)
{
	int	i;

	i = 1;
	if (!tokens || !tokens[1].token)
		return (0);
	while (tokens[i].token)
	{
		if (!tokens[i].token || ft_strlen(tokens[i].token) == 0)
			return (1);
		delete_node(&data->env, tokens[i].token);
		i++;
	}
	return (0);
}
