/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:08:45 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/14 01:58:56 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

void		ft_atoi_mark(char *str, int *i, int *mark)
{
	if (str[*i] == '-')
		*mark = -1;
	(*i)++;
}

int			ft_atoi_push(char *str, int *i, int *ower)
{
	int		mark;
	long	result;
	int		dig;

	result = 0;
	mark = 1;
	dig = 0;
	while ((str[*i] == '\f' || str[*i] == '\n' || str[*i] == '\r' ||
				str[*i] == '\v' || str[*i] == '\t' || str[*i] == ' '))
		(*i)++;
	if ((str[*i] == '-') || (str[*i] == '+'))
		ft_atoi_mark(str, i, &mark);
	while ((str[*i] >= '0') && (str[*i] <= '9'))
	{
		dig++;
		if ((result * 10) < result)
			*ower = 0;
		result = (result * 10) + (str[*i] - '0');
		(*i)++;
	}
	if (result * mark > 2147483647 || result * mark < -2147483648 || !dig)
		*ower = 0;
	return (result * mark);
}

int			make_free_lemin(t_lemin *lemin)
{
	free_for_all(lemin);
	return (0);
}

int			init_lemin(t_lemin *lemin, char **spl)
{
	lemin->initial_text = spl;
	lemin->rooms_len = 0;
	null_pointer_upload(lemin);
	if (!take_ants(lemin, spl))
		return (0);
	if (!take_rooms(lemin, spl))
		return (0);
	hash_table_upload(lemin);
	if (!check_rooms(lemin))
		return (0);
	if (!take_links(lemin, spl))
		return (0);
	return (1);
}
