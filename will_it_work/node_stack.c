/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:56:56 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 20:59:55 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

t_node_stack_item	*process_stack_head(t_stack *stack,
							t_node_stack_item *node, t_node_stack_item *next)
{
	next = stack->head->right;
	stack->tail->right = next;
	next->left = stack->tail;
	stack->head = next;
	node->left = NULL;
	node->right = NULL;
	stack->number_of_items = stack->number_of_items - 1;
	return (node);
}

t_node_stack_item	*remove_arbitrary_element(t_stack *stack,
					t_node_stack_item *node)
{
	t_node_stack_item *previous;
	t_node_stack_item *next;

	if (!stack || !node)
		return (NULL);
	next = NULL;
	if (node == stack->head && node == stack->tail)
		return (pop(stack));
	if (node == stack->tail)
		return (pop(stack));
	if (node == stack->head)
		return (process_stack_head(stack, node, next));
	previous = node->left;
	next = node->right;
	previous->right = next;
	next->left = previous;
	node->left = NULL;
	node->right = NULL;
	stack->number_of_items = stack->number_of_items - 1;
	return (node);
}

t_node_stack_item	*find_the_right_edge(t_stack *edges, t_node *node)
{
	t_node_stack_item	*current;
	int					n;

	n = 0;
	current = edges->tail;
	while (n < edges->number_of_items)
	{
		if (current->node == node)
			return (current);
		current = current->left;
		n = n + 1;
	}
	return (NULL);
}
