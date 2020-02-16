/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:41:51 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/11 11:26:49 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int		get_number_of_digits(int n)
{
	int		number_of_digits;

	number_of_digits = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		number_of_digits = number_of_digits + 1;
	}
	return (number_of_digits);
}

static char		*get_number_string(int n, int number_of_digits, int initial_n)
{
	char *number;

	number = (char *)malloc(sizeof(char) * (number_of_digits + 1));
	if (!number)
		return (NULL);
	while (number_of_digits > 0)
	{
		if (n == 0)
		{
			*number = '0';
			number = number + 1;
			number_of_digits = number_of_digits - 1;
		}
		else
		{
			*number = (n / why_int_power(10, number_of_digits - 1) + '0');
			n = n % why_int_power(10, number_of_digits - 1);
			number_of_digits = number_of_digits - 1;
			number = number + 1;
		}
	}
	*number = '\0';
	number = number - initial_n;
	return (number);
}

static char		*get_special(char type)
{
	char *special;
	char *minimum;

	if (type == 'z')
	{
		special = (char *)malloc(sizeof(char) * 2);
		if (!special)
			return (NULL);
		special[0] = '0';
		special[1] = '\0';
		return (special);
	}
	else
	{
		minimum = "-2147483648";
		special = ft_strdup(minimum);
		return (special);
	}
}

char			*ft_itoa(int n)
{
	int		sign;
	int		number_of_digits;
	char	*number;
	int		initial_number_of_digits;

	if (n == -2147483648)
		return (get_special('m'));
	sign = get_sign(n);
	n = why_int_absolute_value(n);
	number_of_digits = get_number_of_digits(n);
	initial_number_of_digits = get_number_of_digits(n);
	if (n == 0)
		return (get_special('z'));
	number = get_number_string(n, number_of_digits, initial_number_of_digits);
	if (!number)
		return (NULL);
	if (sign == -1)
		number = ft_strjoin("-", number);
	return (number);
}
