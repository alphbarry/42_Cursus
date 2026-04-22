/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:12:37 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/04/13 18:52:24 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	get_pwd(void)
{
	char	*pwd;

	pwd = getcwd(0, 0);
	if (pwd != NULL)
	{
		printf("%s\n", pwd);
		free(pwd);
	}
	else
	{
		printf("PWD not working");
		return (1);
	}
	return (0);
}
