/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_yeah.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:08:25 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/10 15:31:03 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

t_token		*string_to_token(char *str)
{
	int			j;
	int			leftover_size;
	char		*save;
	t_token		*new_token;

	new_token = mallokill(sizeof(t_token));
	get_token_fields(new_token, str);
	j = 1;
	process_token(new_token, str, &j);
	leftover_size = ft_strlen(str) - j - 1;
	if (leftover_size > 0 && new_token->type != '%')
	{
		save = new_token->length_string;
		new_token->length_string = ft_strsub(str, j, leftover_size);
		free(save);
	}
	refine_token(new_token);
	settle_token(new_token);
	return (new_token);
}

void		process_token(struct s_token *new_token, char *str, int *j)
{
	char *save;
	char *sub_string;

	while (why_get_index(FLAGS, str[*j]) != -1)
		process_flags(new_token, str, j);
	while (ft_isdigit((char)str[*j]))
		process_width(new_token, str, j);
	if (str[*j] == '.')
	{
		save = new_token->precision_string;
		new_token->precision_string = ft_strdup(".");
		free(save);
		*j = *j + 1;
		while (ft_isdigit((char)str[*j]))
		{
			save = new_token->precision_string;
			sub_string = ft_strsub(str, *j, 1);
			new_token->precision_string =
			ft_strjoin(new_token->precision_string, sub_string);
			free(save);
			free(sub_string);
			*j = *j + 1;
		}
	}
}

void		get_token_flags(t_token *token)
{
	token->hash = (ft_strchr(token->flag_string, '#') ? 1 : 0);
	token->zero = (ft_strchr(token->flag_string, '0') ? 1 : 0);
	token->minus = (ft_strchr(token->flag_string, '-') ? 1 : 0);
	token->plus = (ft_strchr(token->flag_string, '+') ? 1 : 0);
	token->space = (ft_strchr(token->flag_string, ' ') ? 1 : 0);
	token->ll = (ft_strstr(token->length_string, "ll") ? 1 : 0);
	token->l = ((ft_strchr(token->length_string, 'l') && !token->ll) ? 1 : 0);
	token->hh = (ft_strstr(token->length_string, "hh") ? 1 : 0);
	token->h = ((ft_strchr(token->length_string, 'h') && !token->hh) ? 1 : 0);
	token->big_l = (ft_strchr(token->length_string, 'L') ? 1 : 0);
}

void		destroy_token(t_token **token)
{
	free((*token)->token);
	free((*token)->width_string);
	free((*token)->length_string);
	free((*token)->precision_string);
	free((*token)->flag_string);
	free(*token);
	*token = NULL;
}
