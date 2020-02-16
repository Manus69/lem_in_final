/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:02:40 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/23 18:03:31 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rot_x(int *y, int *z, double alpha)
{
	int tmp_y;

	tmp_y = *y;
	*y = (tmp_y) * cos(alpha) + *z * sin(alpha);
	*z = -(tmp_y) * sin(alpha) + *z * cos(alpha);
}

void		rot_y(int *x, int *z, double beta)
{
	int tmp_x;

	tmp_x = *x;
	*x = (tmp_x) * cos(beta) + *z * sin(beta);
	*z = -(tmp_x) * sin(beta) + *z * cos(beta);
}

void		rot_z(int *x, int *y, double tetta)
{
	int tmp_x;
	int tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x) * cos(tetta) - (tmp_y) * sin(tetta);
	*y = (tmp_x) * sin(tetta) + (tmp_y) * cos(tetta);
}

int			abso_lut(int a, int b)
{
	int abs;

	abs = b - a;
	if (abs < 0)
		abs = -abs;
	return (abs);
}

void		init_var_draw(t_pix *delta, t_pix *sign, t_pix start, t_pix end)
{
	delta->x = abso_lut(start.x, end.x);
	delta->y = abso_lut(start.y, end.y);
	sign->x = start.x < end.x ? 1 : -1;
	sign->y = start.y < end.y ? 1 : -1;
}
