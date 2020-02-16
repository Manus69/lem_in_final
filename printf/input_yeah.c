/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_yeah.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:34:23 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/10 19:35:06 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

void			*get_di_pointer(union u_data *data, t_token *token)
{
	if (token->hh)
		return (&data->integer);
	else if (token->h)
		return (&data->integer);
	else if (token->l)
		return (&data->long_int);
	else if (token->ll)
		return (&data->long_long_int);
	else
		return (&data->integer);
}

void			*get_unsigned_type_pointer(union u_data *data, t_token *token)
{
	if (token->hh)
		return (&data->u_integer);
	else if (token->h)
		return (&data->u_integer);
	else if (token->l)
		return (&data->u_long_int);
	else if (token->ll)
		return (&data->u_long_long_int);
	else
		return (&data->integer);
}

void			*get_pointer(union u_data *data, t_token *token)
{
	if (token->type == 'c')
		return (&data->integer);
	else if (token->type == 's')
		return (data->string);
	else if (token->type == 'p')
		return (data->pointer);
	else if (token->type == 'd' || token->type == 'i')
		return (get_di_pointer(data, token));
	else if (token->type == 'o' || token->type == 'u' ||
	token->type == 'x' || token->type == 'X')
		return (get_unsigned_type_pointer(data, token));
	else if (token->type == 'f')
	{
		if (token->big_l)
			return (&data->long_double);
		else
			return (&data->just_double);
	}
	else
		return (&data->pointer);
}
