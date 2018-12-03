/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:36:41 by ezonda            #+#    #+#             */
/*   Updated: 2018/12/03 17:23:49 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int		ft_checkchar(char *tab)
{
	int i;
	int dot;
	int sharp;

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
		{
			printf("error : wrong char\n");
			return (-1);
		}
		i++;
	}
	if (sharp != 4 || dot != 12)
	{
		printf("error : wrong number of |#| or |.|\n");
		return (-1);
	}
	printf("chars ok\n");
	return (0);
}

static int		ft_checkline(char *tab)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '.' || tab[i] == '#')
			len++;
		if (len > 4)
		{
			printf("error : line > 4 chars\n");
			return (-1);
		}
		if (len == 4 && tab[len] == ' ')
			len = 0;
		i++;
	}
	printf("line_size ok\n");
	return (0);
}

int		ft_checkall(char *tab)
{
	printf("tetri : %s\n", tab);
	if (ft_checkchar(tab) == -1)
		return (-1);
	if (ft_checkline(tab) == -1)
		return (-1);
//	if (ft_checktetri(tab) == 0)
//		return (0);
	return (0);
}
