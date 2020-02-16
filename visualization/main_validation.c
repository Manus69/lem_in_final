/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:25:39 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 17:33:55 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		err_out(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

void	free_hash_found(t_hash *hash_found)
{
	free((*hash_found).first_name);
	free((*hash_found).second_name);
}
