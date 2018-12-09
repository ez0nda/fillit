/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:46:14 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/09 14:35:26 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_line(char *line)
{
	if (line && ft_strlen(line))
	{
		ft_putendl("error");
		return (-1);
	}
	return (0);
}

int		ft_usage(void)
{
	ft_putstr("usage: ./fillit source_file\n");
	return (0);
}

char	**ft_create_map(int nb_tetri, char **map)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	k = 0;
	if (nb_tetri > 2)
		j = ft_sqrt(nb_tetri * 4);
	else
		j = 4;
	if (!(map = (char**)malloc(sizeof(char*) * j + 1)))
		return (NULL);
	while (i < j)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * j)))
			return (NULL);
		while (k < j)
		{
			map[i][k] = '.';
			k++;
		}
		map[i][k] = '\0';
		k = 0;
		i++;
	}
	map[j] = NULL;
	return (map);
}
