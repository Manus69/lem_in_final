/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:38:27 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 18:38:58 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

void	quick_stack_display(t_stack *stack)
{
	t_node_stack_item *current_node;

	if (!stack)
		ft_printf("null stack;\n");
	current_node = stack->tail;
	while (current_node != stack->head)
	{
		ft_printf("%s ", current_node->node->name);
		current_node = current_node->left;
	}
	ft_printf("%s\n", current_node->node->name);
}

void	display_all_paths(t_path_list *paths)
{
	t_path_list		*current_path;
	int				n;

	n = 1;
	current_path = paths;
	while (current_path)
	{
		ft_printf("Path %d of length %d:\n", n, current_path->path->length);
		quick_stack_display(current_path->path->route);
		current_path = current_path->next;
		n = n + 1;
	}
}
