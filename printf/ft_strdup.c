/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:35:28 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/09 11:37:58 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*result;
	int		j;

	result = (char *)malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (j < (int)ft_strlen(str))
	{
		result[j] = str[j];
		j = j + 1;
	}
	result[j] = '\0';
	return (result);
}
