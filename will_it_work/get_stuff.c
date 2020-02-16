/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:48:34 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/16 14:17:57 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"
#include "lemin.h"

t_node		**get_node_array(t_lemin *lemin)
{
	t_node	**array;
	int		j;
	int		number_of_nodes;

	j = 0;
	number_of_nodes = lemin->rooms_len;
	array = mallokill(sizeof(struct s_node *) * (number_of_nodes + 1));
	while (j < number_of_nodes)
	{
		array[j] = new_node_item(j, lemin->rooms[j].name);
		j = j + 1;
	}
	array[j] = NULL;
	return (array);
}

void		get_adjacency_stacks_from_structure(t_node **nodes, t_lemin *lemin)
{
	int					n;
	int					m;
	t_stack				*stack;
	t_node_stack_item	*node_stack_item;
	t_links				*current_link;

	n = 0;
	while (nodes[n])
	{
		m = 0;
		current_link = lemin->rooms[n].links;
		while (current_link)
		{
			node_stack_item =
			new_node_stack_item(nodes[current_link->link->index]);
			if (m == 0)
				stack = new_stack(node_stack_item, node_stack_item, 1);
			else
				stack = push(stack, node_stack_item);
			current_link = current_link->next;
			m = m + 1;
		}
		nodes[n]->adjacent_nodes = (m > 0) ? stack : NULL;
		n = n + 1;
	}
}

t_colony	*get_colony(t_lemin lemin)
{
	t_colony *colony;

	colony = mallokill(sizeof(struct s_colony));
	colony->number_of_ants = lemin.ant_count;
	colony->number_of_paths = -1;
	colony->m = -1;
	colony->m_p = -1;
	colony->current_running_time = -1;
	colony->min_running_time = -1;
	colony->distance_to = -1;
	colony->distance_from = -1;
	colony->nodes = get_node_array(&lemin);
	colony->ants = NULL;
	colony->nodes[lemin.start]->class = start;
	colony->nodes[lemin.end]->class = finish;
	colony->start = colony->nodes[lemin.start];
	colony->finish = colony->nodes[lemin.end];
	get_adjacency_stacks_from_structure(colony->nodes, &lemin);
	colony->pivot_nodes = NULL;
	colony->active_pivots = NULL;
	colony->current_flow = NULL;
	colony->optimal_flow = NULL;
	colony->residual_path = NULL;
	return (colony);
}

static char	*new_string_protected(size_t size)
{
	char *new_string;

	new_string = ft_strnew(size);
	if (!new_string)
	{
		ft_printf("Malloc failure;\n");
		exit(1);
	}
	return (new_string);
}

char		*get_move_description(t_ant *ant, t_node *node)
{
	char	*move_description;
	char	*store;
	int		index;
	int		n;

	move_description = new_string_protected(MOVE_DESCRIPTION_LENGTH);
	index = 1;
	n = -1;
	move_description[0] = 'L';
	store = ft_itoa(ant->number + 1);
	while (store[++n] != '\0')
		move_description[index + n] = store[n];
	index = index + n;
	free(store);
	move_description[index++] = '-';
	n = -1;
	while (node->name[++n] != '\0')
		move_description[index + n] = node->name[n];
	move_description[index + n] = ' ';
	return (move_description);
}
