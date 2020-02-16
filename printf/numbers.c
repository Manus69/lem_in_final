/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:15:36 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/10 19:10:06 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

const char *g_possible_digits = "0123456789abcdef";

int		number_of_digits_mk2(unsigned long long number, int base)
{
	int					digits;
	unsigned long long	result;

	digits = 1;
	result = number;
	while (result)
	{
		result = result / base;
		if (!result)
			break ;
		digits = digits + 1;
	}
	return (digits);
}

char	*why_integer_to_ascii(long long number, int base)
{
	int					sign;
	unsigned long long	result;
	int					digits;
	char				*number_string;

	sign = 1;
	result = number;
	if (number < 0 && base == 10)
	{
		sign = -1;
		result = -number;
	}
	digits = ((sign == -1) ? number_of_digits_mk2(result, base) + 1 :
	number_of_digits_mk2(result, base));
	number_string = ft_strnew(digits);
	while (digits - 1 >= 0)
	{
		number_string[digits - 1] = g_possible_digits[(result % base)];
		digits = digits - 1;
		result = result / base;
	}
	if (sign == -1 && base == 10)
		number_string[0] = '-';
	return (number_string);
}

char	*unsigned_integer_to_ascii(unsigned long long number, int base)
{
	unsigned long long			result;
	int							digits;
	int							index;
	char						*number_string;

	digits = number_of_digits_mk2(number, base);
	index = digits - 1;
	number_string = ft_strnew(digits);
	if (base > 16 || base < 2)
		return (NULL);
	else
		result = number;
	while (index >= 0)
	{
		number_string[index] = g_possible_digits[(result % base)];
		index = index - 1;
		result = result / base;
	}
	return (number_string);
}

char	*decimal_part_mk4(long double x, int number_of_digits,
int *last_digit_flag, int *extra_junk_flag)
{
	long double	decimal;
	char		*string;
	int			j;

	string = get_str_of_something(number_of_digits + 1, '0');
	decimal = x - (long long)x;
	j = 0;
	while (number_of_digits + 1)
	{
		decimal = decimal * 10;
		string[j] = (long long)decimal + '0';
		j = j + 1;
		decimal = decimal - (long long)decimal;
		number_of_digits = number_of_digits - 1;
	}
	if (absolute_value(1.0 - decimal) <= EPSILON)
	{
		if (round_propagate(string, j - 1))
			return (become_dumb(string));
	}
	else if (decimal <= TRUNCATION_CONST)
		*last_digit_flag = 1;
	else
		*extra_junk_flag = 1;
	return (string);
}
