/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:44:44 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/06 10:44:38 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int j;

	j = 0;
	while (j < (int)ft_strlen(src))
	{
		dest[j] = src[j];
		j = j + 1;
	}
	dest[j] = '\0';
	return (dest);
}
