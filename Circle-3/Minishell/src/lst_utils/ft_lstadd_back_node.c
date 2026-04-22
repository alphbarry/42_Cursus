/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:25:34 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 19:12:47 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_lstadd_back_node(t_env **lst, t_env *new_lst)
{
	t_env	*last;

	if (!(*lst))
	{
		*lst = new_lst;
		return ;
	}
	last = ft_lstlast_node(*lst);
	last->next = new_lst;
}
