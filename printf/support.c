/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:15:41 by lcaesar           #+#    #+#             */
/*   Updated: 2019/11/10 15:47:06 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "four_header.h"

void	pad_string(char *string, char c, int index, int size)
{
	int j;

	j = 0;
	while (j < size)
	{
		string[index + j] = c;
		j = j + 1;
	}
}

void	swap(char *str, int j, int k)
{
	char	store;

	store = str[j];
	str[j] = str[k];
	str[k] = store;
}

char	*reverse_string(char *str)
{
	int		length;
	int		mid_point;
	int		j;

	length = ft_strlen(str);
	mid_point = length / 2;
	j = 0;
	while (j < mid_point)
	{
		swap(str, j, length - j - 1);
		j = j + 1;
	}
	return (str);
}

void	*mallokill(size_t size)
{
	void *result;

	result = malloc(size);
	if (!result)
	{
		free(result);
		exit(1);
	}
	return (result);
}
