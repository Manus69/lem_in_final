/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:33:12 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/16 14:17:45 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTS_H
# define ANTS_H

# include "lemin.h"

# include "generic_list.h"

# define ERROR_MSG "ERROR"
# define BIG_STRING_CAPACITY 10000000
# define MOVE_DESCRIPTION_LENGTH 128

typedef struct s_ant				t_ant;
typedef struct s_node				t_node;
typedef struct s_node_stack_item	t_node_stack_item;
typedef struct s_stack				t_stack;
typedef struct s_colony				t_colony;
typedef enum e_node_class			t_node_class;

typedef struct s_big_string			t_big_string;
typedef struct s_path				t_path;
typedef struct s_path_list			t_path_list;

typedef struct s_node_pair			t_node_pair;

enum	e_node_class
{
	regular,
	start,
	finish,
};

struct	s_node_pair
{
	t_node_stack_item	*current;
	t_node_stack_item	*next;
};

struct	s_node
{
	int					index;
	int					number_of_ants;
	int					x;
	int					y;
	int					visited;
	int					discovered;
	int					used;
	char				*name;
	t_node				*discovered_via;
	t_node_class		class;
	t_stack				*adjacent_nodes;
	t_stack				*flow;
	t_stack				*residual_nodes;
	t_ant				*ant;
};

struct	s_ant
{
	int					number;
	int					mark;
	t_node				*current_node;
	t_node				*previous_node;
	t_node				*destination;
	t_path				*path;
	t_node_stack_item	*path_position;
};

struct	s_colony
{
	int					number_of_ants;
	int					number_of_paths;
	int					m;
	int					m_p;
	int					current_running_time;
	int					min_running_time;
	int					distance_to;
	int					distance_from;
	t_node				*start;
	t_node				*finish;
	t_node				**nodes;
	t_ant				**ants;
	t_generic_list		*active_pivots;
	t_generic_list		*pivot_nodes;
	t_path_list			*optimal_flow;
	t_path_list			*current_flow;
	t_path				*residual_path;
};

struct	s_node_stack_item
{
	struct s_node		*node;
	t_node_stack_item	*left;
	t_node_stack_item	*right;
};

struct	s_stack
{
	t_node_stack_item	*head;
	t_node_stack_item	*tail;
	int					number_of_items;
};

struct	s_path_list
{
	struct s_path		*path;
	struct s_path_list	*next;
};

struct	s_path
{
	int					length;
	int					number_of_ants;
	struct s_stack		*route;
	t_generic_list		*ants;
};

#endif
