/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:48:10 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 20:49:04 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

void		wipe_graph(t_node **nodes)
{
	int n;

	n = 0;
	while (nodes[n] != NULL)
	{
		nodes[n]->visited = 0;
		nodes[n]->discovered = 0;
		nodes[n]->discovered_via = NULL;
		n = n + 1;
	}
}

void		reset_paths(t_path_list *paths)
{
	t_path_list *current_path;

	current_path = paths;
	while (current_path)
	{
		current_path->path->number_of_ants = 0;
		current_path->path->ants = NULL;
		current_path = current_path->next;
	}
}

void		reset_residual_network(t_colony *colony)
{
	int n;

	n = 0;
	while (colony->nodes[n] != NULL)
	{
		if (colony->nodes[n]->residual_nodes != NULL)
			destroy_stack(&colony->nodes[n]->residual_nodes);
		n = n + 1;
	}
}

void		reset_flow_network(t_colony *colony)
{
	int n;

	n = 0;
	while (colony->nodes[n] != NULL)
	{
		if (colony->nodes[n]->flow != NULL)
			destroy_stack(&colony->nodes[n]->flow);
		n = n + 1;
	}
}

void		reset_everything(t_colony *colony)
{
	wipe_graph(colony->nodes);
	reset_residual_network(colony);
	initialize_residual_network(colony->nodes);
	generate_residual_network_for_flow(colony, colony->current_flow);
}
