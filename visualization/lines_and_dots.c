/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_and_dots.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:52:06 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/23 18:01:51 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		iso_draw(int *x, int *y, int z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

void		pixel_to_image(t_point *half, int x, int y, int color)
{
	int i;

	if (x >= 0 && x < 1000 && y >= 0 && y < 1000)
	{
		i = (x * 4) + (y * 4000);
		half->img_sourse[i++] = color;
		half->img_sourse[i++] = color >> 8;
		half->img_sourse[i] = color >> 16;
	}
}

t_pix		complect_t_pix(t_point *half, int x, int y)
{
	t_pix dot;

	dot.x = x;
	dot.y = y;
	dot.z = half->axis[y][x][0] * half->vizor.z_shift;
	dot.color = half->axis[y][x][1];
	return (dot);
}

void		drawline(t_pix start, t_pix end, t_point *half)
{
	t_pix	present;
	t_pix	delta;
	t_pix	sign;
	int		error;
	int		error2;

	init_var_draw(&delta, &sign, start, end);
	error = delta.x - delta.y;
	present = start;
	while (present.x != end.x || present.y != end.y)
	{
		pixel_to_image(half, present.x, present.y,\
					get_color(present, start, end, delta));
		error2 = error * 2;
		if (error2 > -delta.y)
		{
			error -= delta.y;
			present.x += sign.x;
		}
		if (error2 < delta.x)
		{
			error += delta.x;
			present.y += sign.y;
		}
	}
}
