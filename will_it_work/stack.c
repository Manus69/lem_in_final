/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:53:58 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 20:57:34 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

t_stack						*new_stack(t_node_stack_item *head,
							t_node_stack_item *tail, int number_of_items)
{
	t_stack *stack;

	stack = mallokill(sizeof(struct s_stack));
	stack->head = head;
	stack->tail = tail;
	if (head && tail)
	{
		stack->tail->right = stack->head;
		stack->head->left = stack->tail;
	}
	if (tail->left == NULL)
		stack->tail->left = stack->head;
	if (head->right == NULL)
		stack->head->right = stack->tail;
	stack->number_of_items = number_of_items;
	return (stack);
}

t_stack						*push(t_stack *stack, t_node_stack_item *item)
{
	if (!stack)
		return (new_stack(item, item, 1));
	if (stack->head && stack->tail)
	{
		item->left = stack->tail;
		item->right = stack->head;
		stack->tail->right = item;
		stack->head->left = item;
		stack->tail = item;
	}
	else
	{
		stack->head = item;
		stack->tail = item;
		stack->tail->right = stack->head;
		stack->tail->left = stack->head;
		stack->head->left = stack->tail;
		stack->head->right = stack->tail;
	}
	stack->number_of_items = stack->number_of_items + 1;
	return (stack);
}

t_stack						*queue(t_stack *stack, t_node_stack_item *item)
{
	if (!stack && item)
		return (new_stack(item, item, 1));
	if (!item)
		return (stack);
	stack->head->left = item;
	item->right = stack->head;
	stack->tail->right = item;
	item->left = stack->tail;
	stack->head = item;
	stack->number_of_items = stack->number_of_items + 1;
	return (stack);
}

t_node_stack_item			*pop(t_stack *stack)
{
	t_node_stack_item *node_stack_item;

	if (!stack || (!stack->head && !stack->tail))
		return (NULL);
	if (stack->head == stack->tail)
	{
		node_stack_item = stack->head;
		node_stack_item->left = NULL;
		node_stack_item->right = NULL;
		stack->head = NULL;
		stack->tail = NULL;
		stack->number_of_items = 0;
		return (node_stack_item);
	}
	node_stack_item = stack->tail;
	stack->head->left = stack->tail->left;
	stack->tail->left->right = stack->head;
	stack->tail = stack->tail->left;
	node_stack_item->left = NULL;
	node_stack_item->right = NULL;
	stack->number_of_items = stack->number_of_items - 1;
	return (node_stack_item);
}

t_node_stack_item			*get_nth_element(t_stack *stack, int n)
{
	t_node_stack_item *node_stack_item;

	if (n >= stack->number_of_items)
		return (NULL);
	node_stack_item = stack->head;
	while (n > 0)
	{
		node_stack_item = node_stack_item->right;
		n = n - 1;
	}
	return (node_stack_item);
}
