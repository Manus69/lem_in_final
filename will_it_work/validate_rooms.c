/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:59:30 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/08 22:00:14 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		fill_coords_pool(t_lemin *lemin, int ***coords)
{
	int i;

	i = 0;
	if (!((*coords) = (int **)malloc(sizeof(int *) * (lemin->rooms_len + 1))))
		return (0);
	while (i < lemin->rooms_len)
	{
		if (!((*coords)[i] = (int *)malloc(sizeof(int) * 2)))
		{
			while (i)
				free((*coords)[--i]);
			free((*coords));
			return (0);
		}
		i++;
	}
	(*coords)[i] = NULL;
	i = -1;
	while (++i < lemin->rooms_len)
	{
		(*coords)[i][0] = lemin->rooms[i].x_coord;
		(*coords)[i][1] = lemin->rooms[i].y_coord;
	}
	return (1);
}

void	sort_coords(int ***coords)
{
	int **arr;
	int i;
	int *swap;
	int min;
	int j;

	i = -1;
	arr = *coords;
	while (arr[++i])
	{
		j = i;
		min = j;
		while (arr[j])
		{
			if (arr[min][0] > arr[j][0])
				min = j;
			j++;
		}
		swap = arr[i];
		arr[i] = arr[min];
		arr[min] = swap;
	}
}

int		search_duplicates(int **coords)
{
	int i;

	i = -1;
	while (coords[++i + 1])
	{
		if (coords[i][0] == coords[i + 1][0])
		{
			if (coords[i][1] == coords[i + 1][1])
				return (1);
		}
	}
	return (0);
}

int		check_coords(t_lemin *lemin)
{
	int **coords;

	if (!fill_coords_pool(lemin, &coords))
		return (0);
	sort_coords(&coords);
	if (search_duplicates(coords))
	{
		free_pool_int(&coords);
		return (0);
	}
	free_pool_int(&coords);
	return (1);
}

int		check_rooms(t_lemin *lemin)
{
	if (lemin->start < 0 || lemin->end < 0 || !check_rooms_name(lemin))
		return (0);
	if (!check_coords(lemin))
		return (0);
	return (1);
}
