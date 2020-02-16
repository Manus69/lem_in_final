/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:28:04 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 19:28:05 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

int			get_distance_to_the_jam(t_path *path)
{
	int					distance;
	t_node_stack_item	*current;

	distance = 0;
	current = path->route->tail->left;
	while (current != path->route->head)
	{
		if (current->node->ant)
			return (distance);
		distance = distance + 1;
		current = current->left;
	}
	return (-1);
}

int			get_distance_from_the_jam(t_path *path)
{
	int					distance;
	t_node_stack_item	*current;

	distance = 0;
	current = path->route->head->right;
	while (current != path->route->tail)
	{
		if (current->node->ant)
			return (distance);
		distance = distance + 1;
		current = current->right;
	}
	return (-1);
}
