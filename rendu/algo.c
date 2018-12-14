/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:01:39 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/14 17:38:36 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_rm_tetri2(char **map, char letter[1])
{
	int		i;
	int		j;

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
}

char			**ft_rm_tetri(char **map, char letter[1], int mod)
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
		ft_rm_tetri2(map, letter);
	return (map);
}

static void		ft_pos_last(int c[7], int d[2], char **tetri, char l[1])
{
	if (l[0] != 'B' && l[0] != 'A')
	{
		d[0] = d[0] - 5;
		while (ft_strlen(tetri[d[0]]))
			d[0]--;
		d[0]++;
	}
	else
		d[0] = 0;
	c[4] = 0;
	l[0]--;
	d[1] = 0;
	ft_move_map(c);
}

static char		**ft_place_tetri(char **map, char **tetri, char l[1], int f[4])
{
	static int		d[2];
	int				c[7];

	ft_init(map, c, f);
	while (ft_strlen(tetri[d[0]]))
	{
		if (c[4] == 1)
		{
			BIG_IF + BIG_IF2 + BIG_IF3 ? FAT_IF : FAT_ELSE;
			if (BIG_IF4 + BIG_IF5)
			{
				ft_reset(c);
				if (l[0] == 'A')
					return (back_the_map(map, d, f));
				else
					ft_move_the_map(map, c, l);
				map = ft_rm_tetri(map, l, 1);
				ft_pos_last(c, d, tetri, l);
			}
		}
		ft_move_the_tetri(tetri, c, d);
	}
	ft_end(l, d);
	return (map);
}

void			ft_algo(char **tetrimino, char l[1], int nb_tetri)
{
	static char		**tetri;
	char			**map;
	static char		letter[1];
	int				f[4];

	map = NULL;
	f[0] = 0;
	f[2] = 0;
	f[3] = 0;
	if (l[0] != '0')
	{
		letter[0] = l[0];
		tetri = tetrimino;
		return ;
	}
	f[1] = nb_tetri;
	if (!(map = ft_create_map(f[1], map, f)))
		return ;
	l[0] = 'A';
	while (l[0] <= letter[0])
		if (!(map = ft_place_tetri(map, tetri, l, f)))
			return ;
	ft_display_map(map);
	clearmap(map);
	return ;
}
