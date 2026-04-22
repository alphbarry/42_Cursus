/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:24:05 by alphbarr          #+#    #+#             */
/*   Updated: 2024/07/01 19:24:11 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	is_key(int key)
{
	return (key == KEY_PLUS || key == KEY_PLUST || key == KEY_MINUS
		|| key == KEY_MINUST
		|| key == KEY_8 || key == KEY_8T || key == KEY_2 || key == KEY_2T
		|| key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT
		|| key == KEY_RIGHT || key == KEY_5 || key == KEY_5T || key == KEY_4
		|| key == KEY_4T || key == KEY_SPACE || key == KEY_6 || key == KEY_6T);
}

void	do_key(int key, t_fdf **matrix)
{
	handle_angle_keys(key, matrix);
	handle_scale_keys(key, matrix);
	handle_z_scale_keys(key, matrix);
	handle_shift_keys(key, matrix);
	handle_isometric_keys(key, matrix);
}

void	new_image(t_fdf **matrix)
{
	int		i;

	i = 0;
	while (i < (*matrix)->size_line * (*matrix)->win_y)
	{
		(*matrix)->addr[i] = 0;
		(*matrix)->addr[i + 1] = 0;
		(*matrix)->addr[i + 2] = 0;
		i += 4;
	}
}

int	deal_key(int key, t_fdf **matrix)
{
	if (is_key(key))
	{
		new_image(matrix);
		do_key(key, matrix);
		mlx_put_image_to_window((*matrix)->mlx_ptr,
			(*matrix)->win_ptr, (*matrix)->img_ptr, 0, 0);
		draw_matrix(matrix, (*matrix)->rows, (*matrix)->cols);
		print_menu(**matrix);
	}
	if (key == KEY_ESC)
	{
		mlx_destroy_image((*matrix)->mlx_ptr, (*matrix)->img_ptr);
		mlx_destroy_window((*matrix)->mlx_ptr, (*matrix)->win_ptr);
		mlx_destroy_display((*matrix)->mlx_ptr);
		free((*matrix)->mlx_ptr);
		free_matrix(matrix, (*matrix)->rows);
		exit(0);
	}
	return (0);
}
