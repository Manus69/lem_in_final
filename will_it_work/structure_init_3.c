/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_init_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:57:41 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/25 20:37:22 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		take_next_start(char *str, int prev_start)
{
	int i;

	i = 0;
	if (prev_start < 0)
		return (i);
	else
		i = prev_start;
	while (str[i] && str[i] != '-')
		i++;
	while (str[i] && str[i] == '-')
		i++;
	return (i);
}

int		take_next_border(char *str, int prev_border)
{
	int i;

	if (prev_border < 0)
		i = 0;
	else
		i = prev_border;
	while (str[i] && str[i] == '-')
		i++;
	while (str[i] && str[i] != '-')
		i++;
	return (i);
}

void	start_state(char **spl, int y, int *start, t_lemin *lemin)
{
	if (!ft_strncmp(spl[y], "##start", 7))
	{
		(*start)++;
		while (spl[y] && spl[y][0] == '#')
			y++;
		lemin->start = y;
	}
}

void	end_state(char **spl, int y, int *end, t_lemin *lemin)
{
	if (!ft_strncmp(spl[y], "##end", 5))
	{
		(*end)++;
		while (spl[y] && spl[y][0] == '#')
			y++;
		lemin->end = y;
	}
}

int		empty_rooms(t_lemin *lemin)
{
	lemin->empty_rooms = 1;
	return (0);
}
