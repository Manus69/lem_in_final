/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:39:28 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 18:41:31 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

void	distribute_ants_uniformly(t_colony *colony,
		t_path_list *path_list, int starting_index)
{
	t_path_list *current_path;

	while (starting_index < colony->number_of_ants)
	{
		current_path = path_list;
		if (!current_path)
			return ;
		while (current_path && (starting_index < colony->number_of_ants))
		{
			colony->ants[starting_index]->path = current_path->path;
			colony->ants[starting_index]->path_position =
			current_path->path->route->tail;
			current_path->path->ants = add(current_path->path->ants,
			(void *)colony->ants[starting_index]);
			current_path->path->number_of_ants += 1;
			starting_index += 1;
			current_path = current_path->next;
		}
	}
}

void	distribute_ants_uniformly_numerically(t_colony *colony,
t_path_list *path_list, int starting_index)
{
	t_path_list *current_path;

	while (starting_index < colony->number_of_ants)
	{
		current_path = path_list;
		if (!current_path)
			return ;
		while (current_path && (starting_index < colony->number_of_ants))
		{
			current_path->path->number_of_ants += 1;
			starting_index += 1;
			current_path = current_path->next;
		}
	}
}
