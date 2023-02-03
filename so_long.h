/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:52:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/02 20:27:03 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./gnl/get_next_line.h"

//color
# define RESET	"\x1b[0m"
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define PP		"\x1B[35m"
# define CYA	"\x1B[36m"
# define BBY	"\x1B[43;1m"
# define BBC	"\x1B[46;1m"
# define BR		"\x1B[41;1m"


typedef struct s_game {
	int		hight;
	int		width;
	char	**map;
	int		collect;
	int		x;
	int		y;
}			t_game;

//utils
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(char *map, char *sth, unsigned int n);
void	lop_split(char **str);
//split
int		check_word(char *s, char c);
int		count_letter(char *s, char c);
char	*my_split(char *s, char c);
char	**ft_split(char *s, char c);
//read map
char	*maps_read(int fd, t_game *game);
void	get_maps(char *file, t_game *game);
//check map
void	check_map_name(char *map, char *file);
void	nap_player_thang_org(char *map, int len);
void	nap_items(char *map, int len, t_game *game);
int		check_kamphaeng(t_game *game);
void	check_sth(char *map, int len);
//error message
void	pim_error(char *s, int mode);
void	pim_str(char *s);

#endif