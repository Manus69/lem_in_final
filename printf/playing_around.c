/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing_around.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:14:50 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/11 12:33:54 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

char			*get_sub_string(char *str, int *s_index,
int *p_index, int *start)
{
	char *sub_string;
	char *save;

	sub_string = ft_strsub(str, *p_index, *s_index - *p_index + 1);
	if (sub_string[ft_strlen(sub_string) - 1] == '%')
	{
		*start = *s_index;
		return (sub_string);
	}
	*p_index = why_get_last_index(sub_string, '%');
	*start = *s_index;
	save = sub_string;
	sub_string = ft_strsub(sub_string,
	*p_index, ft_strlen(sub_string) - *p_index);
	free(save);
	return (sub_string);
}

char			*get_next_token(char *str, char *set, int *start)
{
	int	p_index;
	int	s_index;

	p_index = index_of_any(str, "%", *start);
	while (p_index != -1)
	{
		if (str[p_index + 1] == '\0')
			return (NULL);
		if (str[p_index + 1] == '%')
		{
			p_index = index_of_any(str, "%", p_index + 2);
			continue;
		}
		s_index = index_of_any(str, set, p_index + 1);
		if (s_index != -1)
			return (get_sub_string(str, &s_index, &p_index, start));
		else
			return (NULL);
	}
	return (NULL);
}

int				count_and_destroy_mk2(t_jcount_tuple **tuple,
va_list *argument_list)
{
	int count;

	count = (*tuple)->count;
	free(*tuple);
	*tuple = NULL;
	va_end(*argument_list);
	return (count);
}

int				ft_printf(const char *format, ...)
{
	va_list			argument_list;
	char			*string_token;
	t_token			*token;
	union u_data	*data;
	t_jcount_tuple	*tuple;

	tuple = get_tuple_and_check(format);
	va_start(argument_list, format);
	while (format[tuple->j] != '\0')
	{
		if (create_confusion(&(tuple->j), &(tuple->count), format))
			continue;
		string_token = get_next_token((char *)format, TYPES, &(tuple->j));
		if (string_token)
		{
			token = string_to_token(string_token);
			data = get_data(token, &argument_list);
			tuple->count += print_token_input(token, get_pointer(data, token));
			free(data);
			destroy_token(&token);
			free(string_token);
		}
		tuple->j = tuple->j + 1;
	}
	return (count_and_destroy_mk2(&tuple, &argument_list));
}
