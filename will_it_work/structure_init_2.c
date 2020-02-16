/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_init_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:17:50 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/08 21:57:09 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		fill_borders(char *str)
{
	int i;
	int border_count;

	i = -1;
	border_count = 0;
	while (str[++i])
	{
		if (str[i] == '-')
			border_count++;
	}
	return (border_count);
}

int		fill_one_link(char *str, t_hash *hash_found)
{
	int start;
	int border;

	start = -1;
	border = -1;
	hash_found->hash_first = 0;
	hash_found->hash_second = 0;
	if (fill_borders(str) > 1)
		return (0);
	start = take_next_start(str, start);
	border = take_next_border(str, border);
	hash_found->hash_first = hash_my_name(str, start, border);
	hash_found->first_name = ft_strsub(str, start, border - start);
	start = border;
	start = take_next_start(str, start);
	border = ft_strlen(str);
	hash_found->hash_second = hash_my_name(str, start, border);
	hash_found->second_name = ft_strsub(str, start, border - start);
	return (1);
}

int		error_out_link_create(t_hash *hash_found)
{
	free((*hash_found).first_name);
	free((*hash_found).second_name);
	return (0);
}

void	init_take_var(t_lemin *lemin, int *y, int *links_count)
{
	*y = lemin->start_links - 1;
	*links_count = 0;
}

int		take_links(t_lemin *lemin, char **spl)
{
	int		y;
	t_hash	hash_found;
	int		links_count;

	init_take_var(lemin, &y, &links_count);
	while (spl[++y])
	{
		if (spl[y][0] != '#')
		{
			hash_found.first_name = NULL;
			hash_found.second_name = NULL;
			if (!fill_one_link(spl[y], &hash_found))
				return (0);
			if (!create_link_in_room(lemin, hash_found))
				return (error_out_link_create(&hash_found));
			free(hash_found.first_name);
			free(hash_found.second_name);
			links_count++;
		}
		else if (!ft_strcmp(spl[y], "##start") || !ft_strcmp(spl[y], "##end"))
			return (0);
	}
	if (!links_count)
		return (0);
	return (1);
}
