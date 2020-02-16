/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:15:16 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/11 13:09:16 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

int	get_adjusted_string_length(t_output *output, t_token *token)
{
	int adjusted_length;

	adjusted_length = output->default_length;
	if (token->type == 'p')
		return (output->prefix_size + output->default_length);
	else if (why_get_index("ouxX", token->type) != -1)
	{
		if (token->hash)
			adjusted_length = adjusted_length + output->prefix_size;
		if (token->precision > adjusted_length)
			adjusted_length = token->precision + output->prefix_size;
		return (adjusted_length);
	}
	else if (token->type == 's')
	{
		if (token->precision != -1 &&
		(int)ft_strlen(output->result) >= token->precision)
			return (token->precision);
	}
	else if (token->type == 'd' || token->type == 'i' || token->type == 'f')
		return (output->default_length + output->prefix_size);
	return (output->default_length);
}

int	get_output_string_length(t_output *output, t_token *token)
{
	if (token->width > output->adjusted_length)
		return (token->width);
	else
		return (output->adjusted_length);
}

int	get_insertion_index(t_output *output, t_token *token)
{
	if (token->minus)
		return (output->prefix_size);
	else if (output->output_length - output->default_length >= 0)
		return (output->output_length - output->default_length);
	else
		return (0);
}

int	get_prefix_index(t_output *output, t_token *token)
{
	if (token->minus)
		return (0);
	else if (token->zero)
		return (0);
	else
		return (output->insertion_index - output->prefix_size);
}

int	print_token_input(t_token *token, void *input)
{
	t_output	*output;
	int			length;

	output = get_output_item(token, input);
	if (token->minus)
		pad_string(output->output, output->padding_char,
		output->insertion_index + output->default_length,
		output->output_length - output->adjusted_length);
	else
		pad_string(output->output, output->padding_char,
		0, output->insertion_index);
	fill_string(output->output, output->result, output->insertion_index);
	fill_string(output->output, output->prefix, output->prefix_index);
	write(1, (unsigned char *)output->output, output->output_length);
	length = output->output_length;
	destroy_output(&output);
	return (length);
}
