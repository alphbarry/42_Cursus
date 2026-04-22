/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:30:00 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 18:50:29 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	count_env(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

char	**create_env(void)
{
	char	**new_env;
	char	*pwd;

	new_env = malloc(3 * sizeof(char *));
	if (!new_env)
		return (NULL);
	pwd = getcwd(0, 0);
	new_env[0] = ft_strjoin(ft_strdup("PWD="), ft_strdup(pwd));
	new_env[1] = ft_strdup("SHLVL=1");
	new_env[2] = ft_strdup("_=/usr/bin/env");
	new_env[3] = NULL;
	if (!new_env[0] || !new_env[1] || !new_env[2])
	{
		free(new_env[0]);
		free(new_env[1]);
		free(new_env[2]);
		free(new_env);
		return (NULL);
	}
	return (new_env);
}

char	**allocate_env_copy(char **env)
{
	int		env_count;
	char	**new_env;

	env_count = count_env(env);
	new_env = malloc((env_count + 1) * sizeof(char *));
	if (!new_env)
		return (NULL);
	return (new_env);
}

char	**free_env_on_error(char **env, int i)
{
	while (i > 0)
		free(env[--i]);
	free(env);
	return (NULL);
}

char	**copy_env(char **env)
{
	int		i;
	char	**new_env;

	if (!env || !*env)
		return (create_env());
	new_env = allocate_env_copy(env);
	if (!new_env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		if (!new_env[i])
			return (free_env_on_error(new_env, i));
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}
