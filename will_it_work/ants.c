/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:29:01 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/15 14:44:22 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

t_ant		*spawn_new_ant(t_node *node, int number)
{
	t_ant	*ant;

	ant = mallokill(sizeof(struct s_ant));
	ant->number = number;
	ant->mark = 0;
	ant->current_node = node;
	ant->previous_node = NULL;
	ant->destination = NULL;
	ant->path = NULL;
	ant->path_position = NULL;
	node->ant = ant;
	node->number_of_ants = node->number_of_ants + 1;
	return (ant);
}

t_ant		**spawn_all_ants(t_node *start, int number_of_ants)
{
	t_ant	**ants;
	int		n;

	if (!start)
		return (NULL);
	ants = mallokill(sizeof(struct s_ant *) * (number_of_ants + 1));
	n = 0;
	while (n < number_of_ants)
	{
		ants[n] = spawn_new_ant(start, n);
		n = n + 1;
	}
	ants[n] = NULL;
	start->number_of_ants = number_of_ants;
	return (ants);
}

int			move(t_ant *ant)
{
	t_node	*next_node;
	char	*move_description;

	if (!ant || !ant->path || !ant->path->length)
		return (0);
	next_node = ant->path_position->left->node;
	if (next_node->ant != NULL)
		return (0);
	move_description = get_move_description(ant, next_node);
	ant->previous_node = ant->current_node;
	ant->current_node->ant = NULL;
	ant->current_node->number_of_ants = ant->current_node->number_of_ants - 1;
	ant->current_node = next_node;
	next_node->number_of_ants = next_node->number_of_ants + 1;
	next_node->ant = ant;
	ant->path_position = ant->path_position->left;
	if (ant->current_node->class == finish)
	{
		ant->current_node->ant = NULL;
		ant->path->number_of_ants = ant->path->number_of_ants - 1;
		ant->path = NULL;
	}
	write(1, move_description, ft_strlen(move_description));
	free(move_description);
	return (1);
}
