/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:52:03 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/11 10:11:58 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub_string;
	unsigned int	j;

	if (!s)
		return (NULL);
	sub_string = (char *)malloc(sizeof(char) * len + 1);
	if (!sub_string)
		return (NULL);
	j = 0;
	while (j < (unsigned int)len)
	{
		sub_string[j] = *(s + start + j);
		j = j + 1;
	}
	sub_string[j] = '\0';
	return (sub_string);
}
