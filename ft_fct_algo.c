/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:22:01 by ezonda            #+#    #+#             */
/*   Updated: 2018/12/14 19:17:50 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_move_tetri(int d[2])
{
	d[1]++;
	if (d[1] == 4)
	{
		d[0]++;
		d[1] = 0;
	}
}

void	ft_first_stock(int c[7], int d[2])
{
	if (c[4] == 0)
	{
		c[2] = d[0];
		c[3] = d[1];
		c[4]++;
	}
}

void	ft_move_map(int c[7])
{
	c[1]++;
	if (c[1] == ft_sqrt(c[6] * 4) + c[5])
	{
		c[0]++;
		c[1] = 0;
	}
}

char	**ft_back_tetri(char **map, char l[1], int c[7], int d[2])
{
	map = ft_rm_tetri(map, l, 0);
	ft_move_map(c);
	d[0] = c[2];
	d[1] = c[3];
	return (map);
}
