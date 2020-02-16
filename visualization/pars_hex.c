/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:02:56 by gemerald          #+#    #+#             */
/*   Updated: 2020/02/09 17:50:42 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void		concat_me_stdin(char **args, char *str)
{
	static int	i;
	int			j;
	char		*dst;

	j = 0;
	dst = *args;
	while (str[j])
	{
		dst[i++] = str[j++];
	}
	dst[i++] = '\n';
	dst[i] = '\0';
}

int			check_and_parse(char **spl, t_lemin *lemin)
{
	lemin->start = -1;
	lemin->end = -1;
	if (!init_lemin(lemin, spl))
		return (0);
	return (1);
}

int			search_void_string(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
			return (1);
	}
	return (0);
}

char		*ft_undin_second(int fd)
{
	char	*buf;
	int		ret;

	if (!(buf = (char *)malloc(sizeof(char) * 10000000)))
		return (NULL);
	ret = read(fd, buf, 10000000);
	buf[ret] = '\0';
	return (buf);
}

int			lets_read(t_lemin *lemin)
{
	char	*input;
	char	**spl;
	int		fd;

	fd = 0;
	if (!(input = ft_undin_second(fd)))
		return (0);
	spl = ft_strsplit(input, '\n');
	free(input);
	if (!check_and_parse(spl, lemin))
		return (0);
	return (1);
}
