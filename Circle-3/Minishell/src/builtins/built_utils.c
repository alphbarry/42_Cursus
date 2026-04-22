/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:57:08 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 18:46:32 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	print_env_list(t_env *env_list)
{
	t_env	*current;

	current = env_list;
	if (!current)
	{
		printf("La lista de variables de entorno está vacía.\n");
		return (1);
	}
	while (current)
	{
		if (ft_strcmp(current->env_value, "") != 0)
			printf("%s=%s\n", current->env_key, current->env_value);
		current = current->next;
	}
	return (0);
}

void	print_export(t_env *env_list)
{
	t_env	*current;

	current = env_list;
	if (!current)
	{
		printf("La lista de variables de entorno está vacía.\n");
		return ;
	}
	while (current)
	{
		if (ft_strcmp(current->env_value, "") == 0)
			printf("declare -x %s\n", current->env_key);
		else
			printf("declare -x %s=\"%s\"\n", current->env_key,
				current->env_value);
		current = current->next;
	}
}

int	count_pointer(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
		i++;
	return (i);
}

char	*get_var(const char *env_var)
{
	int	len;

	len = 0;
	while (env_var[len] && env_var[len] != '=' && env_var[len] != '+')
		len++;
	return (ft_substr(env_var, 0, len));
}

char	*get_value(const char *env_val)
{
	int	start;

	start = 0;
	while (env_val[start] && env_val[start] != '=')
		start++;
	if (env_val[start] == '=')
		start++;
	return (ft_substr(env_val, start, ft_strlen(env_val) - start));
}
