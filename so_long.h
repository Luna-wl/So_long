/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:52:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/03 23:16:07 by wluedara         ###   ########.fr       */
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
# include "./mlx/mlx.h"

# define X_EVENT_KEY_EXIT		17
# define KEY_CTRL				56
# define KEY_ENTER				36
# define KEY_SPACE				49
# define KEY_ESC				53
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_W					13
# define KEY_R					15

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

typedef struct s_mlx {
	char	**map;
	void	*win;
	void	*init;
	void	*player;
	void	*enemy;
	void	*exit;
	void	*collectible;
	void	*floor;
	void	*wall;
	int		width;
	int		hight;
}			t_mlx;

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
void	lop_song_stars(char **str);
//read map
char	*maps_read(int fd, t_game *game);
void	get_maps(char *file, t_game *game);
//check map
void	check_map_name(char *map, char *file, t_game *game);
void	nap_player_thang_org(char *map, int len, t_game *game);
void	nap_items(char *map, int len, t_game *game);
int		check_kamphaeng(t_game *game);
void	check_sth(char *map, int len, t_game *game);
//error message
void	pim_error(char *s, t_game *game, int mode);
void	pim_str(char *s);
//flood fill
void	len_dai_mai(t_game *game);
void	ha_po_start(t_game *game);
char	**do_new_map(char **map, t_game *game);
void	flood(int x, int y, char **map, t_game *game);
//mlx
void	sesame_mlx(t_game *game, t_mlx *mlx);
int		key_hook(int key_code, t_mlx *mlx);
void	komnod(t_mlx *mlx, t_game *game);
void	pid_win(t_mlx *mlx);

#endif