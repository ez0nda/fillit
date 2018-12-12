/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:23:31 by ezonda            #+#    #+#             */
/*   Updated: 2018/12/12 13:44:50 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_rm_tetri2(char **map, char letter[1])
{
	int i;
	int j;

	i = 0;
	j = 0;
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
	return (map);
}

/*void	ft_backtrack(char **map, char **tetri, int nb_tetri)
{

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
			}
			if (i_map == ft_sqrt(nb_tetri * 4) + feed[0] - 1 && j_map == ft_sqrt(nb_tetri * 4) + feed[0] - 1)
			{
				i_map = 0;
				j_map = 0;
				while (map[i_map][j_map] != letter[0] - 1)
				{
					j_map++;
					if (j_map == ft_sqrt(nb_tetri * 4) + feed[0])
					{
						i_map++;
						j_map = 0;
					}
				}
				if (letter[0] - 1 == 'A' && map[ft_sqrt(nb_tetri * 4) + feed[0] - 1][ft_sqrt(nb_tetri * 4) + feed[0] - 1] == 'A')
				{
					i_tetri = 0;
					j_tetri = 0;
					feed++;
					ft_create_map(nb_tetri, map, feed);
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
}*/
