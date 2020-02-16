/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 11:34:09 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 11:54:07 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_draw(int *x, int *error, int *y, int radius)
{
	*x = 0;
	*error = 0;
	*y = radius;
}

static void		direct_radius(t_pix start, int x, int y, t_point *half)
{
	pixel_to_image(half, start.x + x, start.y + y, start.color);
	pixel_to_image(half, start.x + x, start.y - y, start.color);
	pixel_to_image(half, start.x - x, start.y + y, start.color);
	pixel_to_image(half, start.x - x, start.y - y, start.color);
}

static void		first_if(int *x, int *delta)
{
	++(*x);
	(*delta) += 2 * (*x) + 1;
}

static void		second_if(int *y, int *delta)
{
	--(*y);
	(*delta) += 1 - 2 * (*y);
}

void			draw_circle(t_point *half, t_pix start, int radius)
{
	int delta;
	int x;
	int error;
	int y;

	delta = 1 - 2 * radius;
	init_draw(&x, &error, &y, radius);
	while (y >= 0)
	{
		direct_radius(start, x, y, half);
		error = 2 * (delta + y) - 1;
		if (delta < 0 && error <= 0)
		{
			first_if(&x, &delta);
			continue;
		}
		error = 2 * (delta - x) - 1;
		if (delta > 0 && error > 0)
		{
			second_if(&y, &delta);
			continue;
		}
		next_wh_circle(&x, &y, &delta);
	}
}
