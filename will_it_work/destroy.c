/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:32:53 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 18:36:17 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

void	destroy_stack(t_stack **stack)
{
	t_node_stack_item *current_node_stack_item;
	t_node_stack_item *next_node_stack_item;

	if (!(*stack))
		return ;
	if ((*stack)->tail)
	{
		current_node_stack_item = (*stack)->tail;
		while ((*stack)->number_of_items)
		{
			next_node_stack_item = current_node_stack_item->left;
			free(current_node_stack_item);
			(*stack)->number_of_items = (*stack)->number_of_items - 1;
			current_node_stack_item = next_node_stack_item;
		}
	}
	free(*stack);
	*stack = NULL;
}

void	destroy_path(t_path **path)
{
	destroy_stack(&(*path)->route);
	destroy_generic_list(&(*path)->ants);
	free(*path);
	*path = NULL;
}

void	destroy_path_list(t_path_list **path_list, int kill_ants)
{
	t_path_list **current;
	t_path_list *next;

	if (!path_list || !*path_list)
		return ;
	current = path_list;
	while (*current)
	{
		next = (*current)->next;
		if (kill_ants)
		{
			destroy_generic_list(&(*current)->path->ants);
		}
		destroy_path(&(*current)->path);
		free(*current);
		*current = NULL;
		*current = next;
	}
}

void	kill_all_ants(t_colony *colony)
{
	int		n;
	t_ant	**current_ant;

	n = 0;
	while (colony->ants[n])
	{
		current_ant = &(colony->ants[n]);
		free(*current_ant);
		*current_ant = NULL;
		n = n + 1;
	}
	current_ant = &(colony->ants[n]);
	free(*current_ant);
	*current_ant = NULL;
}

void	destroy_all_nodes(t_colony *colony)
{
	int n;

	n = 0;
	while (colony->nodes[n])
	{
		destroy_stack(&colony->nodes[n]->adjacent_nodes);
		destroy_stack(&colony->nodes[n]->flow);
		destroy_stack(&colony->nodes[n]->residual_nodes);
		free(colony->nodes[n]);
		n = n + 1;
	}
	free(colony->nodes[n]);
}
