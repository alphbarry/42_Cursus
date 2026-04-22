/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_window_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:23:13 by alphbarr          #+#    #+#             */
/*   Updated: 2024/07/01 19:23:33 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_win_size(int key, t_fdf **matrix)
{
	if ((key == 0 && (*matrix)->win_y <= 500) || (key == 6
			&& (*matrix)->win_x <= 500))
		return (1);
	if ((key == 1 && (*matrix)->win_y > 1000) || (key == 7
			&& (*matrix)->win_x > 2000))
		return (1);
	return (0);
}

void	full_screen(t_fdf **matrix)
{
	static int	old_x;
	static int	old_y;

	if ((*matrix)->win_x != 2560)
	{
		old_x = (*matrix)->win_x;
		old_y = (*matrix)->win_y;
	}
	if ((*matrix)->win_x == 2560)
	{
		(*matrix)->win_x = old_x;
		(*matrix)->win_y = old_y;
	}
	else
	{
		(*matrix)->win_x = 2560;
		(*matrix)->win_y = 1400;
	}
}

void	change_window_size(int key, t_fdf **matrix)
{
	if (check_win_size(key, matrix))
		return ;
	if (key == 6)
		(*matrix)->win_x -= 100;
	if (key == 7)
		(*matrix)->win_x += 100;
	if (key == 0)
		(*matrix)->win_y -= 100;
	if (key == 1)
		(*matrix)->win_y += 100;
	if (key == 3)
		full_screen(matrix);
}

void	new_window(int key, t_fdf **matrix)
{
	change_window_size(key, matrix);
	mlx_destroy_image((*matrix)->mlx_ptr, (*matrix)->img_ptr);
	mlx_destroy_window((*matrix)->mlx_ptr, (*matrix)->win_ptr);
	(*matrix)->mlx_ptr = mlx_init();
	(*matrix)->win_ptr = mlx_new_window((*matrix)->mlx_ptr, (*matrix)->win_x,
			(*matrix)->win_y, "FDF");
	(*matrix)->shift_x = (*matrix)->win_x / 3;
	(*matrix)->shift_y = (*matrix)->win_y / 3;
	draw_matrix(matrix, (*matrix)->rows, (*matrix)->cols);
	mlx_key_hook((*matrix)->win_ptr, deal_key, matrix);
	mlx_loop((*matrix)->mlx_ptr);
}
