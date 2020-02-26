/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_init_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:02:30 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/08 21:16:35 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			find_borders(t_lemin *lemin, char **spl)
{
	int y;
	int rooms_count;

	y = lemin->start_rooms - 1;
	rooms_count = 0;
	while (spl[++y])
	{
		if (spl[y][0] != '#' && !ft_strchr(spl[y], ' '))
			break ;
		if (spl[y][0] != '#')
			rooms_count++;
		if (!fill_start_end(spl, y, lemin))
			return (0);
	}
	lemin->rooms_len = rooms_count;
	lemin->start_links = y;
	if (lemin->start == y || lemin->end == y ||
			lemin->start == lemin->end)
		return (0);
	return (1);
}

void		init_ants_var(int *y, int *x, int *ower)
{
	*y = -1;
	*x = 0;
	*ower = 1;
}

int			take_ants(t_lemin *lemin, char **spl)
{
	int y;
	int x;
	int ower;

	init_ants_var(&y, &x, &ower);
	lemin->ant_count = -2;
	while (spl[++y] && lemin->ant_count == -2)
	{
		if (spl[y][x] != '#' && spl[y][x])
		{
			if (ft_isspace(spl[y][0]))
				return (0);
			lemin->ant_count = ft_atoi_push(spl[y], &x, &ower);
			if (lemin->ant_count < 1 || !ower || spl[y][x])
			{
				lemin->start_rooms = y;
				return (0);
			}
		}
		else if (!ft_strncmp(spl[y], "##start", 7) ||
				!ft_strncmp(spl[y], "##end", 5))
			return (0);
	}
	lemin->start_rooms = y;
	return (1);
}

int			fill_start_end(char **spl, int y, t_lemin *lemin)
{
	static int start_count;
	static int end_count;

	if (spl[y][0] == '#')
	{
		start_state(spl, y, &start_count, lemin);
		end_state(spl, y, &end_count, lemin);
	}
	if (start_count > 1 || end_count > 1)
		return (0);
	return (1);
}
