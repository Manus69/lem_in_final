/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waste_of_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:03:25 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 21:04:39 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

void		process_pivots(t_colony *colony, t_node_stack_item *next_node)
{
	if (!is_on_the_list(colony->pivot_nodes, (void *)next_node->node))
		colony->pivot_nodes =
		add(colony->pivot_nodes, (void *)next_node->node);
	else
	{
		colony->active_pivots =
		add(colony->active_pivots, (void *)next_node->node);
		return ;
	}
	block_pivots(colony->active_pivots, 0);
	destroy_generic_list(&colony->active_pivots);
	colony->active_pivots = new_generic_list((void *)next_node->node);
}

t_stack		*backtrack(t_node *finish, t_node *start)
{
	t_stack				*path;
	t_node				*current_node;
	t_node_stack_item	*node_stack_item;

	node_stack_item = new_node_stack_item(finish);
	path = new_stack(node_stack_item, node_stack_item, 1);
	current_node = finish->discovered_via;
	while (current_node != start)
	{
		if (!current_node)
			break ;
		path = push(path, new_node_stack_item(current_node));
		current_node = current_node->discovered_via;
	}
	if (start != finish)
		path = push(path, new_node_stack_item(start));
	return (path);
}
