/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:31:13 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 18:31:14 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

t_stack			*copy_route(t_stack *old_route)
{
	t_node_stack_item	*current_node_stack_item;
	t_stack				*resulting_stack;
	t_node_stack_item	*new_item;

	current_node_stack_item = old_route->tail;
	new_item = new_node_stack_item(current_node_stack_item->node);
	resulting_stack = new_stack(new_item, new_item, 1);
	current_node_stack_item = current_node_stack_item->left;
	while (resulting_stack->number_of_items < old_route->number_of_items)
	{
		new_item = new_node_stack_item(current_node_stack_item->node);
		resulting_stack = queue(resulting_stack, new_item);
		current_node_stack_item = current_node_stack_item->left;
	}
	return (resulting_stack);
}

t_path			*copy_path(t_path *source_path)
{
	t_path		*path;
	t_stack		*new_route;

	new_route = copy_route(source_path->route);
	path = new_path(new_route);
	path->length = source_path->length;
	return (path);
}

t_path_list		*copy_flow(t_path_list *current_flow)
{
	t_path_list		*current_path;
	t_path_list		*flow;
	t_path			*flow_path_copy;

	flow = NULL;
	current_path = current_flow;
	while (current_path)
	{
		flow_path_copy = copy_path(current_path->path);
		flow = queue_path(flow, flow_path_copy);
		current_path = current_path->next;
	}
	return (flow);
}
