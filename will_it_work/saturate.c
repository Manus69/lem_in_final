/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saturate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:05:43 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/15 16:34:40 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

static void	useless_function(t_colony *colony,
			t_path_list *current_path, int n)
{
	colony->ants[n]->path = current_path->path;
	colony->ants[n]->path_position = current_path->path->route->tail;
	colony->ants[n]->path->number_of_ants += 1;
	current_path->path->ants = add(current_path->path->ants,
	(void *)colony->ants[n]);
}

static int	waste_of_time_numerical(t_colony *colony,
			t_path_list *current_path,
			t_path_list *next_longest_path, t_path_list *path_list)
{
	int n;

	n = 0;
	while (current_path && (n < colony->number_of_ants))
	{
		current_path->path->number_of_ants += 1;
		if (current_path->next == next_longest_path)
		{
			if (current_path->path->number_of_ants +
			current_path->path->length < next_longest_path->path->length)
				current_path = path_list;
			else
			{
				next_longest_path = get_next_longest_path(next_longest_path);
				if (!next_longest_path)
					return (n + 1);
				current_path = path_list;
			}
		}
		else
			current_path = current_path->next;
		n = n + 1;
	}
	return (n);
}

static int	waste_of_time(t_colony *colony, t_path_list *current_path,
			t_path_list *next_longest_path, t_path_list *path_list)
{
	int n;

	n = 0;
	while (current_path && (n < colony->number_of_ants))
	{
		useless_function(colony, current_path, n);
		if (current_path->next == next_longest_path)
		{
			if (current_path->path->number_of_ants +
			current_path->path->length < next_longest_path->path->length)
				current_path = path_list;
			else
			{
				next_longest_path = get_next_longest_path(next_longest_path);
				if (!next_longest_path)
					return (n + 1);
				current_path = path_list;
			}
		}
		else
			current_path = current_path->next;
		n = n + 1;
	}
	return (n);
}

int			saturate_paths(t_colony *colony, t_path_list *path_list)
{
	t_path_list	*current_path;
	t_path_list	*next_longest_path;

	current_path = path_list;
	next_longest_path = get_next_longest_path(current_path);
	if (!next_longest_path)
		return (0);
	return (waste_of_time(colony, current_path,
	next_longest_path, path_list));
}

int			saturate_paths_numerically(t_colony *colony,
			t_path_list *path_list)
{
	t_path_list	*current_path;
	t_path_list	*next_longest_path;

	current_path = path_list;
	next_longest_path = get_next_longest_path(current_path);
	if (!next_longest_path)
		return (0);
	return (waste_of_time_numerical(colony, current_path,
	next_longest_path, path_list));
}
