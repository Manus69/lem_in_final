/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:21:11 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/11 13:16:18 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	start = result;
	while (*s1 != '\0')
	{
		*result = *s1;
		result = result + 1;
		s1 = s1 + 1;
	}
	while (*s2 != '\0')
	{
		*result = *s2;
		result = result + 1;
		s2 = s2 + 1;
	}
	*result = '\0';
	return (start);
}
