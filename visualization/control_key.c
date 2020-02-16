/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:41:12 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 11:56:45 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				mouse_press_hook(int key, int x, int y, void *param)
{
	t_point *half;

	half = ((t_point *)param);
	if (key == 1 && x && y)
		half->mouse.left_press = 1;
	if (key == 4)
		half->vizor.zoom += 2;
	if (key == 5 && half->vizor.zoom > 2)
		half->vizor.zoom -= 2;
	if (key == 2)
	{
		zero_to_vizor(half);
		zero_to_rot(&half->rot);
	}
	ft_bzero(half->img_sourse, 4000000);
	draw_point(half);
	mlx_put_image_to_window(half->mlx_ptr, half->window, half->map, 0, 0);
	return (0);
}

void			motion_draw(t_point *half)
{
	if (half->mouse.prev_x == half->mouse.x &&
			half->mouse.prev_y > half->mouse.y)
		half->rot.alpha -= 0.05;
	else if (half->mouse.prev_x == half->mouse.x &&
			half->mouse.prev_y < half->mouse.y)
		half->rot.alpha += 0.05;
	else if (half->mouse.prev_x < half->mouse.x &&
			half->mouse.prev_y == half->mouse.y)
		half->rot.tetta += 0.05;
	else if (half->mouse.prev_x > half->mouse.x &&
			half->mouse.prev_y == half->mouse.y)
		half->rot.tetta -= 0.05;
	else if ((half->mouse.prev_x < half->mouse.x && half->mouse.prev_y \
				< half->mouse.y) || (half->mouse.prev_x > half->mouse.x &&
			half->mouse.prev_y < half->mouse.y))
		half->rot.beta += 0.05;
	else if ((half->mouse.prev_x > half->mouse.x &&
			half->mouse.prev_y > half->mouse.y) ||
			(half->mouse.prev_x < half->mouse.x &&
			half->mouse.prev_y > half->mouse.y))
		half->rot.beta -= 0.05;
	ft_bzero(half->img_sourse, 4000000);
	draw_point(half);
	mlx_put_image_to_window(half->mlx_ptr, half->window, half->map, 0, 0);
	draw_text(half);
}

int				motion_hook(int x, int y, void *param)
{
	t_point *half;

	half = ((t_point *)param);
	if (half->mouse.left_press)
	{
		half->mouse.prev_x = half->mouse.x;
		half->mouse.prev_y = half->mouse.y;
		half->mouse.x = x;
		half->mouse.y = y;
		motion_draw(half);
	}
	return (0);
}

int				mouse_release_hook(int key, int x, int y, void *param)
{
	t_point *half;

	half = ((t_point *)param);
	if (key == 1 && x && y)
		half->mouse.left_press = 0;
	return (0);
}
