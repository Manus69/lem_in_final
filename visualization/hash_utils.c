/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:19:39 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 15:20:23 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_hash_cell(t_hash_table **cell)
{
	if (!((*cell) = (t_hash_table *)malloc(sizeof(t_hash_table))))
		return (0);
	(*cell)->next = NULL;
	return (1);
}

int		create_hash_cell_chain(t_hash_table **cell)
{
	t_hash_table *chain;

	if (!((chain) = (t_hash_table *)malloc(sizeof(t_hash_table))))
		return (0);
	chain->next = *cell;
	(*cell) = chain;
	return (1);
}

void	hash_table_upload(t_lemin *lemin)
{
	int i;

	i = -1;
	while (++i < lemin->rooms_len)
	{
		if (!lemin->table_hashes[lemin->rooms[i].hash])
		{
			create_hash_cell(&lemin->table_hashes[lemin->rooms[i].hash]);
			lemin->table_hashes[lemin->rooms[i].hash]->link = &lemin->rooms[i];
		}
		else
		{
			create_hash_cell_chain(&lemin->table_hashes[lemin->rooms[i].hash]);
			lemin->table_hashes[lemin->rooms[i].hash]->link = &lemin->rooms[i];
		}
	}
}

void	null_pointer_upload(t_lemin *lemin)
{
	int i;

	i = -1;
	while (++i < 4096)
		lemin->table_hashes[i] = NULL;
}
