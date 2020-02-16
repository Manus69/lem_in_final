/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_to_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:40:33 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/23 17:40:50 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		charge_draw(t_pix *dot, t_point *half)
{
	dot->x *= half->vizor.zoom;
	dot->y *= half->vizor.zoom;
	dot->z += half->vizor.zoom / half->vizor.z_shift;
	dot->x -= (half->max_x * half->vizor.zoom) / 2;
	dot->y -= (half->max_y * half->vizor.zoom) / 2;
	rot_x(&dot->y, &dot->z, half->rot.alpha);
	rot_y(&dot->x, &dot->z, half->rot.beta);
	rot_z(&dot->x, &dot->y, half->rot.tetta);
	if (half->projection == 1)
		iso_draw(&dot->x, &dot->y, dot->z);
	dot->x += 500 + half->vizor.x_shift;
	dot->y += 500 + half->vizor.y_shift;
}
