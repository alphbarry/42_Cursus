/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expand_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:05:06 by alphbarr          #+#    #+#             */
/*   Updated: 2025/04/13 22:23:55 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expand_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:05:06 by alphbarr          #+#    #+#             */
/*   Updated: 2025/04/10 18:50:54 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	expand_dollar_var(t_token *exp_t, t_data *data, t_token *curr_tok, int i)
{
	int	r;

	if (i > 0)
		r = expand_env_var(exp_t, data, curr_tok[i].token, curr_tok[i
				- 1].type);
	else
		r = expand_env_var(exp_t, data, curr_tok[i].token, TOKEN);
	if (curr_tok[i].type == TOKEN && i > 0 && r == 2 && data->error_tok_pos
		== -42)
	{
		data->error_tok_name = curr_tok[i].token;
		data->error_tok_pos = i;
		print_error(NULL, data->error_tok_name, "ambiguous redirect");
	}
	return (r);
}

int	check_no_lit_space(t_token *tok)
{
	int	i;

	i = 0;
	if (!tok->token[0])
		return (2);
	while (tok->token[i])
	{
		if (ft_strchr(" \t\f\v", tok->token[i]) && !tok->literal[i])
			return (2);
		i++;
	}
	return (0);
}

t_token_type	get_last_token_type(t_token *new_tokens)
{
	int				i;
	t_token_type	ret;

	if (!new_tokens)
		return (TOKEN);
	else
	{
		i = 0;
		ret = TOKEN;
		while (new_tokens[i].token)
		{
			ret = new_tokens[i].type;
			i++;
		}
	}
	return (ret);
}

int	init_expansion_data(int *i, t_token **new_tokens, t_data *data,
		t_token *exp_t)
{
	data->error_tok_pos = -42;
	data->error_tok_name = NULL;
	*i = -1;
	*new_tokens = NULL;
	exp_t->literal = NULL;
	return (0);
}
