/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:05:07 by alpha             #+#    #+#             */
/*   Updated: 2025/04/14 15:52:15 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	get_expansion_len(t_data *data, char *t, int i)
{
	int		ret;
	char	*env_name;
	char	*env_val;

	if (t[i] == '~')
		env_name = ft_strdup("HOME");
	else
	{
		if (t[i + 1] != '_' && !ft_isalpha(t[i + 1]) && t[i + 1] != '?')
			return (0);
		env_name = ft_substr(&t[i + 1], 0, end_var(&t[i + 1]) - &t[i + 1]);
	}
	env_val = get_env(data, env_name);
	if (!env_val)
	{
		ret = ft_strlen(env_name);
		return (free(env_name), -ret);
	}
	if (t[i] == '~')
		ret = ft_strlen(env_val);
	else
		ret = ft_strlen(env_val) - ft_strlen(env_name);
	free(env_val);
	free(env_name);
	return (ret);
}

static int	expansion_counter(t_data *data, char *t)
{
	int	ret;
	int	i;
	int	in_q;

	ret = 0;
	i = 0;
	in_q = 0;
	while (t[i])
	{
		update_quote_status(&in_q, t[i]);
		if ((in_q != 1 && t[i] == '$' && (t[i + 1] == '_' || t[i + 1] == '?'
					|| ft_isalpha(t[i + 1]))) || (t[i] == '~' && !i
				&& ft_strchr(" \t\f\v/", t[1])))
			ret += get_expansion_len(data, t, i) - 1;
		i++;
	}
	return (i + ret);
}

static int	init_expan_token(t_token *exp_t, t_data *data, char *c_t,
		t_token_type prev)
{
	int	exp_len;

	if (prev == HDOC)
		exp_len = ft_strlen(c_t);
	else
		exp_len = expansion_counter(data, c_t);
	exp_t->token = malloc(exp_len + 1);
	if (!exp_t->token)
		return (1);
	exp_t->literal = malloc(sizeof(int) * exp_len);
	if (!exp_t->literal)
		return (free(exp_t->token), exp_t->token = NULL, 1);
	return (0);
}

t_token	*token_expander(t_data *data, t_token *c_toks)
{
	int		i;
	t_token	*new_tokens;
	t_token	*local_n_t;
	t_token	exp_t;

	if (init_expansion_data(&i, &new_tokens, data, &exp_t))
		return (NULL);
	while (c_toks[++i].token)
	{
		if (init_expan_token(&exp_t, data, c_toks[i].token,
				get_last_token_type(new_tokens)))
			return (NULL);
		if (expand_dollar_var(&exp_t, data, c_toks, i) == 1)
			return (NULL);
		else if (expand_dollar_var(&exp_t, data, c_toks, i) == 2)
			new_tokens[tokenslen(new_tokens) - 1].type = REDIR_ERROR;
		local_n_t = split_expanded_token(&exp_t);
		if (!local_n_t)
			return (free_tokens(new_tokens), NULL);
		new_tokens = tokens_join_free(new_tokens, local_n_t);
		if (!new_tokens)
			return (NULL);
	}
	return (new_tokens);
}
