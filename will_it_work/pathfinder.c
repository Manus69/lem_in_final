/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:40:02 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/16 14:18:10 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

t_stack			*queue_nodes_set_parent(t_stack *target_stack,
				t_stack *source_stack, t_node *discovered_via, t_node *finish)
{
	t_node_stack_item	*node;
	int					n;

	if (!source_stack || source_stack->number_of_items == 0)
		return (target_stack);
	n = 0;
	while (n < source_stack->number_of_items)
	{
		node = get_nth_element(source_stack, n);
		if (node->node->ant && (node->node != finish))
		{
			n = n + 1;
			continue ;
		}
		if ((node->node->visited == 0) && (node->node->discovered == 0))
		{
			target_stack = queue(target_stack,
			new_node_stack_item(node->node));
			target_stack->head->node->discovered = 1;
			target_stack->head->node->discovered_via = discovered_via;
		}
		n = n + 1;
	}
	return (target_stack);
}

void			bfs_visit(t_node *node,
				t_stack *node_queue, t_node *finish, int network_flag)
{
	if (node->visited)
		return ;
	if (node->ant && (node != finish))
		return ;
	node->visited = 1;
	if (network_flag == 0)
		node_queue = queue_nodes_set_parent(node_queue,
		node->adjacent_nodes, node, finish);
	else if (network_flag == 1)
		node_queue = queue_nodes_set_parent(node_queue,
		node->flow, node, finish);
	else
		node_queue = queue_nodes_set_parent(node_queue,
		node->residual_nodes, node, finish);
}

static t_stack	*get_item_queue(t_node *start,
				t_node *finish, int network_flag)
{
	t_stack *node_item_queue;

	node_item_queue = NULL;
	if (network_flag == 0)
		node_item_queue = queue_nodes_set_parent(node_item_queue,
		start->adjacent_nodes, start, finish);
	else if (network_flag == 1)
		node_item_queue = queue_nodes_set_parent(node_item_queue,
		start->flow, start, finish);
	else
		node_item_queue = queue_nodes_set_parent(node_item_queue,
		start->residual_nodes, start, finish);
	return (node_item_queue);
}

static void		useless_function(t_stack *node_item_queue,
				t_node *next_node, t_node *finish, int network_flag)
{
	bfs_visit(next_node, node_item_queue, finish, network_flag);
	free(pop(node_item_queue));
}

t_stack			*naive_bfs(t_node *start, t_node *finish, int network_flag)
{
	t_stack				*node_item_queue;
	t_node				*next_node;
	int					path_found;

	if (start == finish)
		return (NULL);
	start->visited = 1;
	node_item_queue = get_item_queue(start, finish, network_flag);
	path_found = 0;
	while (node_item_queue && node_item_queue->number_of_items)
	{
		next_node = node_item_queue->tail->node;
		if (next_node == finish)
		{
			bfs_visit(next_node, node_item_queue, finish, network_flag);
			path_found = 1;
			break ;
		}
		else
			useless_function(node_item_queue, next_node, finish, network_flag);
	}
	destroy_stack(&node_item_queue);
	if (path_found)
		return (backtrack(finish, start));
	return (NULL);
}
