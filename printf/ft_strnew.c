/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:39:26 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/14 17:22:06 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		j;
	char	*new_string;
	size_t	check;

	if (size == 0)
		return (ft_strdup(""));
	check = size + 1;
	if (check < size)
		return (NULL);
	new_string = (char *)malloc(sizeof(char) * (size + 1));
	if (!new_string)
		return (NULL);
	j = 0;
	while (j < (int)size)
	{
		new_string[j] = '\0';
		j = j + 1;
	}
	new_string[j] = '\0';
	return (new_string);
}
