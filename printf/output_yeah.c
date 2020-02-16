/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_yeah.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:28:39 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/10 20:05:20 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

char	get_padding_char(t_output *output, t_token *token)
{
	if (token->zero)
		return ('0');
	if (why_get_index("ouxX", token->type) != -1)
		if (token->precision >= output->adjusted_length)
			return ('0');
	return (' ');
}

char	*process_hash(t_output *output, t_token *token)
{
	if (token->type == 'x' && (ft_strcmp(output->result, "0") != 0))
		return (ft_strdup("0x"));
	else if (token->type == 'X' && (ft_strcmp(output->result, "0") != 0))
		return (ft_strdup("0X"));
	else if (token->type == 'o')
	{
		if ((ft_strcmp(output->result, "0") == 0) && (token->precision == 0))
			return (ft_strdup("0"));
		else if (ft_strcmp(output->result, "0") == 0)
			return (ft_strdup(""));
		if (token->precision <= (int)ft_strlen(output->result))
			return (ft_strdup("0"));
	}
	return (NULL);
}

char	*get_prefix(t_output *output, t_token *token)
{
	char *save;

	if (token->type == 'p')
		return (ft_strdup("0x"));
	if (token->hash && (save = process_hash(output, token)))
		return (save);
	if (token->plus)
		if ((token->type == 'd' || token->type == 'i' || token->type == 'f')
		&& (output->result[0] != '-'))
			return (ft_strdup("+"));
	if (token->type == 'd' || token->type == 'i' || token->type == 'f')
	{
		if (output->result[0] == '-')
		{
			save = output->result;
			output->result = ft_strsub(output->result,
			1, ft_strlen(output->result) - 1);
			free(save);
			return (ft_strdup("-"));
		}
		if (token->space)
			return (ft_strdup(" "));
	}
	return (ft_strdup(""));
}

char	*get_default_token_representaion(t_output *output,
t_token *token, void *input)
{
	char *result;

	if (token->type == 'p')
		result = why_integer_to_ascii((unsigned long)input, 16);
	else if (token->type == 'c')
	{
		if (!input)
			return (ft_strdup(""));
		if (*(char *)input == '\0')
			output->default_length = 1;
		result = ft_strnew(1);
		result[0] = *(unsigned char *)input;
	}
	else
		result = process_token_types(token, input);
	return (result);
}
