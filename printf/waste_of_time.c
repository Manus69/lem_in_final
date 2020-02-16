/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waste_of_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:09:16 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/11 14:02:50 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

void	process_sign(long double *x, int *sign, long long *integer)
{
	*sign = 1;
	if (*x < 0)
	{
		*sign = -1;
		*x = (-1) * (*x);
	}
	*integer = (long long)(*x);
}

void	set_variables(int *last_digit, int *extra_junk)
{
	*last_digit = 0;
	*extra_junk = 0;
}

char	*make_unintelligible(struct s_useless *why,
char *decimal_string, int precision)
{
	char *save;
	char *save_again;
	char *result;

	waste_time(why, decimal_string, precision);
	save = decimal_string;
	decimal_string = ft_strsub(decimal_string, 0, precision);
	free(save);
	save = decimal_string;
	decimal_string = ft_strjoin(".", decimal_string);
	free(save);
	result = why_integer_to_ascii(why->integer, 10);
	save = result;
	save_again = decimal_string;
	result = ft_strjoin(result, decimal_string);
	free(save);
	free(save_again);
	return (result);
}

char	*make_incomprehensible(char *result)
{
	char *save;

	save = result;
	result = ft_strjoin("-", result);
	free(save);
	return (result);
}

char	*real_to_ascii_mk3(long double x, int precision)
{
	char				*result;
	char				*decimal_string;
	struct s_useless	*why;

	why = mallokill(sizeof(struct s_useless));
	process_sign(&x, &why->sign, &why->integer);
	set_variables(&why->last_digit, &why->extra_junk);
	decimal_string = decimal_part_mk4(x, precision,
	&why->last_digit, &why->extra_junk);
	if (precision)
		result = make_unintelligible(why, decimal_string, precision);
	else
	{
		if (decimal_string[0] - '0' >= 5)
			why->integer = why->integer + 1;
		result = why_integer_to_ascii(why->integer, 10);
	}
	if (why->sign == -1)
		result = make_incomprehensible(result);
	free(why);
	if (!precision)
		free(decimal_string);
	return (result);
}
