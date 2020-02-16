/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_draw_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 11:54:24 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 15:40:38 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	next_wh_circle(int *x, int *y, int *delta)
{
	++(*x);
	(*delta) += 2 * ((*x) - (*y));
	--(*y);
}

void	init_ant_name(char *str, int *start, int *border, char **ant_name)
{
	*start = -1;
	*border = -1;
	(*ant_name) = print_ant_name(str, (*start));
	*start = take_next_start(str, (*start));
	*border = take_next_border(str, (*border));
	*start = take_next_start(str, (*start));
}
