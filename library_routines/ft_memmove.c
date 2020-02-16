/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:16:42 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/13 16:52:15 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	buffer[len];

	if (len > 1000000)
		return (NULL);
	if (!dst && !src)
		return (NULL);
	ft_memcpy(buffer, src, len);
	ft_memcpy(dst, buffer, len);
	return (dst);
}
