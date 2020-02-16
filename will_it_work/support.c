/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:00:43 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/16 14:21:39 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

void	print_initial_text(char **initial_text)
{
	int j;

	j = -1;
	while (initial_text[++j])
	{
		write(1, initial_text[j], ft_strlen(initial_text[j]));
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

void	block_pivots(t_generic_list *pivot_nodes, long block)
{
	t_generic_list *current_node;

	current_node = pivot_nodes;
	while (current_node != NULL)
	{
		((t_node *)current_node->stuff)->ant = (void *)block;
		current_node = current_node->next;
	}
}

int		estimate_run_time(t_path_list *paths)
{
	t_path_list	*current_path;
	int			max_effective_length;
	int			current_effective_length;

	if (!paths)
		return (0);
	current_path = paths;
	max_effective_length =
	current_path->path->length + current_path->path->number_of_ants - 2;
	while (current_path)
	{
		if (current_path->path->number_of_ants == 0)
		{
			current_path = current_path->next;
			continue ;
		}
		current_effective_length =
		current_path->path->length + current_path->path->number_of_ants - 2;
		if (current_effective_length > max_effective_length)
			max_effective_length = current_effective_length;
		current_path = current_path->next;
	}
	return (max_effective_length);
}

int		collect_garbage(t_lemin lemin, t_colony *colony)
{
	free_for_all(&lemin);
	destroy_path_list(&colony->optimal_flow, 1);
	destroy_path_list(&colony->current_flow, 1);
	destroy_generic_list(&colony->active_pivots);
	destroy_generic_list(&colony->pivot_nodes);
	reset_flow_network(colony);
	reset_residual_network(colony);
	kill_all_ants(colony);
	free(colony->ants);
	destroy_all_nodes(colony);
	free(colony->nodes);
	free(colony);
	return (0);
}

void	go_forth(t_colony *colony)
{
	t_generic_list	*current_ant;
	t_path_list		*current_path;

	while (colony->finish->number_of_ants < colony->number_of_ants)
	{
		current_path = colony->optimal_flow;
		while (current_path)
		{
			current_ant = current_path->path->ants;
			while (current_ant)
			{
				if (((t_ant *)current_ant->stuff)->current_node->class ==
				finish)
				{
					current_ant = current_ant->next;
					continue ;
				}
				move((t_ant *)current_ant->stuff);
				current_ant = current_ant->next;
			}
			current_path = current_path->next;
		}
		write(1, "\n", 1);
	}
}
