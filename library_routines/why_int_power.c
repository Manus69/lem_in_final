/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   why_int_power.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:51:55 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/10 13:52:02 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		why_int_power(unsigned int base, unsigned int exponent)
{
	unsigned int		value;
	unsigned int		j;

	if (exponent == 0)
		return (1);
	if (exponent == 1)
		return (base);
	j = 1;
	value = base;
	while (j < exponent)
	{
		value = value * base;
		j = j + 1;
	}
	return (value);
}
