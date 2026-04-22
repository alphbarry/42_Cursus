/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:25:39 by alphbarr          #+#    #+#             */
/*   Updated: 2024/07/01 19:25:43 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(t_fdf *a, t_fdf *b, t_fdf *param)
{
	a->x *= param->scale;
	a->y *= param->scale;
	b->x *= param->scale;
	b->y *= param->scale;
	a->z *= param->z_scale;
	b->z *= param->z_scale;
}

void	set_param(t_fdf *a, t_fdf *b, t_fdf *param)
{
	zoom(a, b, param);
	if (param->is_isometric)
	{
		isometric(a, param->angle);
		isometric(b, param->angle);
	}
	a->x += param->shift_x;
	a->y += param->shift_y;
	b->x += param->shift_x;
	b->y += param->shift_y;
}
