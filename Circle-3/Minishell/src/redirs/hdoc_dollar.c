/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:41:20 by alpha             #+#    #+#             */
/*   Updated: 2025/04/13 22:25:26 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	expand_env_variable(char *nl, char *l, t_data *data, int *j)
{
	char	*env_v_name;
	char	*env_v_val;
	int		k;

	k = 0;
	env_v_name = ft_substr(l, 0, end_var(l) - l);
	env_v_val = get_env(data, env_v_name);
	if (!env_v_val)
		return (free(env_v_name), (*j)--, (void)0);
	while (env_v_val[k])
	{
		nl[*j] = env_v_val[k];
		k++;
		(*j)++;
	}
	(*j)--;
	free(env_v_name);
	free(env_v_val);
}

static int	count_env_var_expansion(t_data *data, char *t, int i)
{
	int		ret;
	char	*env_v_name;
	char	*env_v_val;

	if (t[i + 1] != '_' && !ft_isalpha(t[i + 1]) && t[i + 1] != '?')
		return (0);
	env_v_name = ft_substr(&t[i + 1], 0, end_var(&t[i + 1]) - &t[i + 1]);
	env_v_val = get_env(data, env_v_name);
	if (!env_v_val)
	{
		ret = ft_strlen(env_v_name);
		return (free(env_v_name), -ret);
	}
	ret = ft_strlen(env_v_val) - ft_strlen(env_v_name);
	free(env_v_val);
	free(env_v_name);
	return (ret);
}

static int	hdoc_expanded_length(t_data *data, char *t)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (t[i])
	{
		if (t[i] == '$' && (t[i + 1] == '_' || t[i + 1] == '?' || ft_isalpha(t[i
						+ 1])))
			ret += count_env_var_expansion(data, t, i) - 1;
		i++;
	}
	return (i + ret);
}

char	*expand_dollar_variables(char *l, t_data *data)
{
	int		i;
	int		j;
	char	*nl;

	i = 0;
	j = 0;
	nl = malloc(hdoc_expanded_length(data, l) + 1);
	if (!nl)
		return (NULL);
	while (l[i])
	{
		if (l[i] == '$' && (l[i + 1] == '_' || l[i + 1] == '?' || ft_isalpha(l[i
						+ 1])))
		{
			expand_env_variable(nl, &l[i + 1], data, &j);
			i += end_var(&l[i + 1]) - &l[i + 1];
		}
		else
			nl[j] = l[i];
		j++;
		i++;
	}
	nl[j] = 0;
	free(l);
	return (nl);
}
