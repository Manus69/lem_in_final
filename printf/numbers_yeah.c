/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_yeah.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:14:58 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/10 19:29:58 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

long double	absolute_value(long double x)
{
	return ((x < 0) ? -x : x);
}

int			round_propagate(char *decimal, int index)
{
	if (index == -1)
		return (1);
	if (decimal[index] != '9')
	{
		decimal[index] = decimal[index] + 1;
		return (0);
	}
	else
	{
		decimal[index] = '0';
		return (round_propagate(decimal, index - 1));
	}
}

char		*become_dumb(char *string)
{
	free(string);
	return (ft_strdup("overflow"));
}

void		waste_time(struct s_useless *why,
char *decimal_string, int precision)
{
	if (ft_strcmp("overflow", decimal_string) == 0)
		why->integer = why->integer + 1;
	else if (decimal_string[precision] - '0' > 5)
	{
		if (round_propagate(decimal_string, precision - 1))
			why->integer = why->integer + 1;
	}
	else if (decimal_string[precision] == '5' &&
	(decimal_string[precision - 1] - '0') % 2 == 0 &&
	!why->last_digit && !why->extra_junk)
		;
	else if (decimal_string[precision] == '5' &&
	(why->last_digit || why->extra_junk))
	{
		if (round_propagate(decimal_string, precision - 1))
			why->integer = why->integer + 1;
	}
	else if (decimal_string[precision] == '5' && why->integer == 0)
	{
		if (round_propagate(decimal_string, precision - 1))
			why->integer = why->integer + 1;
	}
}
