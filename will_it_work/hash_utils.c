/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:00:48 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/14 01:58:01 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_hash_table	*create_hash_cell(t_room *room)
{
	t_hash_table *tmp;

	if (!((tmp) = (t_hash_table *)malloc(sizeof(t_hash_table))))
		return (NULL);
	tmp->link = room;
	tmp->next = NULL;
	return (tmp);
}

int				create_hash_cell_chain(t_hash_table **cell)
{
	t_hash_table *chain;

	if (!((chain) = (t_hash_table *)malloc(sizeof(t_hash_table))))
		return (0);
	chain->next = *cell;
	(*cell) = chain;
	return (1);
}

void			hash_table_upload(t_lemin *lemin)
{
	int i;

	i = -1;
	while (++i < lemin->rooms_len)
	{
		if (!lemin->table_hashes[lemin->rooms[i].hash])
		{
			lemin->table_hashes[lemin->rooms[i].hash] =\
				create_hash_cell(&lemin->rooms[i]);
		}
		else
		{
			create_hash_cell_chain(&lemin->table_hashes[lemin->rooms[i].hash]);
			lemin->table_hashes[lemin->rooms[i].hash]->link = &lemin->rooms[i];
		}
	}
}

void			null_pointer_upload(t_lemin *lemin)
{
	int i;

	i = -1;
	while (++i < 4096)
		lemin->table_hashes[i] = NULL;
}
