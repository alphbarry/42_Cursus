/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:25:58 by alphbarr          #+#    #+#             */
/*   Updated: 2024/07/02 14:04:58 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	default angle: 0.523599
**	make the figure 3d (isometric stile)
*/

#include "../includes/fdf.h"

void	isometric(t_fdf *fdf, double angle)
{
	fdf->x = (fdf->x - fdf->y) * cos(angle);
	fdf->y = (fdf->x + fdf->y) * sin(angle) - fdf->z;
}

void	check_file_status(int fd)
{
	struct stat	file_stat;

	if (fstat(fd, &file_stat) < 0)
	{
		close(fd);
		ft_error("could not get file status");
	}
	if (S_ISDIR(file_stat.st_mode))
	{
		close(fd);
		ft_error("attempted to read a directory");
	}
}

int	extension_fdf(char *filename)
{
	char	*d;

	d = ft_strrchr(filename, '.');
	if (!d || d == filename)
		return (0);
	if (ft_strcmp(d, ".fdf") == 0)
		return (1);
	else
		return (0);
}
