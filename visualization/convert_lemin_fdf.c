/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_lemin_fdf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 11:57:08 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 11:57:39 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		find_xoy_max(t_lemin *lemin, int xoy)
{
	int i;
	int max;

	i = -1;
	max = -2147483648;
	while (++i < lemin->rooms_len)
	{
		if (lemin->coords_pool[i][xoy] > max)
			max = lemin->coords_pool[i][xoy];
	}
	return (max + 1);
}

int		*make_one_cell(void)
{
	int *cell;

	if (!(cell = (int *)malloc(sizeof(int) * 3)))
		return (NULL);
	cell[0] = 0;
	cell[1] = 0;
	cell[3] = 0;
	return (cell);
}

int		**make_x_line(int max_x)
{
	int x;
	int **x_line;

	x = -1;
	if (!(x_line = (int **)malloc(sizeof(int *) * (max_x + 1))))
		return (NULL);
	while (++x < max_x)
	{
		x_line[x] = make_one_cell();
	}
	x_line[x] = NULL;
	return (x_line);
}

int		***from_lem_to_axis(t_lemin *lemin)
{
	int max_x;
	int max_y;
	int ***axis;
	int y;

	max_x = find_xoy_max(lemin, 0);
	max_y = find_xoy_max(lemin, 1);
	y = -1;
	if (!(axis = (int ***)malloc(sizeof(int **) * (max_y + 1))))
		return (NULL);
	while (++y < max_y)
	{
		axis[y] = make_x_line(max_x);
	}
	axis[y] = NULL;
	return (axis);
}
