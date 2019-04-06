/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:46:14 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/15 19:53:30 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clearmap(char **tab, char **tetri)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	tab = NULL;
	if (!tetri)
		return ;
	i = 0;
	while (tetri[i])
	{
		free(tetri[i]);
		i++;
	}
	free(tetri[i]);
	free(tetri);
	tetri = NULL;
}

int		ft_usage(void)
{
	ft_putstr("usage: ./fillit source_file\n");
	return (0);
}

int		ft_check_void(int nb_tetri, int check)
{
	if (nb_tetri != check / 4)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

void	ft_display_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}

char	**ft_create_map(int nb_tetri, char **map, int feed[4])
{
	int				i;
	int				j;
	int				k;

	i = 0;
	k = 0;
	j = ft_sqrt(nb_tetri * 4) + feed[0];
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
