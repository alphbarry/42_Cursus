/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:09:54 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 19:12:36 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_node(t_env *node)
{
	if (node)
	{
		free(node->env_key);
		free(node->env_value);
		free(node);
	}
}

void	free_env_list(t_env *env)
{
	t_env	*current;
	t_env	*next;

	current = env;
	while (current)
	{
		next = current->next;
		free_node(current);
		current = next;
	}
}
