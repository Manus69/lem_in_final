/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_axis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:49:18 by bgerda            #+#    #+#             */
/*   Updated: 2019/11/23 17:52:49 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		spl_is_number(char c)
{
	if ((((c >= '0' && c <= '9') ||
		((c >= 'a' && c <= 'f') ||
		(c >= 'A' && c <= 'F')) ||
		c == 'x' || c == 'X')))
		return (1);
	else
		return (0);
}

void	find_xy_interval(t_point *half)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (half->axis[y])
		y++;
	half->max_y = y;
	while (half->axis[0][x])
		x++;
	half->max_x = x;
}

void	edge_of_abyss(int ***spl, int *min, int *max)
{
	int x;
	int y;

	y = -1;
	if (!min && !max)
	{
		*min = 2147483647;
		*max = -2147483648;
	}
	while (spl[++y])
	{
		x = -1;
		while (spl[y][++x])
		{
			if (spl[y][x][0] > *max)
				*max = spl[y][x][0];
			if (spl[y][x][0] < *min)
				*min = spl[y][x][0];
		}
	}
}

void	free_to_axis(int ****spl)
{
	int ***axis;
	int x;
	int y;

	y = -1;
	axis = *spl;
	while (axis[++y])
	{
		x = -1;
		while (axis[y][++x])
			free(axis[y][x]);
		free(axis[y]);
	}
	free(axis);
	axis = NULL;
}
