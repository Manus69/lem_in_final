/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:05:54 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 16:07:05 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

int		ft_atoi_push(char *str, int *i, int *ower)
{
	int		mark;
	long	result;

	result = 0;
	mark = 1;
	while ((str[*i] == '\f' || str[*i] == '\n' || str[*i] == '\r' ||\
				str[*i] == '\v' || str[*i] == '\t' || str[*i] == ' '))
		(*i)++;
	if ((str[*i] == '-') || (str[*i] == '+'))
	{
		if (str[*i] == '-')
			mark = -1;
		(*i)++;
	}
	while ((str[*i] >= '0') && (str[*i] <= '9'))
	{
		if ((result * 10) < result)
			*ower = 0;
		result = (result * 10) + (str[*i] - '0');
		(*i)++;
	}
	if (result * mark > 2147483647 || result * mark < -2147483648)
		*ower = 0;
	return (result * mark);
}

void	print_rooms(t_lemin *lemin)
{
	int		i;
	t_links	*list;

	i = 0;
	while (i < lemin->rooms_len)
	{
		list = lemin->rooms[i].links;
		printf("room index = %d\n", lemin->rooms[i].index);
		printf("room name = %s\n", lemin->rooms[i].name);
		while (list)
		{
			printf("room nextdoor = %d\n", list->link->index);
			list = list->next;
		}
		i++;
		ft_putchar('\n');
	}
}

int		init_lemin(t_lemin *lemin, char **spl)
{
	int end;

	end = 1;
	lemin->initial_text = spl;
	null_pointer_upload(lemin);
	if (!take_ants(lemin, spl))
		end = 0;
	if (!take_rooms(lemin, spl))
		end = 0;
	hash_table_upload(lemin);
	if (!check_rooms(lemin))
		end = 0;
	if (end && !take_links(lemin, spl))
		end = 0;
	if (!end)
	{
		free_for_all(lemin);
		return (0);
	}
	return (1);
}
