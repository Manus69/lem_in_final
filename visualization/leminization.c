/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leminization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:28:16 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 15:31:21 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_move(t_point *half, t_pix fill, int radius)
{
	fill.color = 0xFF0000;
	while (--radius)
		draw_circle(half, fill, radius);
}

void			take_move(t_point *half, char *str, t_hash *hash_found)
{
	int		start;
	int		border;
	t_room	*move_point;
	t_pix	fill_circle;

	start = -1;
	border = -1;
	start = take_next_start(str, start);
	border = take_next_border(str, border);
	start = take_next_start(str, start);
	while (str[border])
	{
		border = take_next_border(str, border);
		hash_found->hash_first = hash_my_name(str, start, border);
		hash_found->first_name = ft_strsub(str, start, border - start);
		move_point = search_in_table(half->lem,\
				hash_found->hash_first, hash_found->first_name);
		fill_circle = complect_t_pix(half,\
				move_point->x_coord, move_point->y_coord);
		charge_draw(&fill_circle, half);
		draw_move(half, fill_circle, 5);
		start = take_next_start(str, start);
		border = start;
		free(hash_found->first_name);
	}
}

char			*print_ant_name(char *str, int start)
{
	char		*ant_name;
	int			i;
	static int	name;

	if (!(ant_name = (char *)malloc(sizeof(char) * (20))))
		return (NULL);
	if (start < 0)
		name = 0;
	i = 0;
	while (str[name] && str[name] != 'L')
		name++;
	while (str[name] && str[name] != '-')
		ant_name[i++] = str[name++];
	ant_name[i] = '\0';
	return (ant_name);
}

void			take_ant_name(t_point *half, char *str, t_hash *hash_found)
{
	int		start;
	int		border;
	t_room	*move_point;
	t_pix	fill_circle;
	char	*ant_name;

	init_ant_name(str, &start, &border, &ant_name);
	while (str[border])
	{
		border = take_next_border(str, border);
		hash_found->hash_first = hash_my_name(str, start, border);
		hash_found->first_name = ft_strsub(str, start, border - start);
		move_point = search_in_table(half->lem,\
				hash_found->hash_first, hash_found->first_name);
		fill_circle = complect_t_pix(half,\
				move_point->x_coord, move_point->y_coord);
		charge_draw(&fill_circle, half);
		mlx_string_put(half->mlx_ptr, half->window,\
				fill_circle.x + 10, fill_circle.y + 5, 0xFF0000, ant_name);
		free(ant_name);
		ant_name = print_ant_name(str, start);
		start = take_next_start(str, start);
		border = start;
		free(hash_found->first_name);
	}
}

void			move_my_ants(t_point *half)
{
	static int	step;
	t_hash		hash_found;

	if (!step)
		step = half->lem->start_move - 1;
	ft_bzero(half->img_sourse, 4000000);
	if (half->lem->initial_text[step])
	{
		draw_point(half);
		take_move(half, half->lem->initial_text[step], &hash_found);
		mlx_put_image_to_window(half->mlx_ptr, half->window, half->map, 0, 0);
		draw_text(half);
		take_ant_name(half, half->lem->initial_text[step], &hash_found);
		step++;
	}
	else
		step = half->lem->start_move - 1;
}
