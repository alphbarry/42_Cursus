/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:40:36 by alphbarr          #+#    #+#             */
/*   Updated: 2025/04/13 22:33:32 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_env(t_data *data, char *key)
{
	int		i;
	t_env	*current;

	current = data->env;
	i = 0;
	if (key[0] == '?')
		return (ft_itoa(g_err));
	while (current)
	{
		if (!ft_strncmp(key, current->env_key, ft_strlen(key) + 1))
			break ;
		i++;
		current = current->next;
	}
	if (current)
		return (ft_strdup(current->env_value));
	return (NULL);
}

static void	fill_execv_env(char **env, t_env *env_list)
{
	int	i;

	i = 0;
	while (env_list)
	{
		if (env_list->env_value)
			env[i] = ft_strjoin3(env_list->env_key, "=", env_list->env_value);
		else
			env[i] = ft_strdup(env_list->env_key);
		if (!env[i])
			return (free_double(env));
		i++;
		env_list = env_list->next;
	}
	env[i] = NULL;
}

char	**conv_to_execv_format(t_data *data)
{
	int		len;
	char	**env;
	t_env	*current;

	len = 0;
	current = data->env;
	while (current)
	{
		len++;
		current = current->next;
	}
	env = malloc((len + 1) * sizeof(char *));
	if (!env)
		return (NULL);
	fill_execv_env(env, data->env);
	return (env);
}
