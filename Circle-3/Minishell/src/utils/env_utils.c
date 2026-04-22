/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:55:21 by alpha             #+#    #+#             */
/*   Updated: 2025/04/14 16:00:08 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_env	*allocate_env_node(char *key, char *value)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->env_key = ft_strdup(key);
	new_node->env_value = ft_strdup(value);
	new_node->export_flag = 1;
	new_node->join_flag = 1;
	new_node->next = NULL;
	free(key);
	free(value);
	return (new_node);
}

static void	free_env_node(t_env *node)
{
	if (node)
	{
		free(node->env_key);
		free(node->env_value);
		free(node);
	}
}

t_env	*allocate_env_struct(char **envp)
{
	t_env	*env;
	t_env	*new_node;
	t_env	*last;
	int		i;
	int		j;
	char	*key;
	char	*value;

	env = NULL;
	last = NULL;
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=')
			j++;
		key = ft_substr(envp[i], 0, j);
		value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]) - j - 1);
		if (!key || !value)
			return (free_env_node(env), NULL);
		new_node = allocate_env_node(key, value);
		if (!new_node)
			return (free_env_node(env), NULL);
		if (!env)
			env = new_node;
		else
			last->next = new_node;
		last = new_node;
		i++;
	}
	return (env);
}
