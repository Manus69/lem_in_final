/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:02:25 by gemerald          #+#    #+#             */
/*   Updated: 2020/01/27 23:03:05 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_links(t_lemin *lemin)
{
	int i;

	i = -1;
	while (++i < lemin->rooms_len)
	{
		free(lemin->rooms[i].name);
		if (lemin->rooms[i].links)
			del_list_links(&lemin->rooms[i].links);
	}
}

void		del_list_hash(t_hash_table **hash_chain)
{
	t_hash_table	*link;
	t_hash_table	*f_link;

	link = *hash_chain;
	while (link)
	{
		f_link = link->next;
		free(link);
		link = f_link;
	}
}

void		free_hash_table(t_lemin *lemin)
{
	int i;

	i = -1;
	while (++i < 4096)
	{
		if (lemin->table_hashes[i])
			del_list_hash(&lemin->table_hashes[i]);
	}
}

void		free_for_all(t_lemin *lemin)
{
	int y;

	y = -1;
	while (lemin->initial_text[++y])
		free(lemin->initial_text[y]);
	free(lemin->initial_text);
	free_hash_table(lemin);
	if (!lemin->empty_rooms)
	{
		free_links(lemin);
		free(lemin->rooms);
	}
}
