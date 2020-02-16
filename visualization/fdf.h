/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:40:10 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 15:54:43 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "lemin.h"

typedef struct		s_mlw
{
	void			*mlx_ptr;
	void			*window;
	void			*map;
	char			*img_sourse;
}					t_mlw;

typedef struct		s_mouse
{
	int				prev_x;
	int				prev_y;
	int				x;
	int				y;
	int				left_press;
}					t_mouse;

typedef struct		s_vizor
{
	int				zoom;
	int				z_shift;
	int				x_shift;
	int				y_shift;
}					t_vizor;

typedef struct		s_rot
{
	double			alpha;
	double			beta;
	double			tetta;
}					t_rot;

typedef struct		s_point
{
	int				***axis;
	int				max_x;
	int				max_y;
	int				bits_pp;
	int				size_line;
	int				endian;
	int				min_z;
	int				max_z;
	char			*img_sourse;
	void			*mlx_ptr;
	void			*window;
	void			*map;
	t_mouse			mouse;
	t_vizor			vizor;
	int				projection;
	t_rot			rot;
	t_lemin			*lem;
}					t_point;

typedef struct		s_pix
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_pix;

int					***char_to_point(char *str);
void				find_xy_interval(t_point *half);
double				percent(int start, int end, int current);
void				edge_of_abyss(int ***spl, int *min, int *max);
void				make_first_color(int ****axis, int min, int max);
void				incr_z(t_point *changed, int count, int mark);
void				set_hooks(t_point *half);
int					draw_point(t_point *half);
void				rot_x(int *y, int *z, double alpha);
void				rot_y(int *x, int *z, double beta);
void				rot_z(int *x, int *y, double tetta);
void				rotation(int flag, int *y, int *x, int *z, t_rot rot);
void				iso_draw(int *x, int *y, int z);
void				charge_draw(t_pix *dot, t_point *half);
void				zero_to_vizor(t_point *half);
void				zero_to_rot(t_rot *rot);
void				zero_to_half(t_point *half, t_lemin *lemin);
char				*ft_undin(int fd);
int					get_color(t_pix present, t_pix start, t_pix end,\
								t_pix delta);
void				pixel_to_image(t_point *half, int x, int y, int color);
t_pix				complect_t_pix(t_point *half, int x, int y);
void				drawline(t_pix start, t_pix end, t_point *half);
int					first_color(int z, int max_z, int min_z);
int					spl_is_number(char c);
int					mouse_press_hook(int key, int x, int y, void *param);
int					motion_hook(int x, int y, void *param);
int					mouse_release_hook(int key, int x, int y, void *param);
void				free_to_axis(int ****spl);
void				init_var_draw(t_pix *delta, t_pix *sign,\
									t_pix start, t_pix end);
int					***from_lem_to_axis(t_lemin *lemin);
void				touch_my_node(t_point *half, t_lemin *lemin);
void				draw_circle(t_point *half, t_pix start, int radius);
void				move_my_ants(t_point *half);
int					draw_text(t_point *half);
int					exit_hook(int key, void *param);
void				next_wh_circle(int *x, int *y, int *delta);
char				*print_ant_name(char *str, int start);
void				init_ant_name(char *str, int *start,\
					int *border, char **ant_name);
int					draw_point(t_point *half);

#endif
