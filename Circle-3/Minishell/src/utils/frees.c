/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:32:02 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 22:33:02 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (!str)
		return (free(s1), NULL);
	free(s1);
	return (str);
}

char	*ft_strjoin3_free(char *s1, char *s2, char *s3)
{
	char	*str;

	str = ft_strjoin3(s1, s2, s3);
	if (!str)
		return (free(s1), NULL);
	free(s1);
	return (str);
}

void	on_error_free(char *cmd_num, char *hdoc_num)
{
	if (cmd_num)
		free(cmd_num);
	if (hdoc_num)
		free(hdoc_num);
}

void	free_hdocs(t_hdoc **hdocs)
{
	int	i;
	int	j;

	if (!hdocs)
		return ;
	i = 0;
	while (hdocs[i])
	{
		j = 0;
		while (hdocs[i][j].str)
		{
			free(hdocs[i][j].str);
			hdocs[i][j].str = NULL;
			j++;
		}
		free(hdocs[i]);
		hdocs[i] = NULL;
		i++;
	}
	free(hdocs);
	hdocs = NULL;
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		if (env->env_key)
			free(env->env_key);
		if (env->env_value)
			free(env->env_value);
		free(env);
		env = tmp;
	}
}
