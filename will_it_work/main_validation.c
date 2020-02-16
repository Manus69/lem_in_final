/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:01:39 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/16 14:00:53 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		err_out(void)
{
	ft_putstr_fd("ERROR\n", 2);
	return (0);
}

char	*feel_map_file(int ac, char **av, t_lemin *lemin)
{
	int i;

	i = 0;
	lemin->print_path = 0;
	while (++i < ac)
	{
		if (ft_strcmp("--path", av[i]))
			return (av[i]);
		lemin->print_path = 1;
	}
	return (NULL);
}
