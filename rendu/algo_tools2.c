/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:47:32 by ezonda            #+#    #+#             */
/*   Updated: 2018/12/14 17:12:09 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_end(char l[1], int d[2])
{
	l[0]++;
	d[0]++;
	d[1] = 0;
}

void		ft_reset(int c[7])
{
	c[0] = 0;
	c[1] = 0;
}

void		ft_move_the_map(char **map, int c[7], char l[1])
{
	while (map[c[0]][c[1]] != l[0] - 1)
		ft_move_map(c);
}

void		ft_move_the_tetri(char **tetri, int c[7], int d[2])
{
	while (tetri[d[0]][d[1]] == '.')
		ft_move_tetri(d);
	ft_first_stock(c, d);
}

char		**back_the_map(char **map, int d[2], int f[4])
{
	if (!(map = ft_prev_back_map(map, d, f)))
		return (NULL);
	return (map);
}
