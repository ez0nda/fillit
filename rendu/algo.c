/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:01:39 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/12 16:13:36 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_rm_tetri(char **map, char letter[1], int mod)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (mod == 0)
	{
		while (map[i])
		{
			while (map[i][j])
			{
				if (map[i][j] == letter[0])
					map[i][j] = '.';
				j++;
			}
			i++;
			j = 0;
		}
	}
	else
	{
		while (map[i])
		{
			while (map[i][j])
			{
				if (map[i][j] == letter[0] || map[i][j] == letter[0] - 1)
					map[i][j] = '.';
				j++;
			}
			i++;
			j = 0;
		}
	}
	return (map);
}

static char		**ft_place_tetri(char **map, char **tetri, int nb_tetri, char letter[1], int feed[1])
{
	static int		i_tetri;
	static int		j_tetri;
	int				i_map;
	int				j_map;
	int				i_stock;
	int				j_stock;
	int				count;

	count = 0;
	i_map = 0;
	j_map = 0;
	while (map[i_map][j_map] != '.')
	{
		j_map++;
		if (j_map == ft_sqrt(nb_tetri * 4) + feed[0])
		{
			i_map++;
			j_map = 0;
		}
	}
	while (ft_strlen(tetri[i_tetri]))
	{
		if (count == 1)
		{
			if (i_map + i_tetri - i_stock < ft_sqrt(nb_tetri * 4) + feed[0] && j_map + j_tetri - j_stock < ft_sqrt(nb_tetri * 4) + feed[0] &&
					map[i_map + i_tetri - i_stock][j_map + j_tetri - j_stock] == '.')
			{
				map[i_map + i_tetri - i_stock][j_map + j_tetri - j_stock] = tetri[i_tetri][j_tetri];
				j_tetri++;
				if (j_tetri == 4)
				{
					i_tetri++;
					j_tetri = 0;
				}
			}
			else
			{
				map = ft_rm_tetri(map, letter, 0);
				j_map++;
				if (j_map == ft_sqrt(nb_tetri * 4) + feed[0])
				{
					i_map++;
					j_map = 0;
				}
				i_tetri = i_stock;
				j_tetri = j_stock;
			}
			if (i_map == ft_sqrt(nb_tetri * 4) + feed[0] - 1 && j_map == ft_sqrt(nb_tetri * 4) + feed[0] - 1)
			{
				i_map = 0;
				j_map = 0;
				if (letter[0] == 'A')
				{
					i_tetri = 0;
					j_tetri = 0;
					feed[0]++;
					if (!(map = ft_create_map(nb_tetri, map, feed)))
						return (NULL);
					letter[0] = 'A';
					return (map);
				}
				else
				{
					while (map[i_map][j_map] != letter[0] - 1)
					{
						j_map++;
						if (j_map == ft_sqrt(nb_tetri * 4) + feed[0])
						{
							i_map++;
							j_map = 0;
						}
					}
				}
				if (letter[0] - 1 == 'A' && map[ft_sqrt(nb_tetri * 4) + feed[0] - 1][ft_sqrt(nb_tetri * 4) + feed[0] -1] == 'A')
				{
					i_tetri = 0;
					j_tetri = 0;
					feed[0]++;
					if (!(map = ft_create_map(nb_tetri, map, feed)))
						return (NULL);
					letter[0] = 'A';
					return (map);
				}
				map = ft_rm_tetri(map, letter, 1);
				if (letter[0] != 'B' && letter[0] != 'A')
				{
					i_tetri = i_tetri - 5;
					while (ft_strlen(tetri[i_tetri]))
						i_tetri--;
					i_tetri++;
				}
				else
					i_tetri = 0;
				count = 0;
				letter[0]--;
				j_tetri = 0;
				j_map++;
				if (j_map == ft_sqrt(nb_tetri * 4) + feed[0])
				{
					i_map++;
					j_map = 0;
				}
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
			i_stock = i_tetri;
			j_stock = j_tetri;
			count++;
		}
	}
	letter[0]++;
	i_tetri++;
	j_tetri = 0;
	return (map);
}

char		**ft_algo(char **tetrimino, char l[1], int nb_tetri)
{
	static char		**tetri;
	char			**map;
	static char		letter[1];
	int				j;
	int				k;
	int				feed[1];

	map = NULL;
	feed[0] = 0;
	j = 0;
	k = 0;
	if (l[0] != '0')
	{
		letter[0] = l[0];
		tetri = tetrimino;
		return (NULL);
	}
	if (!(map = ft_create_map(nb_tetri, map, feed)))
		return (NULL);
	l[0] = 'A';
	while (l[0] <= letter[0])
	{
		if (!(map = ft_place_tetri(map, tetri, nb_tetri, l, feed)))
			return (NULL);
	}
	ft_display_map(map);
	return (map);
}
