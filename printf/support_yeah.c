/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_yeah.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:44:38 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/10 16:06:18 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

int		index_of_any(char *str, char *set, int start)
{
	int	j;

	j = 0;
	while (str[start + j] != '\0')
	{
		if (why_get_index(set, str[start + j]) != -1)
			return (start + j);
		j = j + 1;
	}
	return (-1);
}

int		why_get_last_index(char *str, char c)
{
	int	index;
	int	j;

	index = -1;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == c)
			index = j;
		j = j + 1;
	}
	return (index);
}

void	str_capitalize(char *str)
{
	int j;

	j = 0;
	while (str[j] != '\0')
	{
		if (ft_isalpha(str[j]))
			str[j] = str[j] + ('A' - 'a');
		j = j + 1;
	}
}

char	*get_str_of_something(int length, char c)
{
	char	*str;
	int		j;

	str = mallokill(sizeof(char) * (length + 1));
	j = 0;
	while (j < length)
	{
		str[j] = c;
		j = j + 1;
	}
	str[j] = '\0';
	return (str);
}

void	fill_string(char *string, char *sub_string, int j)
{
	int k;

	k = 0;
	while (sub_string[k] != '\0')
	{
		string[j + k] = sub_string[k];
		k = k + 1;
	}
}
