/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plug.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:46:56 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 20:47:17 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

void				plug_the_path(t_path *path, int plug)
{
	t_node_stack_item *current_node;

	current_node = path->route->tail->left;
	while (current_node != path->route->head)
	{
		if (plug)
			current_node->node->ant = (void *)1;
		else if (!plug)
			current_node->node->ant = NULL;
		current_node = current_node->left;
	}
}

void				unplug_all_paths(t_path_list *paths)
{
	t_path_list *current_path;

	current_path = paths;
	while (current_path)
	{
		plug_the_path(current_path->path, 0);
		current_path = current_path->next;
	}
}

void				plug_all_paths(t_path_list *paths)
{
	t_path_list *current_path;

	current_path = paths;
	while (current_path)
	{
		plug_the_path(current_path->path, 1);
		current_path = current_path->next;
	}
}
