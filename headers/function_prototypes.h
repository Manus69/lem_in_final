/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_prototypes.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:33:23 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/16 14:21:40 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_PROTOTYPES_H
# define FUNCTION_PROTOTYPES_H

# include "four_header.h"

# include "ants.h"

# include "generic_list.h"

t_node				**get_node_array(t_lemin *lemin);
void				get_adjacency_stacks_from_structure(t_node **nodes,
					t_lemin *lemin);
t_colony			*get_colony(t_lemin lemin);
char				*get_move_description(t_ant *ant, t_node *node);

t_ant				*spawn_new_ant(t_node *node, int number);
t_ant				**spawn_all_ants(t_node *start, int number_of_ants);
void				compute_path(t_ant *ant, t_node *from,
					t_node *destination);
int					move(t_ant *ant);
t_node				*find_alpha_ant(t_ant **ants, int reset_alpha_counter);

void				distribute_ants_uniformly
(t_colony *colony, t_path_list *path_list, int starting_index);
void				distribute_ants_uniformly_numerically
(t_colony *colony, t_path_list *path_list, int starting_index);

int					saturate_paths(t_colony *colony, t_path_list *path_list);
int					saturate_paths_numerically(t_colony *colony,
					t_path_list *path_list);

t_node				*new_node_item(int index, char *name);
t_node_stack_item	*new_node_stack_item(t_node *node);
t_stack				*new_stack(t_node_stack_item *head,
					t_node_stack_item *tail, int number_of_items);
t_stack				*push(t_stack *stack, t_node_stack_item *item);
t_node_stack_item	*pop(t_stack *stack);
t_stack				*queue(t_stack *stack, t_node_stack_item *item);
t_node_stack_item	*get_nth_element(t_stack *stack, int n);
t_stack				*copy_node_stack(t_stack *source_stack);
t_node_stack_item	*remove_arbitrary_element(t_stack *stack,
					t_node_stack_item *node);

t_stack				*naive_dfs(t_node *start, t_node *finish);
t_stack				*naive_bfs(t_node *start, t_node *finish, int flow_flag);
t_stack				*visit(t_stack *path, t_node *current, t_node *finish);
void				wipe_graph(t_node **nodes);
t_stack				*backtrack(t_node *finish, t_node *start);

void				block_pivots(t_generic_list *pivot_nodes, long block);

void				quick_stack_display(t_stack *stack);
void				display_all_paths(t_path_list *paths);

void				destroy_stack(t_stack **stack);
void				destroy_path(t_path **path);
void				reset_residual_network(t_colony *colony);
void				reset_flow_network(t_colony *colony);
void				destroy_path_list(t_path_list **path_list, int kill_ants);
void				kill_all_ants(t_colony *colony);
void				reset_ants_for_paths(t_path_list *paths);
void				destroy_all_nodes(t_colony *colony);
t_node_stack_item	*find_the_right_edge(t_stack *edges, t_node *node);

t_path				*new_path(t_stack *route);
t_path_list			*new_path_list(t_path *path);
t_path_list			*queue_path(t_path_list *path_list, t_path *path);
t_path_list			*get_the_right_path(t_node *node, t_path_list *paths);
t_path_list			*remove_path_from_list(t_path_list **path_list,
					t_path *path);
t_path_list			*get_next_longest_path(t_path_list *path_list_item);

t_path				*find_minimum_cost_path_mk2(t_path_list *paths);

void				initialize_the_flow_netowrk(t_colony *colony,
					t_path_list *paths);
void				initialize_residual_network(t_node **nodes);
void				generate_residual_network_for_flow(t_colony *colony,
					t_path_list *path_list);
void				superimpose(t_colony *colony, t_path *path, int pivoting);
void				plug_the_path(t_path *path, int plug);
t_path_list			*get_flow_paths(t_colony *colony, int flow_flag);
void				unplug_all_paths(t_path_list *paths);
void				plug_all_paths(t_path_list *paths);
int					count_paths(t_path_list *paths);
int					count_non_empty_paths(t_path_list *paths);
t_path_list			*copy_flow(t_path_list *current_flow);
void				reset_paths(t_path_list *paths);
void				reset_everything(t_colony *colony);

int					get_distance_to_the_jam(t_path *path);
int					get_distance_from_the_jam(t_path *path);
void				superimpose_mk2_backwards(t_colony *colony, t_path *path);
void				superimpose_mk2_forwards(t_colony *colony, t_path *path);

int					collect_garbage(t_lemin lemin, t_colony *colony);
void				block_pivots(t_generic_list *pivot_nodes, long block);
void				print_initial_text(char **initial_text);
int					estimate_run_time(t_path_list *paths);
void				go_forth(t_colony *colony);

void				undo_flow_on_segment(t_path *flow_path,
					t_node *final_node);
void				undo_flow_on_segment_after_intersection(t_path *flow_path,
					t_node *intersection);
void				process_pivots(t_colony *colony,
					t_node_stack_item *next_node);

void				set_minimum(t_colony *colony);
void				saturate_and_distribute(t_colony *colony,
					t_path_list *paths, int numerical);
void				compute_distance_superimpose(t_colony *colony);
void				saturate_and_distribute_mk2(t_colony *colony,
					t_path_list *paths, int *index, int numerical);
#endif
