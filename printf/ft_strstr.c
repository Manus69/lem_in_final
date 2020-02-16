/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:28:07 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/10 14:41:58 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int j;
	int k;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	j = 0;
	while (haystack[j] != '\0')
	{
		k = 0;
		while (haystack[j + k] == needle[k]
				&& haystack[j + k] != '\0' && needle[k] != '\0')
			k = k + 1;
		if (needle[k] == '\0')
			return ((char *)&(haystack[j]));
		j = j + 1;
	}
	return (NULL);
}
