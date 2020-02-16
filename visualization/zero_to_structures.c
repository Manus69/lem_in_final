/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_to_structures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:42:25 by bgerda            #+#    #+#             */
/*   Updated: 2020/02/09 17:40:36 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zero_to_rot(t_rot *rot)
{
	rot->alpha = 0;
	rot->beta = 0;
	rot->tetta = 0;
}

void	zero_to_mouse(t_point *half)
{
	half->mouse.prev_x = 0;
	half->mouse.prev_y = 0;
	half->mouse.x = 0;
	half->mouse.y = 0;
	half->mouse.left_press = 0;
}

void	zero_to_vizor(t_point *half)
{
	half->vizor.x_shift = 0;
	half->vizor.y_shift = 0;
	half->vizor.z_shift = 1;
	if (half->max_x < 50)
		half->vizor.zoom = 30;
	else if (half->max_x < 500)
		half->vizor.zoom = 3;
	else
		half->vizor.zoom = 1;
}

void	zero_to_half(t_point *half, t_lemin *lemin)
{
	half->axis = (int ***)from_lem_to_axis(lemin);
	touch_my_node(half, lemin);
	half->min_z = 0;
	half->max_z = 0;
	half->projection = 0;
	half->mlx_ptr = mlx_init();
	half->window = mlx_new_window(half->mlx_ptr, 1000, 1000, "fdf");
	half->map = mlx_new_image(half->mlx_ptr, 1000, 1000);
	half->img_sourse = mlx_get_data_addr(half->map, &half->bits_pp,
		&half->size_line, &half->endian);
	edge_of_abyss(half->axis, &half->min_z, &half->max_z);
	make_first_color(&half->axis, half->min_z, half->max_z);
	find_xy_interval(half);
	zero_to_mouse(half);
	zero_to_vizor(half);
	zero_to_rot(&half->rot);
}
