/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rooms_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:48:52 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 17:49:54 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			room_l_name(char *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]) && str[i])
	{
		i++;
	}
	if (!str[i] || str[i] == 'L')
		return (1);
	return (0);
}

int			list_cmp(t_hash_table *begin_list)
{
	t_hash_table *list;
	t_hash_table *start;

	start = begin_list;
	while (start->next)
	{
		if (room_l_name(start->link->name))
			return (0);
		list = start->next;
		while (list)
		{
			if (!ft_strcmp(start->link->name, list->link->name))
				return (0);
			list = list->next;
		}
		start = start->next;
	}
	if (room_l_name(start->link->name))
		return (0);
	return (1);
}

int			check_rooms_name(t_lemin *lemin)
{
	int i;

	i = -1;
	while (++i < 4096)
	{
		if (lemin->table_hashes[i])
		{
			if (!list_cmp(lemin->table_hashes[i]))
				return (0);
		}
	}
	return (1);
}

int			fill_coords_pool(t_lemin *lemin, int ***coords)
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
