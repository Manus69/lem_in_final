/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:21:41 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 19:21:48 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

t_node				*new_node_item(int index, char *name)
{
	t_node *node;

	node = mallokill(sizeof(struct s_node));
	node->index = index;
	node->number_of_ants = 0;
	node->name = name;
	node->ant = NULL;
	node->class = regular;
	node->visited = 0;
	node->discovered = 0;
	node->used = 0;
	node->discovered_via = NULL;
	node->x = -1;
	node->y = -1;
	node->adjacent_nodes = NULL;
	node->flow = NULL;
	node->residual_nodes = NULL;
	return (node);
}

t_node_stack_item	*new_node_stack_item(t_node *node)
{
	t_node_stack_item *node_stack_item;

	node_stack_item = mallokill(sizeof(struct s_node_stack_item));
	node_stack_item->node = node;
	node_stack_item->left = NULL;
	node_stack_item->right = NULL;
	return (node_stack_item);
}
