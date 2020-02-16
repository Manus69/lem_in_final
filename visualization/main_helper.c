/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:54:50 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 15:55:24 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	upload_link(t_point *half, t_pix start, t_pix end)
{
	charge_draw(&end, half);
	drawline(start, end, half);
}

void	draw_start(t_point *half, t_pix start, int radius)
{
	start.color = 0xFFFFFF;
	while (--radius)
		draw_circle(half, start, radius);
}

void	draw_end(t_point *half, t_pix start, int radius)
{
	start.color = 0xFF00FF;
	while (--radius)
		draw_circle(half, start, radius);
}

void	draw_point_wh(t_pix *start, t_pix *end, t_point *half, t_links **list)
{
	*end = complect_t_pix(half, (*list)->link->x_coord,\
					(*list)->link->y_coord);
	upload_link(half, (*start), (*end));
	(*list) = (*list)->next;
}

int		draw_point(t_point *half)
{
	int			i;
	t_links		*list;
	t_pix		start;
	t_pix		end;
	int			radius;

	i = -1;
	while (++i < half->lem->rooms_len)
	{
		radius = 10;
		list = half->lem->rooms[i].links;
		start = complect_t_pix(half,\
			half->lem->rooms[i].x_coord, half->lem->rooms[i].y_coord);
		charge_draw(&start, half);
		while (list)
			draw_point_wh(&start, &end, half, &list);
		draw_circle(half, start, radius);
		mlx_string_put(half->mlx_ptr, half->window,\
				start.x, start.y, 0xFFFFFF, half->lem->rooms[i].name);
		if (half->lem->rooms[i].part > 0)
			draw_start(half, start, radius);
		if (half->lem->rooms[i].part < 0)
			draw_end(half, start, radius);
	}
	return (0);
}
