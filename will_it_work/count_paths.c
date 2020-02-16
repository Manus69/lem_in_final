/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:31:45 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 18:32:22 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

int				count_paths(t_path_list *paths)
{
	int			n;
	t_path_list	*current_path;

	current_path = paths;
	n = 0;
	while (current_path)
	{
		current_path = current_path->next;
		n = n + 1;
	}
	return (n);
}

int				count_non_empty_paths(t_path_list *paths)
{
	int			n;
	t_path_list	*current_path;

	current_path = paths;
	n = 0;
	while (current_path)
	{
		if (current_path->path->number_of_ants)
			n = n + 1;
		current_path = current_path->next;
	}
	return (n);
}
