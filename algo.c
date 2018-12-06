/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:58:57 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/06 16:59:27 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void		ft_check_pos_map(char **map, char **tetri, int map_pos[2], int nb_tetri)
{
	int		i;
	int		j;
	char	letter;

	letter = map[map_pos[0]][map_pos[1]];
	i = 0;
	j = 0;
	while (i < ft_sqrt(nb_tetri * 4))
	{
		while (j < ft_sqrt(nb_tetri * 4))
		{
			if (map[i][j] == letter)
				map[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	map_pos[1]++;
	if (map_pos[1] == ft_sqrt(nb_tetri * 4))
	{
		map_pos[0]++;
		map_pos[1] = 0;
	}
	i = 0;
	while (map[i])
	{
		printf("map Back: %s\n", map[i]);
		i++;
	}
}

static char		**ft_place_tetri(char **map, char **tetri, int nb_tetri)
{
	int				i;
	static int		count;
	static int		i_tetri;
	static int		i_j_tetri_stock[2];
	static int		j_tetri;
	int				map_pos[2];

	i = 0;
	map_pos[0] = 0;
	map_pos[1] = 0;
//	printf("map i: %d, map j: %d\n", map_pos[0], map_pos[1]);
	while (map[map_pos[0]][map_pos[1]] != '.')
	{
//		printf("map i: %d, map j: %d\n", map_pos[0], map_pos[1]);
		map_pos[1]++;
		if (map_pos[1] == ft_sqrt(nb_tetri * 4))
		{
			map_pos[0]++;
			map_pos[1] = 0;
		}
	}
//	printf("map i: %d, map j: %d\n", map_pos[0], map_pos[1]);
	while (ft_strlen(tetri[i_tetri]))
	{
		if (tetri[i_tetri][j_tetri] != '.')
		{
			if (count == 0)
			{
				i_j_tetri_stock[0] = i_tetri;
				i_j_tetri_stock[1] = j_tetri;
				count++;
			}
			if (map[map_pos[0] + i_tetri - i_j_tetri_stock[0]][map_pos[1] + j_tetri - i_j_tetri_stock[1]]
					&& map[map_pos[0] + i_tetri - i_j_tetri_stock[0]][map_pos[1] + j_tetri - i_j_tetri_stock[1]] == '.')
			{
				map[map_pos[0] + i_tetri - i_j_tetri_stock[0]][map_pos[1] + j_tetri - i_j_tetri_stock[1]] = tetri[i_tetri][j_tetri];
				j_tetri++;
			}
			else
			{
				ft_check_pos_map(map, tetri, map_pos, nb_tetri);
				i_tetri = i_j_tetri_stock[0];
				j_tetri = i_j_tetri_stock[1];
			}
			if (j_tetri == 4)
			{
				i_tetri++;
				j_tetri = 0;
			}
		}
		while (tetri[i_tetri][j_tetri] == '.')
		{
			j_tetri++;
			if (j_tetri == 4)
			{
				i_tetri++;
				j_tetri = 0;
			}
		}
		if (count == 0)
		{
			i_j_tetri_stock[0] = i_tetri;
			i_j_tetri_stock[1] = j_tetri;
			count++;
		}
	}
	count = 0;
	i_tetri++;
	return (map);
}

char		**ft_algo(char **tetrimino, int i, int nb_tetri)
{
	static char		**tetri;
	char			**map;
	int				j;
	int				k;

	j = 0;
	k = 0;
	if (i == 0)
	{
		tetri = tetrimino;
		return (NULL);
	}
	if (!(map = ft_create_map(nb_tetri, map)))
		return (NULL);
//	map = ft_place_tetri(map, tetri, nb_tetri);
//	while (map[j])
//	{
//		printf("map 1 piece: %s\n", map[j]);
//		j++;
//	}
	while (k < nb_tetri)
	{
		map = ft_place_tetri(map, tetri, nb_tetri);
		k++;
	}
	while (j < 4)
	{
		printf("map: %s\n", map[j]);
		j++;
	}
	return (map);
}
