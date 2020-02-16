/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:59:45 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/16 16:19:18 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void					fill_sqr_table(unsigned int sqr_table[])
{
	int i;

	i = 0;
	sqr_table[i++] = 97;
	while (i < 100)
	{
		sqr_table[i] = sqr_table[i - 1] * 97;
		i++;
	}
}

unsigned int			hash_my_name(char *str, int start, int border)
{
	unsigned int			hash;
	int						i;
	static unsigned int		sqr_table[100];

	if (!sqr_table[0])
		fill_sqr_table(sqr_table);
	i = 0;
	hash = 0;
	while (start < border)
	{
		if (i > 99)
			i = 0;
		hash += (str[start++] * sqr_table[i++]);
	}
	hash %= 4096;
	return (hash);
}
