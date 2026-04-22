/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:17:37 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 22:43:01 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	update_existing_env(t_env *node, const char *value)
{
	char	*new_value;

	if (node->join_flag)
	{
		new_value = ft_strjoin(node->env_value, value);
		if (!new_value)
			return (1);
		free(node->env_value);
		node->env_value = new_value;
	}
	else
	{
		free(node->env_value);
		node->env_value = ft_strdup(value);
	}
	node->join_flag = 0;
	node->export_flag = 1;
	return (!node->env_value);
}

static int	add_new_env(t_env **env, const char *key, const char *value)
{
	t_env	*new_node;

	new_node = ft_calloc(1, sizeof(t_env));
	if (!new_node)
		return (perror("malloc"), 1);
	new_node->env_key = ft_strdup(key);
	new_node->env_value = ft_strdup(value);
	if (!new_node->env_key || !new_node->env_value)
		return (free(new_node->env_key), free(new_node->env_value),
			free(new_node), 1);
	new_node->export_flag = (*value != '\0');
	new_node->join_flag = 0;
	new_node->next = *env;
	*env = new_node;
	return (0);
}

int	update_env(t_env **env, const char *key, const char *value)
{
	t_env	*node;

	node = *env;
	while (node)
	{
		if (ft_strcmp(node->env_key, key) == 0)
			return (update_existing_env(node, value));
		node = node->next;
	}
	return (add_new_env(env, key, value));
}

static char	*get_cd_path(t_token *tokens, t_data *data)
{
	t_env	*home_node;

	if (!tokens || !tokens[1].token)
	{
		home_node = data->env;
		while (home_node && ft_strcmp(home_node->env_key, "HOME") != 0)
			home_node = home_node->next;
		if (!home_node || !home_node->env_value)
			return (printf("cd: HOME not set\n"), NULL);
		return (ft_strdup(home_node->env_value));
	}
	return (ft_strdup(tokens[1].token));
}

int	ft_cd(t_token *tokens, t_data *data)
{
	char	*old_pwd;
	char	*path;
	char	*new_pwd;

	old_pwd = getcwd(NULL, 0);
	path = get_cd_path(tokens, data);
	if (!path)
		return (free(old_pwd), 1);
	if (chdir(path) != 0)
		return (perror("cd"), free(old_pwd), free(path), 1);
	new_pwd = getcwd(NULL, 0);
	update_env(&data->env, "OLDPWD", old_pwd);
	update_env(&data->env, "PWD", new_pwd);
	free(old_pwd);
	free(new_pwd);
	free(path);
	return (0);
}
