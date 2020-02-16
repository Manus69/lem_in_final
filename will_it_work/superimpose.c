/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superimpose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:09:40 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 20:22:59 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

static void	connect_flow(t_node_stack_item *current_node,
				t_node_stack_item *next_node)
{
	t_node_stack_item *new_node;

	new_node = new_node_stack_item(next_node->node);
	current_node->node->flow = push(current_node->node->flow, new_node);
}

static void	process_edge(t_node_stack_item *current_node,
				t_node_stack_item *next_node)
{
	t_node_stack_item	*the_right_edge;

	the_right_edge = find_the_right_edge(next_node->node->flow,
	current_node->node);
	remove_arbitrary_element(next_node->node->flow, the_right_edge);
	free(the_right_edge);
}

static void	do_stuff(t_colony *colony, t_node_stack_item *next_node)
{
	t_path_list *the_right_path;

	the_right_path = get_the_right_path(next_node->node, colony->current_flow);
	if (the_right_path)
	{
		plug_the_path(the_right_path->path, 0);
		undo_flow_on_segment(the_right_path->path, next_node->node);
		the_right_path =
		remove_path_from_list(&colony->current_flow, the_right_path->path);
		destroy_path_list(&the_right_path, 0);
	}
}

static void	pointless_function(t_colony *colony, t_node_pair *pair)
{
	do_stuff(colony, pair->next);
	process_pivots(colony, pair->next);
}

void		superimpose(t_colony *colony, t_path *path, int pivoting)
{
	t_node_pair	pair;

	pair.current = path->route->tail;
	while (pair.current != path->route->head)
	{
		if (pair.current->node->class == finish)
			return ;
		pair.next = pair.current->left;
		if (!pair.next->node->flow ||
		pair.next->node->flow->number_of_items == 0)
			connect_flow(pair.current, pair.next);
		else if (pair.next->node->flow->tail->node ==
		pair.current->node)
			process_edge(pair.current, pair.next);
		else if (pair.next->node->flow->number_of_items != 0 && pivoting)
		{
			connect_flow(pair.current, pair.next);
			if (!pair.next->left->node->flow ||\
			!find_the_right_edge(pair.next->left->node->flow, pair.next->node))
				return (pointless_function(colony, &pair));
		}
		else
			connect_flow(pair.current, pair.next);
		pair.current = pair.current->left;
	}
}
