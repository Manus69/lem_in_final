/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:51:30 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 19:17:33 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

void				initialize_the_flow_netowrk(t_colony *colony,
					t_path_list *paths)
{
	t_node_stack_item	*current_node;
	t_node_stack_item	*flow_stack_item;
	t_path_list			*current_path;
	int					n;

	current_path = paths;
	while (current_path)
	{
		n = 0;
		current_node = current_path->path->route->tail;
		while (n < current_path->path->length)
		{
			flow_stack_item = new_node_stack_item(current_node->left->node);
			current_node->node->flow =
			queue(current_node->node->flow, flow_stack_item);
			current_node = current_node->left;
			n = n + 1;
		}
		current_path = current_path->next;
	}
	destroy_stack(&colony->finish->flow);
}

t_path_list			*get_flow_paths(t_colony *colony, int flow_flag)
{
	t_path_list		*path_list;
	t_path			*current_path;

	path_list = NULL;
	current_path =
	new_path(naive_bfs(colony->start, colony->finish, flow_flag));
	if (!current_path)
		return (NULL);
	while (current_path)
	{
		plug_the_path(current_path, 1);
		wipe_graph(colony->nodes);
		path_list = queue_path(path_list, current_path);
		current_path =
		new_path(naive_bfs(colony->start, colony->finish, flow_flag));
		if (current_path && (current_path->length > colony->min_running_time))
		{
			destroy_path(&current_path);
		}
	}
	wipe_graph(colony->nodes);
	return (path_list);
}

void				initialize_residual_network(t_node **nodes)
{
	int					n;
	int					m;
	t_stack				*residual_stack;
	t_node_stack_item	*current_node;

	n = 0;
	while (nodes[n] != NULL)
	{
		if (nodes[n]->adjacent_nodes == NULL)
		{
			n = n + 1;
			continue ;
		}
		m = -1;
		residual_stack = NULL;
		current_node = nodes[n]->adjacent_nodes->tail;
		while (++m < nodes[n]->adjacent_nodes->number_of_items)
		{
			residual_stack = push(residual_stack,
			new_node_stack_item(current_node->node));
			current_node = current_node->left;
		}
		nodes[n]->residual_nodes = residual_stack;
		n = n + 1;
	}
}

static void			process_edges(t_node_stack_item *current_node)
{
	int					k;
	t_node_stack_item	*current_edge;
	t_node_stack_item	*the_right_edge;

	k = 0;
	current_edge = current_node->node->flow->tail;
	while (k < current_node->node->flow->number_of_items)
	{
		the_right_edge =
		find_the_right_edge(current_node->node->residual_nodes,
		current_edge->node);
		remove_arbitrary_element(current_node->node->residual_nodes,
		the_right_edge);
		free(the_right_edge);
		k = k + 1;
		current_edge = current_edge->left;
	}
}

void				generate_residual_network_for_flow(t_colony *colony,
					t_path_list *path_list)
{
	int					m;
	t_path_list			*current_path;
	t_node_stack_item	*current_node;

	current_path = path_list;
	while (current_path != NULL)
	{
		m = 0;
		current_node = current_path->path->route->tail;
		while (m < current_path->path->length)
		{
			if (current_node->node->class == finish)
				break ;
			process_edges(current_node);
			m = m + 1;
			current_node = current_node->left;
		}
		current_path = current_path->next;
		destroy_stack(&colony->finish->flow);
	}
}
