/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:36:41 by ezonda            #+#    #+#             */
/*   Updated: 2018/12/01 16:05:01 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_is_valid(char **line)
{
	int sharp = 0;
	int dot = 0;
	int i = 0;
	int j = 0;

	while (line[i][j] && (line[i][j] == '.' || line[i][j] == '#'))
	{
		if (line[i][j] == '.')
		{
			dot++;
			if (dot > 12)
			{
				printf("error");
				return ;
			}
			i++;
		}
		else if (line[i][j] == '#')
		{
			sharp++;
			if (sharp > 4)
			{
				printf("error");
				return ;
			}
			i++;
		}
		else
		{
			printf("error");
			return ;
		}
		if (ft_strlen(line[i]) == 4)
		{
			i = 0;
			j++;
		}
	}
}

int		main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *line;

	(void)ac;
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		ft_is_valid(&line);
		free(line);
	}
	return (0);
}
