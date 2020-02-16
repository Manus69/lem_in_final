/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:26:55 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 20:44:34 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

t_path_list	*get_next_longest_path(t_path_list *path_list_item)
{
	t_path_list *next_longest_path;

	next_longest_path = path_list_item;
	while (next_longest_path != NULL)
	{
		if (next_longest_path->path->length > path_list_item->path->length)
			return (next_longest_path);
		next_longest_path = next_longest_path->next;
	}
	return (NULL);
}

int			check_if_node_is_on_the_path(t_node *node, t_path *path)
{
	t_node_stack_item *current_node;

	current_node = path->route->tail;
	while (current_node != path->route->head)
	{
		if (current_node->node == node)
			return (1);
		current_node = current_node->left;
	}
	return (0);
}

t_path_list	*get_the_right_path(t_node *node, t_path_list *paths)
{
	t_path_list *current_path;

	current_path = paths;
	while (current_path)
	{
		if (check_if_node_is_on_the_path(node, current_path->path))
			return (current_path);
		current_path = current_path->next;
	}
	return (NULL);
}

t_path_list	*do_whatever(t_path_list *current_path, t_path_list *next_path)
{
	t_path_list *the_right_path;

	next_path = current_path->next->next;
	the_right_path = current_path->next;
	current_path->next = next_path;
	the_right_path->next = NULL;
	return (the_right_path);
}

t_path_list	*remove_path_from_list(t_path_list **path_list, t_path *path)
{
	t_path_list *current_path;
	t_path_list *next_path;

	if (!*path_list || !path)
		return (NULL);
	current_path = *path_list;
	if ((*path_list)->path == path)
	{
		(*path_list) = (*path_list)->next;
		current_path->next = NULL;
		return (current_path);
	}
	next_path = NULL;
	while (current_path)
	{
		if (current_path->next->path == path)
			return (do_whatever(current_path, next_path));
		current_path = current_path->next;
	}
	return (NULL);
}
