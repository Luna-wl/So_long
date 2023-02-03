/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:52:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/03 15:37:52 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./libft/ft_printf.h"
# include "./libft/get_next_line_bonus.h"

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
	int		fill_c;
	int		fill_e;
	int		x;
	int		y;
}			t_game;

//utils
void	lop_split(char **str);
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
//flood fill
void	len_dai_mai(t_game *game);
void	ha_po_start(t_game *game);
char	**do_new_map(char **map, t_game *game);
void	flood(int x, int y, char **map, t_game *game);

#endif