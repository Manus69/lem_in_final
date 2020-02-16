/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_axis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgerda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:56:46 by bgerda            #+#    #+#             */
/*   Updated: 2019/11/23 18:00:00 by bgerda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		spl_len(char *str, int *y)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i])
		{
			(*y)++;
			while (str[i] != '\n' && str[i])
				i++;
		}
		else
			i++;
	}
	return ((*y));
}

int		spl_x_len(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] != '\n' && str[i])
	{
		if (spl_is_number(str[i]))
		{
			len++;
			while (spl_is_number(str[i]))
				i++;
		}
		else
			i++;
	}
	return (len);
}

int		*take_axis(char *str, int *i)
{
	int *axis;

	if (!((axis) = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	if (spl_is_number(str[*i]))
		axis[0] = ft_atoi(&str[(*i)]);
	while (str[(*i)] && spl_is_number(str[*i]))
		(*i)++;
	if (str[(*i)] == ',')
	{
		(*i)++;
		if (!ft_strncmp("0x", &str[(*i)], 2))
		{
			(*i) += 2;
			axis[1] = ft_atoi_base(&str[(*i)], 16);
		}
		else
			axis[1] = ft_atoi(&str[(*i)]);
	}
	else
		axis[1] = 0;
	while (str[(*i)] && spl_is_number(str[*i]))
		(*i)++;
	return (axis);
}

int		**create_x(char *str, int *x, int *i)
{
	int			**spl_x;
	static int	len;

	if (!len)
		len = spl_x_len(str);
	if (!((spl_x) = (int **)malloc(sizeof(int *) * (len + 1))))
		return (NULL);
	while (str[*i] != '\n' && str[*i])
	{
		while (!spl_is_number(str[*i]) && str[*i])
			(*i)++;
		if (spl_is_number(str[*i]))
		{
			spl_x[*x] = take_axis(str, i);
			(*x)++;
		}
	}
	spl_x[*x] = NULL;
	return (spl_x);
}

int		***char_to_point(char *str)
{
	int ***spl;
	int x;
	int y;
	int i;
	int len;

	y = 0;
	i = 0;
	len = 0;
	if (!(spl = (int ***)malloc(sizeof(int **) * (spl_len(str, &len) + 1))))
		return (NULL);
	while (y < len)
	{
		x = 0;
		spl[y] = create_x(str, &x, &i);
		y++;
		if (str[i] == '\n')
			i++;
	}
	spl[y] = NULL;
	return (spl);
}
