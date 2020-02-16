/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:45:12 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/09 13:38:21 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if ((char)c == '\0')
		return ((char *)str + (int)ft_strlen(str));
	while ((int)*str != c && *str != '\0')
	{
		str = str + 1;
	}
	if (*str == '\0')
		return (NULL);
	return ((char *)str);
}
