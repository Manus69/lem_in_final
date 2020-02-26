/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_links_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:39:51 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/25 23:40:00 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	loop_in_links(t_room *first_room, t_room *second_room)
{
	t_links *list;

	list = first_room->links;
	while (list)
	{
		if (list->link == second_room)
			return (1);
		list = list->next;
	}
	list = second_room->links;
	while (list)
	{
		if (list->link == first_room)
			return (1);
		list = list->next;
	}
	return (0);
}
