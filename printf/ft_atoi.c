/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:14:13 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/11 14:17:01 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

	sign = 1;
	while (why_is_whitespace(*str))
		str = str + 1;
	if ((*str == '-') && ft_isdigit(*(str + 1)))
	{
		sign = -1;
		str = str + 1;
	}
	else if ((*str == '+') && ft_isdigit(*(str + 1)))
		str = str + 1;
	result = 0;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		result = result * 10 + (*str - '0');
		str = str + 1;
	}
	if (result > 9223372036854775807 && sign == -1)
		return (0);
	else if (result > 9223372036854775807 && sign == 1)
		return (-1);
	return (sign * result);
}
