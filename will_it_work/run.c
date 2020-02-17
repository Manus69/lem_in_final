/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:35:00 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/16 17:15:22 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"
#include "lemin.h"

static void	initialize_stuff(t_colony *colony)
{
	colony->ants = spawn_all_ants(colony->start, colony->number_of_ants);
	colony->current_flow = get_flow_paths(colony, 0);
	if (!colony->current_flow)
	{
		write(2, ERROR_MSG, ft_strlen(ERROR_MSG));
		exit(1);
	}
	initialize_the_flow_netowrk(colony, colony->current_flow);
	unplug_all_paths(colony->current_flow);
	colony->optimal_flow = copy_flow(colony->current_flow);
	saturate_and_distribute_mk2(colony, colony->current_flow, &colony->m, 1);
	colony->min_running_time = estimate_run_time(colony->current_flow);
	colony->current_running_time = colony->min_running_time;
	colony->m_p = colony->m;
}

static void	get_solution_in_the_first_approximation(t_colony *colony)
{
	while (1)
	{
		reset_everything(colony);
		colony->residual_path =
		new_path(naive_bfs(colony->start, colony->finish, 2));
		wipe_graph(colony->nodes);
		if (!colony->residual_path)
			break ;
		superimpose(colony, colony->residual_path, 0);
		destroy_path_list(&colony->current_flow, 0);
		colony->current_flow = get_flow_paths(colony, 1);
		unplug_all_paths(colony->current_flow);
		reset_paths(colony->current_flow);
		saturate_and_distribute_mk2(colony,
		colony->current_flow, &colony->m, 1);
		colony->current_running_time = estimate_run_time(colony->current_flow);
		if (colony->current_running_time < colony->min_running_time)
			set_minimum(colony);
		else if (colony->current_running_time > colony->min_running_time)
		{
			destroy_path(&colony->residual_path);
			break ;
		}
		destroy_path(&colony->residual_path);
	}
}

static void	refine_solution_via_pivots(t_colony *colony)
{
	while (1)
	{
		reset_everything(colony);
		block_pivots(colony->active_pivots, 1);
		colony->residual_path =
		new_path(naive_bfs(colony->start, colony->finish, 2));
		wipe_graph(colony->nodes);
		if (!colony->residual_path)
			break ;
		plug_all_paths(colony->current_flow);
		compute_distance_superimpose(colony);
		unplug_all_paths(colony->current_flow);
		destroy_path_list(&colony->current_flow, 0);
		colony->current_flow = get_flow_paths(colony, 1);
		unplug_all_paths(colony->current_flow);
		reset_paths(colony->current_flow);
		saturate_and_distribute_mk2(colony,
		colony->current_flow, &colony->m, 1);
		colony->current_running_time =
		estimate_run_time(colony->current_flow);
		if (colony->current_running_time < colony->min_running_time)
			set_minimum(colony);
		destroy_path(&colony->residual_path);
	}
}

static void	block_and_go(t_colony *colony)
{
	block_pivots(colony->active_pivots, 0);
	block_pivots(colony->pivot_nodes, 0);
	go_forth(colony);
}

int			main(int arg_count, char **arg_values)
{
	t_lemin		lemin;
	t_colony	*colony;

	if (!lets_read(&lemin, feel_map_file(arg_count, arg_values, &lemin)))
	{
		if (lemin.initial_text)
			free_for_all(&lemin);
		return (err_out());
	}
	colony = get_colony(lemin);
	initialize_stuff(colony);
	reset_paths(colony->current_flow);
	get_solution_in_the_first_approximation(colony);
	reset_flow_network(colony);
	initialize_the_flow_netowrk(colony, colony->optimal_flow);
	destroy_path_list(&colony->current_flow, 0);
	colony->current_flow = copy_flow(colony->optimal_flow);
	refine_solution_via_pivots(colony);
	reset_paths(colony->optimal_flow);
	saturate_and_distribute_mk2(colony, colony->optimal_flow, &colony->m_p, 0);
	print_initial_text(lemin.initial_text);
	block_and_go(colony);
	if (lemin.print_path)
		display_all_paths(colony->optimal_flow);
	return (collect_garbage(lemin, colony));
}
