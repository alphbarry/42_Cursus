/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:31:27 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 19:12:56 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_env	*ft_lstlast_node(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
