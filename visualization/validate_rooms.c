/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:40:45 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 17:42:58 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		sort_coords(int ***coords)
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

int			search_duplicates(int **coords)
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

void		free_pool_int(int ***coords)
{
	int **arr;
	int i;

	i = 0;
	arr = *coords;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int			check_coords(t_lemin *lemin)
{
	int **coords;

	if (!fill_coords_pool(lemin, &coords))
		return (0);
	sort_coords(&coords);
	lemin->coords_pool = coords;
	if (search_duplicates(coords))
	{
		free_pool_int(&coords);
		return (0);
	}
	return (1);
}

int			check_rooms(t_lemin *lemin)
{
	if (lemin->start < 0 || lemin->end < 0 || !check_rooms_name(lemin))
		return (0);
	if (!check_coords(lemin))
		return (0);
	return (1);
}
