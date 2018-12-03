/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:47:46 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/03 17:14:20 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int		ft_stock(char *line)
{
	static char		*stock[4];
	char			*tetra;
	static int		i;

	tetra = "";
	if (!i)
		i = 0;
	if (!(stock[i] = ft_strdup(line)))
		return (-1);
	i++;
	if (i == 4)
	{
		i = 0;
		while (i < 4)
		{
			if (!(tetra = ft_strjoin(tetra, stock[i])))
				return (-1);
			if (!(tetra = ft_strjoin(tetra, " ")))
				return (-1);
			i++;
		}
		i = ft_checkall(tetra);
	}
	return (i);
}
/*
static int		ft_check_line(char *line)
{
	
}*/

static int		ft_usage(void)
{
	ft_putstr("usage: ./fillit source_file\n");
	return (0);
}

int		main(int ac, const char **av)
{
	char	*line;
	int		fd;
	int		ret;

	if (ac != 2)
		return (ft_usage());
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ret = ft_stock(line);
		if (ret == -1)
			return (0);
		if (ret == 0 && (get_next_line(fd, &line) == -1))
			return (0);
	}
	return (0);
}
