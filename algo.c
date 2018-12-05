/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:58:57 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/05 17:24:56 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


char		**ft_algo(char **tetrimino, int i, int nb_tetri)
{
	static char		**tetri;
	static char		**resol = NULL;
	static int		k;

	if (i == 0)
	{
		tetri = tetrimino;
		return (NULL);
	}
	return (resol);
}
