/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:33:37 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/13 17:51:33 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERIC_LIST_H
# define GENERIC_LIST_H

# include <stdlib.h>

typedef struct s_generic_list	t_generic_list;

struct			s_generic_list
{
	void			*stuff;
	t_generic_list	*next;
};

t_generic_list	*new_generic_list(void *stuff);
t_generic_list	*add(t_generic_list *list, void *stuff);
int				count_generic_list_objects(t_generic_list *generic_list);
int				is_on_the_list(t_generic_list *generic_list, void *stuff);
void			destroy_generic_list(t_generic_list **generic_list);

#endif
