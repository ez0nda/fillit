/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:23:31 by ezonda            #+#    #+#             */
/*   Updated: 2018/12/15 19:26:58 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printnmove(int c[7], int d[2], char **map, char **tetri)
{
	map[c[0] + d[0] - c[2]][c[1] + d[1] - c[3]] = tetri[d[0]][d[1]];
	ft_move_tetri(d);
}

void	ft_map_pos(char **map, int c[7])
{
	while (map[c[0]][c[1]] != '.')
		ft_move_map(c);
}

void	ft_init(char **map, int c[7], int f[2])
{
	c[4] = 0;
	c[0] = 0;
	c[1] = 0;
	c[5] = f[0];
	c[6] = f[1];
	ft_map_pos(map, c);
}

char	**ft_prev_back_map(char **map, int d[2], int f[4])
{
	d[0] = 0;
	d[1] = 0;
	f[0]++;
	ft_clearmap(map, NULL);
	if (!(map = ft_create_map(f[1], map, f)))
		return (NULL);
	return (map);
}
