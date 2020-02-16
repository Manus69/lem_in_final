/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:10:40 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/23 17:40:22 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotor_map(int key, t_point *half)
{
	if (key == 89)
		half->rot.alpha += 0.1;
	if (key == 92)
		half->rot.alpha -= 0.1;
	if (key == 86)
		half->rot.beta += 0.1;
	if (key == 88)
		half->rot.beta -= 0.1;
	if (key == 83)
		half->rot.tetta += 0.1;
	if (key == 85)
		half->rot.tetta -= 0.1;
	if (key == 87 || key == 91)
	{
		half->projection = 1;
		zero_to_vizor(half);
		zero_to_rot(&half->rot);
	}
	ft_bzero(half->img_sourse, 4000000);
	draw_point(half);
	mlx_put_image_to_window(half->mlx_ptr, half->window, half->map, 0, 0);
	draw_text(half);
}

void			shift_map(int key, t_point *half)
{
	if (key == 126)
		half->vizor.y_shift -= 10;
	if (key == 125)
		half->vizor.y_shift += 10;
	if (key == 124)
		half->vizor.x_shift += 10;
	if (key == 123)
		half->vizor.x_shift -= 10;
	ft_bzero(half->img_sourse, 4000000);
	draw_point(half);
	mlx_put_image_to_window(half->mlx_ptr, half->window, half->map, 0, 0);
	draw_text(half);
}

int				key_press_hook(int key, void *param)
{
	t_point *half;

	half = ((t_point *)param);
	if (key == 53)
	{
		free_for_all(half->lem);
		exit(0);
	}
	if (key == 89 || key == 92 || key == 86 || key == 88 || key == 83 ||
			key == 85 || key == 87)
		rotor_map(key, half);
	if (key == 126 || key == 125 || key == 123 || key == 124)
		shift_map(key, half);
	if (key == 49)
		move_my_ants(half);
	return (0);
}

int				exit_hook(int key, void *param)
{
	if (key && param)
	{
		exit(1);
	}
	return (0);
}

void			set_hooks(t_point *half)
{
	mlx_hook(half->window, 4, 0, mouse_press_hook, half);
	mlx_hook(half->window, 2, 0, key_press_hook, half);
	mlx_hook(half->window, 5, 0, mouse_release_hook, half);
	mlx_hook(half->window, 6, 0, motion_hook, half);
	mlx_hook(half->window, 17, 0, exit_hook, half);
}
