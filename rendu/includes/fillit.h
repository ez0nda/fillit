/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:39:40 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/13 21:38:51 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"

int		ft_checkall(char *tab);
int		ft_check_line(char *line);
int		ft_usage(void);
void	ft_algo(char **tetrimino, char l[1], int nb_tetri);
char	**ft_create_map(int nb_tetri, char **map, int feed[1]);
void	ft_display_map(char **map);
char	**ft_rm_tetri2(char **map, char letter[1]);
int		ft_check_void(int nb_tetri, int check);
void	clearmap(char **tab);
void	ft_clear_stock(char *stock[5]);

#endif
