/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_damn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:25:42 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/10 19:26:35 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

char	*get_unsigned_number_representation(t_token *token,
		void *input, int base)
{
	char *result;

	if (token->h)
		result = unsigned_integer_to_ascii(*(unsigned short int *)input, base);
	else if (token->hh)
		result = unsigned_integer_to_ascii(*(unsigned short int *)input, base);
	else if (token->l)
		result = unsigned_integer_to_ascii(*(unsigned long *)input, base);
	else if (!(token->ll))
		result = unsigned_integer_to_ascii(*(unsigned int *)input, base);
	else
		result = unsigned_integer_to_ascii(*(unsigned long long *)input, base);
	return (result);
}

char	*get_percent_token_representation(t_token *token)
{
	char	*result;
	int		offset;

	offset = 0;
	if (ft_strlen(token->token) >= 1 && token->token[0] == '%')
		token->token = ft_strsub(token->token, 1, ft_strlen(token->token) - 1);
	offset = ft_strlen(token->flag_string) + ft_strlen(token->width_string) +
	ft_strlen(token->precision_string);
	if (token->token[offset] != '\0')
		result = ft_strsub(token->token, offset,
		ft_strlen(token->token) - offset);
	else
		result = ft_strdup("%");
	return (result);
}

char	*get_di_token_representation(t_token *token, void *input)
{
	char *result;

	if (token->h)
		result = why_integer_to_ascii(*(short int *)input, 10);
	else if (token->hh)
		result = why_integer_to_ascii(*(char *)input, 10);
	else if (token->l)
		result = why_integer_to_ascii(*(long int *)input, 10);
	else if (!(token->ll))
		result = why_integer_to_ascii(*(int *)input, 10);
	else
		result = why_integer_to_ascii(*(long long *)input, 10);
	return (result);
}

char	*get_f_token_representation(t_token *token, void *input)
{
	char *save;
	char *result;

	if (token->big_l)
		result = real_to_ascii_mk3(*(long double *)input, token->precision);
	else
		result = real_to_ascii_mk3(*(double *)input, token->precision);
	if (token->hash && token->precision == 0)
	{
		save = result;
		result = ft_strjoin(result, ".");
		free(save);
	}
	return (result);
}

char	*get_s_token_representation(t_token *token, void *input)
{
	char *result;

	if (!input)
		input = "(null)";
	if (token->precision >= 0 &&
	token->precision <= (int)ft_strlen((char *)input))
		result = ft_strsub((char *)input, 0, token->precision);
	else
		result = ft_strdup((char *)input);
	return (result);
}
