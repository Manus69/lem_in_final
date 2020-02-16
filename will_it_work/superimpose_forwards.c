/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superimpose_forwards.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:09:17 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 21:09:28 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

static void	connect_flow_forwards(t_node_stack_item *current_node,
			t_node_stack_item *next_node)
{
	t_node_stack_item *new_node;

	new_node = new_node_stack_item(next_node->node);
	current_node->node->flow = push(current_node->node->flow, new_node);
}

static void	process_path_before_intersection(t_colony *colony,
			t_node_stack_item *next_node)
{
	t_path_list *the_right_path;

	the_right_path = get_the_right_path(next_node->node, colony->current_flow);
	if (the_right_path)
	{
		undo_flow_on_segment(the_right_path->path, next_node->node);
		plug_the_path(the_right_path->path, 0);
		the_right_path = remove_path_from_list(&colony->current_flow,
		the_right_path->path);
		destroy_path_list(&the_right_path, 0);
	}
}

void		superimpose_mk2_forwards(t_colony *colony, t_path *path)
{
	t_node_stack_item	*current_node;
	t_node_stack_item	*next_node;

	current_node = path->route->tail;
	while (current_node != path->route->head)
	{
		if (current_node->node->class == finish)
			break ;
		next_node = current_node->left;
		if (next_node->node->ant)
		{
			process_path_before_intersection(colony, next_node);
			connect_flow_forwards(current_node, next_node);
			process_pivots(colony, next_node);
			return ;
		}
		connect_flow_forwards(current_node, next_node);
		current_node = current_node->left;
	}
}
