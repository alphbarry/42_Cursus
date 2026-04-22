/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:21:32 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 22:18:48 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	detect_append_mode(char *token, char **equal_sign)
{
	char	*plus_sign;
	int		plus_count;

	plus_count = 0;
	if (!*equal_sign || *equal_sign == token)
		return (1);
	plus_sign = *equal_sign - 1;
	while (plus_sign >= token && *plus_sign == '+')
	{
		plus_count++;
		plus_sign--;
	}
	if (plus_count == 0)
		return (0);
	if (plus_count != 1)
		return (-1);
	*(*equal_sign - 1) = '\0';
	return (1);
}

void	handle_export_no_value(t_data *data, char *token)
{
	char	*key;

	key = ft_strdup(token);
	if (!key)
		return ;
	if (update_env(&data->env, key, ""))
		free(key);
}

void	handle_export_with_value(t_data *data, char *token, char *equal_sign,
		int append_mode)
{
	char	*key;
	char	*val;
	t_env	*env;

	key = ft_substr(token, 0, equal_sign - token);
	val = ft_strdup(equal_sign + 1);
	env = data->env;
	if (!key || !val)
		return (free(key), free(val));
	while (append_mode && env)
	{
		if (ft_strcmp(env->env_key, key) == 0)
		{
			env->join_flag = 1;
			break ;
		}
		env = env->next;
	}
	if (update_env(&data->env, key, val))
		return (free(key), free(val));
}

static short	is_valid(int append_mode, t_token *tokens, int i)
{
	short	status;

	status = 1;
	if (append_mode < 0 || (!ft_isalpha(tokens[i].token[0])
			&& tokens[i].token[0] != '_'))
		status = 0;
	return (status);
}

int	ft_export(t_token *tokens, t_data *data, int status)
{
	int		i;
	char	*equal_sign;
	int		append_mode;

	if (!tokens || !tokens[1].token)
		return (print_export(data->env), 0);
	i = 1;
	while (tokens[i].token)
	{
		equal_sign = ft_strchr(tokens[i].token, '=');
		append_mode = detect_append_mode(tokens[i].token, &equal_sign);
		if (!is_valid(append_mode, tokens, i))
		{
			(print_error("minishell: export: `", tokens[i].token,
					"': not a valid identifier"));
			status = 1;
		}
		if (is_valid(append_mode, tokens, i) && !equal_sign)
			handle_export_no_value(data, tokens[i].token);
		else if (is_valid(append_mode, tokens, i) && equal_sign)
			handle_export_with_value(data, tokens[i].token, equal_sign,
				append_mode);
		i++;
	}
	return (status);
}
