/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:19:24 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 19:20:10 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generic_list.h"

t_generic_list	*new_generic_list(void *stuff)
{
	t_generic_list *new_list;

	new_list = malloc(sizeof(struct s_generic_list));
	if (!new_list)
		exit(1);
	new_list->stuff = stuff;
	new_list->next = NULL;
	return (new_list);
}

t_generic_list	*add(t_generic_list *list, void *stuff)
{
	t_generic_list *new_item;
	t_generic_list *current;

	new_item = new_generic_list(stuff);
	if (!list)
		return (new_item);
	current = list;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_item;
	return (list);
}

int				count_generic_list_objects(t_generic_list *generic_list)
{
	int				count;
	t_generic_list	*current;

	count = 0;
	current = generic_list;
	while (current)
	{
		count = count + 1;
		current = current->next;
	}
	return (count);
}

int				is_on_the_list(t_generic_list *generic_list, void *stuff)
{
	t_generic_list *current;

	current = generic_list;
	while (current)
	{
		if (current->stuff == stuff)
			return (1);
		current = current->next;
	}
	return (0);
}

void			destroy_generic_list(t_generic_list **generic_list)
{
	t_generic_list **current;
	t_generic_list *next;

	if (!generic_list || !*generic_list)
		return ;
	current = generic_list;
	while (*current)
	{
		next = (*current)->next;
		free(*current);
		*current = NULL;
		*current = next;
	}
}
