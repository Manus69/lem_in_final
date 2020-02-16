/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:22:18 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 19:28:02 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"
#include "lemin.h"

t_path		*new_path(t_stack *route)
{
	t_path *path;

	if (!route)
		return (NULL);
	path = mallokill(sizeof(struct s_path));
	path->route = route;
	path->number_of_ants = 0;
	path->length = route->number_of_items;
	path->ants = NULL;
	return (path);
}

t_path_list	*new_path_list(t_path *path)
{
	t_path_list *path_list;

	path_list = mallokill(sizeof(struct s_path_list));
	path_list->path = path;
	path_list->next = NULL;
	return (path_list);
}

int			check_if_path_exists(t_path_list *path_list, t_path *path)
{
	t_path_list *current;

	current = path_list;
	while (current != NULL)
	{
		if (current->path == path)
			return (1);
		current = current->next;
	}
	return (0);
}

t_path_list	*queue_path(t_path_list *path_list, t_path *path)
{
	t_path_list *new_list_item;
	t_path_list *current_list_item;

	if (!path_list)
		return (new_path_list(path));
	if (check_if_path_exists(path_list, path))
		return (path_list);
	new_list_item = new_path_list(path);
	current_list_item = path_list;
	while (current_list_item->next != NULL)
	{
		current_list_item = current_list_item->next;
	}
	current_list_item->next = new_list_item;
	return (path_list);
}
