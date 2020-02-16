/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:51:19 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/16 16:17:28 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_LEMIN_H
# define LEMIN_LEMIN_H

# include "libft.h"

typedef struct s_links		t_links;

typedef struct				s_hash
{
	int						hash_first;
	char					*first_name;
	int						hash_second;
	char					*second_name;
}							t_hash;

typedef struct				s_room
{
	char					*name;
	int						index;
	unsigned int			hash;
	int						x_coord;
	int						y_coord;
	int						part;
	int						level;
	int						dead;
	int						visited;
	t_links					*entrance;
	t_links					*midget;
	t_links					*output;
	t_links					*so_strange;
	t_links					*links;
	int						links_len;
}							t_room;

struct						s_links
{
	t_room					*link;
	int						dead;
	struct s_links			*next;
};

typedef struct				s_hash_table
{
	t_room					*link;
	struct s_hash_table		*next;

}							t_hash_table;

typedef struct				s_lemin
{
	int						ant_count;
	t_room					*rooms;
	t_hash_table			*table_hashes[4096];
	int						rooms_len;
	int						start_links;
	int						start_rooms;
	int						start;
	int						end;
	int						print_path;
	char					**initial_text;
}							t_lemin;

int							ft_atoi_push(char *str, int *i, int *ower);
char						**ft_strsplit_lem(char const *str, char c);
int							lets_read(t_lemin *lemin, char *map);
int							init_lemin(t_lemin *lemin, char **spl);
int							take_ants(t_lemin *lemin, char **spl);
int							take_rooms(t_lemin *lemin, char **spl);
int							take_links(t_lemin *lemin, char **spl);
unsigned int				hash_my_name(char *str, int start, int border);
int							create_link_in_room(t_lemin *lemin,\
							t_hash hash_found);
void						null_pointer_upload(t_lemin *lemin);
void						hash_table_upload(t_lemin *lemin);
int							err_out(void);
void						free_for_all(t_lemin *lemin);
void						del_list_links(t_links **begin_list);
int							check_rooms(t_lemin *lemin);
void						walker_kk(t_lemin *lemin);
int							push_link(t_links **begin_list, t_room *room);
void						print_rooms(t_lemin *lemin);
void						take_the_way(t_lemin *lemin, int bottle);
int							check_rooms_name(t_lemin *lemin);
void						free_pool_int(int ***coords);
int							fill_start_end(char **spl, int y, t_lemin *lemin);
int							take_next_border(char *str, int prev_border);
int							take_next_start(char *str, int prev_start);
int							find_borders(t_lemin *lemin, char **spl);
void						make_free_hash(t_lemin *lemin);
char						*feel_map_file(int ac, char **av, t_lemin *lemin);

#endif
