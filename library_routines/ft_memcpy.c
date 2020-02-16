/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:19:13 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/13 16:47:03 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int j;

	if (!dst && !src)
		return (NULL);
	j = 0;
	while (j < (int)n)
	{
		*((unsigned char *)dst + j) = *((unsigned char *)src + j);
		j = j + 1;
	}
	return (dst);
}
