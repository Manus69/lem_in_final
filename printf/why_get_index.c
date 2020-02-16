/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   why_get_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <bfskinner60659@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:53:04 by lcaesar           #+#    #+#             */
/*   Updated: 2019/09/30 11:55:45 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	why_get_index(char *string, char c)
{
	int j;

	j = 0;
	while (string[j] != '\0')
	{
		if (string[j] == c)
			return (j);
		j = j + 1;
	}
	return (-1);
}
