/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:28:19 by ezonda            #+#    #+#             */
/*   Updated: 2018/12/05 15:36:44 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static char		*ft_top(char *tab, int gap)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '#' && gap <= 8)
		{
			tab[i - 5] = '#';
			tab[i] = '.';
		}
		if (tab[i] == '#' && (gap > 8 && gap <= 13))
		{
			tab[i - 10] = '#';
			tab[i] = '.';
		}
		if (tab[i] == '#' && gap > 13)
		{
			tab[i - 15] = '#';
			tab[i] = '.';
		}
		i++;
	}
	return (tab);
}

static char		*ft_left(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '#')
		{
			tab[i - 1] = '#';
			tab[i] = '.';
		}
		i++;
	}
	i = 0;
	if (tab[i] != '#' && tab[i + 5] != '#' && tab[i + 10] != '#'
			&& tab[i + 15] != '#')
		ft_left(tab);
	return (tab);
}

char			*ft_top_left(char *tab)
{
	int i;
	int gap;

	i = 0;
	gap = 0;
	if (tab[i] == '#' || (tab[i + 1] == '#' && tab[i + 5] == '#'))
	{
		printf("no change needed\n");
		return (tab);
	}
	while (tab[gap] != '#')
		gap++;
	if (gap > 4)
		ft_top(tab, gap);
	if (tab[i + 5] == '#' || tab[i + 10] == '#')
		return (tab);
	ft_left(tab);
	printf("new tetri :%s\n", tab);
	return (tab);
}
