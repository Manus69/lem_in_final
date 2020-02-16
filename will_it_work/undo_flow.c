/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo_flow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:02:24 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 21:04:51 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

void	undo_flow_on_segment(t_path *flow_path,
		t_node *final_node)
{
	t_node_stack_item	*current_node;
	t_node_stack_item	*the_right_edge;

	if (!flow_path)
		return ;
	current_node = flow_path->route->tail;
	while (current_node->node != final_node)
	{
		the_right_edge = find_the_right_edge(current_node->node->flow,
		current_node->left->node);
		remove_arbitrary_element(current_node->node->flow, the_right_edge);
		free(the_right_edge);
		current_node = current_node->left;
	}
}

void	undo_flow_on_segment_after_intersection(t_path *flow_path,
		t_node *intersection)
{
	t_node_stack_item	*current_node;
	t_node_stack_item	*the_right_edge;

	if (!flow_path)
		return ;
	current_node = flow_path->route->tail;
	while (current_node->node != intersection)
	{
		current_node = current_node->left;
	}
	while (current_node->node != flow_path->route->head->node)
	{
		the_right_edge = find_the_right_edge(current_node->node->flow,
		current_node->left->node);
		remove_arbitrary_element(current_node->node->flow, the_right_edge);
		free(the_right_edge);
		current_node = current_node->left;
	}
}
