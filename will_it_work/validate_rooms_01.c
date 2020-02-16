/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rooms_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:00:33 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/08 22:01:08 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		room_l_name(char *str)
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

int		list_cmp(t_hash_table *begin_list)
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

int		check_rooms_name(t_lemin *lemin)
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

void	free_pool_int(int ***coords)
{
	int **arr;
	int i;

	i = 0;
	arr = *coords;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
