/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:15:23 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/10 15:25:43 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

void	refine_token(t_token *token)
{
	char *sub_string;

	get_token_flags(token);
	if (ft_strlen(token->width_string) != 0)
		token->width = (ft_atoi(token->width_string));
	else
		token->width = -1;
	if (ft_strlen(token->precision_string) != 0)
	{
		sub_string = ft_strsub(token->precision_string,
		1, ft_strlen(token->precision_string) - 1);
		token->precision = (ft_atoi(sub_string));
		free(sub_string);
	}
	else
		token->precision = -1;
}

void	settle_token(t_token *token)
{
	if (token->zero && token->minus)
		token->zero = 0;
	if (token->space && token->plus)
		token->space = 0;
	if (token->precision_string[0] == '.' && token->zero && token->type != 'f')
		token->zero = 0;
	if (token->type == 'f')
	{
		if (token->precision < 0)
			token->precision = 6;
	}
}

void	get_token_fields(struct s_token *token, char *str)
{
	token->token = ft_strdup(str);
	token->type = str[ft_strlen(str) - 1];
	if (token->type == ' ')
		token->type = '%';
	token->flag_string = ft_strnew(0);
	token->width_string = ft_strnew(0);
	token->precision_string = ft_strnew(0);
	token->length_string = ft_strnew(0);
}

void	process_flags(struct s_token *new_token, char *str, int *j)
{
	char *save;
	char *sub_string;

	save = new_token->flag_string;
	sub_string = ft_strsub(str, *j, 1);
	new_token->flag_string = ft_strjoin(new_token->flag_string, sub_string);
	free(save);
	free(sub_string);
	*j = *j + 1;
}

void	process_width(struct s_token *new_token, char *str, int *j)
{
	char *save;
	char *sub_string;

	save = new_token->width_string;
	sub_string = ft_strsub(str, *j, 1);
	new_token->width_string = ft_strjoin(new_token->width_string, sub_string);
	free(save);
	free(sub_string);
	*j = *j + 1;
}
