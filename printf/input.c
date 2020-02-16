/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:14:36 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/10 19:35:07 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

union u_data	*get_csp_data(t_token *token, va_list *argument_list)
{
	union u_data	*data;

	data = mallokill(sizeof(union u_data));
	if (token->type == 'c')
		data->integer = (char)va_arg(*argument_list, int);
	else if (token->type == 's')
		data->string = va_arg(*argument_list, char *);
	else if (token->type == 'p')
		data->pointer = va_arg(*argument_list, void *);
	return (data);
}

union u_data	*get_di_data(t_token *token, va_list *argument_list)
{
	union u_data *data;

	data = mallokill(sizeof(union u_data));
	if (token->hh)
		data->integer = (char)va_arg(*argument_list, int);
	else if (token->h)
		data->integer = (short)va_arg(*argument_list, int);
	else if (token->l)
		data->long_int = (long int)va_arg(*argument_list, long int);
	else if (token->ll)
		data->long_long_int = (long long)va_arg(*argument_list, long long);
	else
		data->integer = va_arg(*argument_list, int);
	return (data);
}

union u_data	*get_usigned_data(t_token *token, va_list *argument_list)
{
	union u_data *data;

	data = mallokill(sizeof(union u_data));
	if (token->hh)
		data->u_integer = (unsigned char)va_arg(*argument_list, unsigned int);
	else if (token->h)
		data->u_integer = (unsigned short)va_arg(*argument_list, unsigned int);
	else if (token->l)
		data->u_long_int = va_arg(*argument_list, unsigned long int);
	else if (token->ll)
		data->u_long_long_int = va_arg(*argument_list, unsigned long long);
	else
		data->integer = va_arg(*argument_list, unsigned int);
	return (data);
}

union u_data	*get_f_data(t_token *token, va_list *argument_list)
{
	union u_data *data;

	data = mallokill(sizeof(union u_data));
	if (token->big_l)
		data->long_double = (long double)va_arg(*argument_list, long double);
	else
		data->just_double = va_arg(*argument_list, double);
	return (data);
}
