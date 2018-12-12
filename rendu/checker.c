/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:36:41 by ezonda            #+#    #+#             */
/*   Updated: 2018/12/06 11:09:57 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_checkchar(char *tab)
{
	int		i;
	int		dot;
	int		sharp;

	i = 0;
	dot = 0;
	sharp = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '#')
			sharp++;
		if (tab[i] == '.')
			dot++;
		if (tab[i] != '#' && tab[i] != '.' && tab[i] != ' ')
			return (-1);
		i++;
	}
	if (sharp != 4 || dot != 12)
		return (-1);
	return (0);
}

static int		ft_checkline(char *tab)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '.' || tab[i] == '#')
			len++;
		if (len > 4)
			return (-1);
		if (len == 4 && tab[len] == ' ')
			len = 0;
		i++;
	}
	return (0);
}

static int		ft_checktetri(char *tab)
{
	int			i;
	int			occ;

	i = 0;
	occ = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '#' && tab[i + 1] == '#')
			occ++;
		if (tab[i] == '#' && tab[i + 5] == '#')
			occ++;
		if (tab[i] == '#' && tab[i - 1] == '#')
			occ++;
		if (tab[i] == '#' && tab[i - 5] == '#')
			occ++;
		i++;
	}
	if (occ == 6 || occ == 8)
		return (0);
	return (-1);
}

int				ft_checkall(char *tab)
{
	static int	i;

	i++;
	if (ft_checkchar(tab) == -1)
	{
		ft_putendl("error");
		return (-1);
	}
	if (ft_checkline(tab) == -1)
	{
		ft_putendl("error");
		return (-1);
	}
	if (ft_checktetri(tab) == -1)
	{
		ft_putendl("error");
		return (-1);
	}
	if (i == 26)
	{
		ft_putendl("error");
		return (-1);
	}
	return (0);
}
