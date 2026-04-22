/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:24:38 by alphbarr          #+#    #+#             */
/*   Updated: 2024/07/01 19:24:42 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_default(t_fdf *param)
{
	if (!param)
		ft_error("param is NULL in set_default");
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 1920;
	param->win_y = 1080;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	if (!param->mlx_ptr)
		ft_error("Failed to initialize mlx");
	param->win_ptr = mlx_new_window(param->mlx_ptr,
			param->win_x, param->win_y, "FDF");
	if (!param->win_ptr)
		ft_error("Failed to create window");
	param->img_ptr = mlx_new_image(param->mlx_ptr, param->win_x, param->win_y);
	if (!param->img_ptr)
		ft_error("Failed to create image");
	param->addr = mlx_get_data_addr(param->img_ptr,
			&(param->bpp), &(param->size_line), &(param->endian));
}

int	close_window(t_fdf **param)
{
	mlx_destroy_image((*param)->mlx_ptr, (*param)->img_ptr);
	mlx_destroy_window((*param)->mlx_ptr, (*param)->win_ptr);
	mlx_destroy_display((*param)->mlx_ptr);
	free((*param)->mlx_ptr);
	free_matrix(param, (*param)->rows);
	exit(0);
}

int	main(int ac, char **av)
{
	t_fdf	**matrix;

	if (ac != 2)
		ft_error("error of ./fdf map.fdf");
	matrix = read_file(av[1]);
	if (!matrix || !matrix[0])
		ft_error("Failed to read file");
	set_default(matrix[0]);
	draw_matrix(matrix, (*matrix)->rows, (*matrix)->cols);
	mlx_hook((*matrix)->win_ptr, 17, 0, close_window, matrix);
	mlx_key_hook((*matrix)->win_ptr, deal_key, matrix);
	mlx_loop((*matrix)->mlx_ptr);
}
