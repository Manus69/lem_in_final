/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:15:30 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/10 19:24:39 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

char		*process_token_types(t_token *token, void *input)
{
	char *result;

	if (token->type == 's')
		result = get_s_token_representation(token, input);
	else if (token->type == 'd' || token->type == 'i')
		result = get_di_token_representation(token, input);
	else if (token->type == 'x')
		result = get_unsigned_number_representation(token, input, 16);
	else if (token->type == 'X')
	{
		result = get_unsigned_number_representation(token, input, 16);
		str_capitalize(result);
	}
	else if (token->type == 'o')
		result = get_unsigned_number_representation(token, input, 8);
	else if (token->type == 'u')
		result = get_unsigned_number_representation(token, input, 10);
	else if (token->type == 'f')
		result = get_f_token_representation(token, input);
	else
		result = get_percent_token_representation(token);
	return (result);
}

void		check_precision(t_output *new_output, t_token *token)
{
	char		*save;
	char		*sub_string;

	if (token->precision > (int)ft_strlen(new_output->result))
	{
		save = new_output->result;
		sub_string = get_str_of_something(token->precision -
		ft_strlen(new_output->result), '0');
		new_output->result = ft_strjoin(sub_string, new_output->result);
		free(save);
		free(sub_string);
	}
}

void		check_something_else(t_output *new_output, t_token *token)
{
	char *save;

	if (token->precision <= 0 &&
	(why_get_index(token->precision_string, '.') != -1) && token->type != 'f')
	{
		save = new_output->result;
		new_output->result = ft_strdup("");
		free(save);
	}
}

t_output	*get_output_item(t_token *token, void *input)
{
	t_output	*new_output;

	new_output = mallokill(sizeof(t_output));
	new_output->default_length = 0;
	new_output->result =
	get_default_token_representaion(new_output, token, input);
	new_output->prefix = get_prefix(new_output, token);
	new_output->prefix_size = ft_strlen(new_output->prefix);
	if (why_get_index("diouxXp", token->type) != -1)
		check_precision(new_output, token);
	if (ft_strcmp(new_output->result, "0") == 0)
		check_something_else(new_output, token);
	new_output->default_length =
	new_output->default_length + ft_strlen(new_output->result);
	new_output->adjusted_length =
	get_adjusted_string_length(new_output, token);
	new_output->output_length = get_output_string_length(new_output, token);
	new_output->padding_char = ((token->zero) ? '0' : ' ');
	new_output->insertion_index = get_insertion_index(new_output, token);
	new_output->output = ft_strnew(new_output->output_length);
	new_output->prefix_index = get_prefix_index(new_output, token);
	return (new_output);
}

void		destroy_output(t_output **output)
{
	free((*output)->result);
	free((*output)->prefix);
	free((*output)->output);
	free(*output);
	*output = NULL;
}
