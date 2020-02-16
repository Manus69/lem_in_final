/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_visual_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:02:39 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 12:04:20 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		touch_my_node(t_point *half, t_lemin *lemin)
{
	int		i;
	int		l_count;
	t_links	*list;
	int		x;
	int		y;

	i = -1;
	while (++i < lemin->rooms_len)
	{
		l_count = 0;
		list = lemin->rooms[i].links;
		while (list)
		{
			list = list->next;
			l_count += 10;
		}
		x = lemin->rooms[i].x_coord;
		y = lemin->rooms[i].y_coord;
		half->axis[lemin->rooms[i].y_coord][lemin->rooms[i].x_coord][0] =\
						(i % 2) ? (10 + l_count) : -(10 + l_count);
	}
}
