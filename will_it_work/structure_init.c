/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:11:02 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/16 16:30:52 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			remember_room_name(char *str, char **room_name, int *i)
{
	int end;
	int j;

	end = *i;
	j = 0;
	while (str[end] && str[end] != ' ')
		end++;
	if (!((*room_name) = (char *)malloc(sizeof(char) * (end + 1))))
		return (0);
	while (str[*i] && (*i) < end)
		(*room_name)[j++] = str[(*i)++];
	(*room_name)[j++] = '\0';
	return (1);
}

t_room		charge_room(char *str, int index_room, int *flag)
{
	t_room	room;
	int		ower;
	int		i;

	room.index = index_room;
	room.part = 0;
	ower = 1;
	i = 0;
	if (!remember_room_name(str, &room.name, &i))
		*flag = 1;
	room.x_coord = ft_atoi_push(str, &i, &ower);
	room.y_coord = ft_atoi_push(str, &i, &ower);
	if (!ower || str[i])
		*flag = 2;
	room.hash = hash_my_name(room.name, 0, ft_strlen(room.name));
	room.level = 0;
	room.visited = 0;
	room.dead = 0;
	room.entrance = NULL;
	room.output = NULL;
	room.midget = NULL;
	room.so_strange = NULL;
	return (room);
}

void		take_start_end(t_lemin *lemin, int room, int y)
{
	if (y == lemin->start)
	{
		lemin->rooms[room].part = 1;
		lemin->start = room;
	}
	if (y == lemin->end)
	{
		lemin->rooms[room].part = -1;
		lemin->end = room;
	}
}

void		init_var_in_take_rooms(int *y, int *room, int *flag, t_lemin *lemin)
{
	*y = lemin->start_rooms - 1;
	*room = 0;
	*flag = 0;
}

int			take_rooms(t_lemin *lemin, char **spl)
{
	int y;
	int room;
	int flag;

	if (!find_borders(lemin, spl))
		return (empty_rooms(lemin));
	if (!(lemin->rooms = (t_room *)malloc(sizeof(t_room) * lemin->rooms_len)))
		return (lemin->rooms_len = 0);
	init_var_in_take_rooms(&y, &room, &flag, lemin);
	while (++y < lemin->start_links)
	{
		if (spl[y][0] != '#')
		{
			lemin->rooms[room] = charge_room(spl[y], room, &flag);
			if (flag)
			{
				lemin->rooms_len = (flag == 1 ? room : room + 1);
				return (0);
			}
			lemin->rooms[room].links = NULL;
			take_start_end(lemin, room, y);
			room++;
		}
	}
	return (1);
}
