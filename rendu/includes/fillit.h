/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:39:40 by jebrocho          #+#    #+#             */
/*   Updated: 2018/12/14 17:34:51 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/includes/libft.h"

# define BIG_IF c[0] + d[0] - c[2] < ft_sqrt(f[1] * 4)
# define BIG_IF2 f[0] && c[1] + d[1] - c[3] < ft_sqrt(f[1] * 4)
# define BIG_IF3 f[0] && map[c[0] + d[0] - c[2]][c[1] + d[1] - c[3]] == '.'
# define BIG_IF4 c[0] == ft_sqrt(f[1] * 4)
# define BIG_IF5 f[0] - 1 && c[1] == ft_sqrt(f[1] * 4) + f[0] - 1
# define FAT_IF ft_printnmove(c,d,map, tetri)
# define FAT_ELSE (map = ft_back_tetri(map, l, c, d))

int		ft_checkall(char *tab);
int		ft_check_line(char *line);
int		ft_usage(void);
void	ft_algo(char **tetrimino, char l[1], int nb_tetri);
char	**ft_create_map(int nb_tetri, char **map, int feed[1]);
void	ft_display_map(char **map);
int		ft_check_void(int nb_tetri, int check);
void	clearmap(char **tab);
void	ft_clear_stock(char *stock[5]);
int		ft_check_nbtetri(int t[3], char *line, char **av);
char	*ft_join_tetri(char *stock[5], char *tetra, int i);
int		ft_delncheck(char *stock[5], char *tetra, int i);
void	ft_move_tetri(int c[7]);
void	ft_first_stock(int c[7], int d[2]);
char	**ft_create_map2(int nb_tetri, char **map, int c[7]);
void	ft_move_map(int c[7]);
int		ft_check_map(char **map);
void	ft_printnmove(int c[7], int d[2], char **map, char **tetri);
char	**ft_back_tetri(char **map, char l[1], int c[7], int d[2]);
char	**ft_rm_tetri(char **map, char letter[1], int mod);
void	ft_map_pos(char **map, int c[7]);
void	ft_init(char **map, int c[7], int f[2]);
char	**ft_prev_back_map(char **map, int d[2], int f[4]);
void	ft_end(char l[1], int d[2]);
void	ft_reset(int c[7]);
void	ft_move_the_map(char **map, int c[7], char l[1]);
void	ft_move_the_tetri(char **tetri, int c[7], int d[2]);
char	**back_the_map(char **map, int d[2], int f[4]);

#endif
