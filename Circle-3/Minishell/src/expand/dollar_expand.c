/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:12:49 by alphbarr          #+#    #+#             */
/*   Updated: 2025/04/14 15:49:29 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	fill_env_value(t_token *tok, char *t, t_data *data, int *j)
{
	char	*env_name;
	char	*env_val;
	int		k;

	k = 0;
	if (*(t - 1) == '~')
		env_name = ft_strdup("HOME");
	else
		env_name = ft_substr(t, 0, end_var(t) - t);
	if (!env_name)
		return (-1);
	env_val = get_env(data, env_name);
	if (!env_val)
		return (free(env_name), (*j)--, 0);
	while (env_val[k])
	{
		tok->token[*j] = env_val[k];
		k++;
		(*j)++;
	}
	tok->token[*j] = '\0';
	(*j)--;
	free(env_name);
	free(env_val);
	return (k);
}

void	update_quote_status(int *i_q, char c)
{
	if ((*i_q == 1 && c == '\'') || (*i_q == 2 && c == '"'))
		*i_q = 0;
	else if (!*i_q && (c == '\'' || c == '"'))
		*i_q = (c == '"') + 1;
}

static int	fill_literal_exp(int k, t_token *tok, int i_q, int *j)
{
	if (k < 0)
		return (1);
	while (k-- > 0)
	{
		tok->literal[*j - k] = i_q || !ft_strchr(" \t\f\v", tok->token[*j - k]);
	}
	return (0);
}

static char	set_literal_flag(int i_q, char c, t_token *tok, int j)
{
	if ((i_q == 1 && c == '\'') || (i_q == 2 && c == '"') || (!i_q
			&& ft_strchr(" \t\f\v'\"", c)))
		tok->literal[j] = 0;
	else if (c)
		tok->literal[j] = 1;
	return (c);
}

int	expand_env_var(t_token *tok, t_data *data, char *t, t_token_type prev)
{
	int	i;
	int	j;
	int	i_q;

	i = -1;
	j = 0;
	i_q = 0;
	tok->type = get_token_type(t);
	while (t[++i])
	{
		update_quote_status(&i_q, t[i]);
		if (((i_q != 1 && t[i] == '$' && (t[i + 1] == '_' || t[i + 1] == '?'
						|| ft_isalpha(t[i + 1]))) || (t[i] == '~' && !i
					&& ft_strchr(" \t\f\v/", t[1]))) && prev != HDOC)
		{
			if (fill_literal_exp(fill_env_value(tok, &t[i + 1], data, &j), tok,
					i_q, &j))
				return (1);
			i += end_var(&t[i + 1]) - &t[i + 1];
		}
		else
			tok->token[j] = set_literal_flag(i_q, t[i], tok, j);
		j++;
	}
	return (tok->token[i] = 0, (prev == REDIR) * check_no_lit_space(tok));
}
