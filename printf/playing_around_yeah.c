/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing_around_yeah.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:53:47 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/11 12:35:06 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

union u_data	*get_data(t_token *token, va_list *argument_list)
{
	union u_data	*data;

	if (token->type == 'c' || token->type == 's' || token->type == 'p')
		data = get_csp_data(token, argument_list);
	else if (token->type == 'd' || token->type == 'i')
		data = get_di_data(token, argument_list);
	else if (token->type == 'o' || token->type == 'u' ||
	token->type == 'x' || token->type == 'X')
		data = get_usigned_data(token, argument_list);
	else if (token->type == 'f')
		data = get_f_data(token, argument_list);
	else
	{
		data = mallokill(sizeof(union u_data));
		data->pointer = va_arg(*argument_list, void *);
	}
	return (data);
}

int				count_and_destroy(t_jcount_tuple **tuple)
{
	int count;

	count = (*tuple)->count;
	free(*tuple);
	*tuple = NULL;
	return (count);
}

t_jcount_tuple	*get_tuple_and_check(const char *format)
{
	t_jcount_tuple	*tuple;

	if (!format)
		exit(1);
	tuple = mallokill(sizeof(t_jcount_tuple));
	tuple->j = 0;
	tuple->count = 0;
	return (tuple);
}

int				create_confusion(int *j, int *count, const char *format)
{
	if (format[*j] != '%')
	{
		write(1, &(format[*j]), 1);
		*j = *j + 1;
		*count = *count + 1;
		return (1);
	}
	if (format[*j] == '%' && format[*j + 1] == '%')
	{
		ft_putchar('%');
		*j = *j + 2;
		*count = *count + 1;
		return (1);
	}
	return (0);
}
