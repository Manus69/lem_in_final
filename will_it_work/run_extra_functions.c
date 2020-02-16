/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_extra_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:51:09 by lcaesar           #+#    #+#             */
/*   Updated: 2020/02/16 16:24:16 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ants.h"
#include "function_prototypes.h"

void	set_minimum(t_colony *colony)
{
	destroy_generic_list(&colony->active_pivots);
	colony->min_running_time = colony->current_running_time;
	colony->m_p = colony->m;
	destroy_path_list(&colony->optimal_flow, 0);
	colony->optimal_flow = copy_flow(colony->current_flow);
}

void	saturate_and_distribute_mk2(t_colony *colony,
		t_path_list *paths, int *index, int numerical)
{
	if (numerical)
	{
		*index = saturate_paths_numerically(colony, paths);
		distribute_ants_uniformly_numerically(colony, paths, *index);
	}
	else
	{
		*index = saturate_paths(colony, paths);
		distribute_ants_uniformly(colony, paths, *index);
	}
}

void	saturate_and_distribute(t_colony *colony,
		t_path_list *paths, int numerical)
{
	if (numerical)
	{
		colony->m = saturate_paths_numerically(colony, paths);
		distribute_ants_uniformly_numerically(colony, paths, colony->m);
	}
	else
	{
		colony->m_p = saturate_paths(colony, paths);
		distribute_ants_uniformly(colony, paths, colony->m_p);
	}
}

void	compute_distance_superimpose(t_colony *colony)
{
	colony->distance_to = get_distance_to_the_jam(colony->residual_path);
	colony->distance_from = get_distance_from_the_jam(colony->residual_path);
	if ((colony->distance_to < 0) || (colony->distance_from < 0))
		superimpose(colony, colony->residual_path, 1);
	else if (colony->distance_from > colony->distance_to)
		superimpose_mk2_backwards(colony, colony->residual_path);
	else
		superimpose_mk2_forwards(colony, colony->residual_path);
}
