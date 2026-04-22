/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:17:31 by alphbarr          #+#    #+#             */
/*   Updated: 2024/06/26 18:32:12 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

void	ft_error(char *error)
{
	ft_printf("%s\n", error);
	exit(1);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	mod(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

void	free_matrix(t_fdf **matrix, int rows)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
