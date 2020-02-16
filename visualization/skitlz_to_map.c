/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skitlz_to_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:46:36 by bgerda            #+#    #+#             */
/*   Updated: 2019/11/23 17:48:55 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		first_color(int z, int max_z, int min_z)
{
	double part;

	part = percent(min_z, max_z, z);
	if (part < 0.2)
		return (0x006400);
	else if (part < 0.4)
		return (0x00BFFF);
	else if (part < 0.6)
		return (0x8B008B);
	else if (part < 0.8)
		return (0xFFFF00);
	else
		return (0x0000FF);
}

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_pix present, t_pix start, t_pix end, t_pix delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (present.color == end.color)
		return (present.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, present.x);
	else
		percentage = percent(start.y, end.y, present.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16)
		& 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8)
		& 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	make_first_color(int ****axis, int min, int max)
{
	int ***spl;
	int x;
	int y;

	y = -1;
	spl = *axis;
	while (spl[++y])
	{
		x = -1;
		while (spl[y][++x])
		{
			if (spl[y][x][1] == 0)
				spl[y][x][1] = first_color(spl[y][x][0], max, min);
		}
	}
}
