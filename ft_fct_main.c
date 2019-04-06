/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:37:08 by ezonda            #+#    #+#             */
/*   Updated: 2018/12/15 21:23:34 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_nbtetri(int t[3], char *line, char **av)
{
	t[0] = open(av[1], O_RDONLY);
	while (get_next_line(t[0], &line) > 0)
	{
		(!ft_strlen(line) ? t[1]++ : t[2]++);
		ft_strdel(&line);
	}
	if (ft_check_void(t[1], t[2]) == 0)
		return (0);
	close(t[0]);
	return (1);
}

char		*ft_join_tetri(char *stock[5], char *tetra, int i)
{
	char		*tmp;

	while (i < 4)
	{
		if (!(tmp = ft_strjoin(tetra, stock[i])))
			return (NULL);
		ft_strdel(&tetra);
		if (!(tetra = ft_strjoin(tmp, " ")))
			return (NULL);
		ft_strdel(&tmp);
		i++;
	}
	return (tetra);
}

int			ft_delncheck(char *stock[5], char *tetra, int i, char *line)
{
	if (i == -1)
	{
		ft_strdel(&tetra);
		ft_strdel(&line);
		return (-1);
	}
	free(stock[i]);
	stock[i] = NULL;
	ft_strdel(&tetra);
	return (i);
}

int			ft_check_line(char *line)
{
	if (line && ft_strlen(line))
	{
		ft_putendl("error");
		return (-1);
	}
	ft_strdel(&line);
	return (0);
}
