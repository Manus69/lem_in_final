/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:03:30 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/26 18:50:24 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <fcntl.h>

int		check_and_parse(char **spl, t_lemin *lemin)
{
	lemin->start = -1;
	lemin->end = -1;
	if (!init_lemin(lemin, spl))
		return (0);
	return (1);
}

int		search_void_string(char *str)
{
	int i;

	i = -1;
	if (!str || str[0] == '\n')
		return (1);
	while (str[++i])
	{
		if (str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
			return (1);
	}
	return (0);
}

char	*ft_undin_second(int fd)
{
	char	*buf;
	int		ret;

	if (!(buf = (char *)malloc(sizeof(char) * 10000000)))
		return (NULL);
	if (0 > (ret = read(fd, buf, 10000000)))
		return (NULL);
	buf[ret] = '\0';
	return (buf);
}

int		lets_read(t_lemin *lemin, char *map)
{
	char	*input;
	char	**spl;
	int		fd;

	fd = 0;
	input = NULL;
	if (map)
		fd = open(map, O_RDONLY);
	if (fd < 0)
		fd = 0;
	if (!(input = ft_undin_second(fd)))
		return (0);
	if (search_void_string(input))
	{
		free(input);
		lemin->initial_text = NULL;
		return (0);
	}
	spl = ft_strsplit(input, '\n');
	free(input);
	if (!check_and_parse(spl, lemin))
		return (0);
	return (1);
}
