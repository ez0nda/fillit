/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:47:46 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/17 13:50:09 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			ft_form_tetrimino(char **tetrimino)
{
	static char		letter[1];
	int				i;
	static int		j;
	static int		k;

	i = 0;
	if (!k)
		k = 5;
	if (!letter[0])
		letter[0] = 'A';
	while (j < k)
	{
		while (tetrimino[j][i])
		{
			if (tetrimino[j][i] == '#')
				tetrimino[j][i] = letter[0];
			i++;
		}
		j++;
		i = 0;
	}
	tetrimino[j] = NULL;
	k = k + 5;
	ft_algo(tetrimino, letter, 0);
	letter[0]++;
}

static int			ft_stock_tetrimino(char *stock[5], int nb_tetri)
{
	static char		**tetrimino;
	static int		i;
	static int		j;
	int				k;

	k = 0;
	if (!i)
		i = 5;
	if (!tetrimino)
		if (!(tetrimino = (char**)malloc(sizeof(char*) * nb_tetri * 5 + 1)))
			return (-1);
	while (j < i)
	{
		if (!(tetrimino[j] = ft_strdup(stock[k])))
			return (-1);
		j++;
		k++;
	}
	ft_form_tetrimino(tetrimino);
	i = i + 5;
	return (0);
}

static int			ft_stock(char *line, int nb_tetri)
{
	static char		*stock[5];
	char			*tetra;
	static int		i;

	if (!(tetra = ft_strdup("")))
		return (-1);
	if (!(stock[i] = ft_strdup(line)))
		return (-1);
	i++;
	if (i == 4)
	{
		i = 0;
		if (!(tetra = ft_join_tetri(stock, tetra, i)))
			return (-1);
		i = 4;
		stock[i] = "\0";
		if ((i = ft_checkall(tetra)) == -1)
			return (ft_delncheck(stock, tetra, i, line));
		if ((i = ft_stock_tetrimino(stock, nb_tetri)) == -1)
			return (-1);
		ft_strdel(stock);
	}
	return (ft_delncheck(stock, tetra, i, line));
}

static int			ft_get_tetri(char *line, int fd, int nb_tetri)
{
	int				ret;

	ret = ft_stock(line, nb_tetri);
	if (ret == -1)
		return (0);
	if (ret == 0 && (get_next_line(fd, &line) == -1))
		return (0);
	if (ret == 0 && ft_check_line(line) == -1)
		return (0);
	return (1);
}

int					main(int ac, char **av)
{
	char			*line;
	char			l[1];
	int				t[3];

	line = NULL;
	l[0] = '0';
	t[1] = 1;
	t[2] = 0;
	if (ac != 2)
		return (ft_usage());
	if (ft_check_nbtetri(t, line, av) == 0)
		return (0);
	t[0] = open(av[1], O_RDONLY);
	while (get_next_line(t[0], &line) > 0)
	{
		if (ft_get_tetri(line, t[0], t[1]) == 0)
			return (0);
		ft_strdel(&line);
	}
	close(t[0]);
	ft_algo(NULL, l, t[1]);
	return (0);
}
