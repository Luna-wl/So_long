/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:52:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/10 23:58:50 by wluedara         ###   ########.fr       */
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

# ifndef KEY_H
#  define KEY_H
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
# endif
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

typedef struct s_xy {
	int		x;
	int		y;
}			t_xy;

typedef struct s_img {
	void	*player;
	void	*enemy;
	void	*exit;
	void	*collect;
	void	*floor;
	void	*wall;
}			t_img;

typedef struct s_mlx {
	char	**map;
	void	*win;
	void	*init;
	t_img	img;
	int		size;
	int		start_x;
	int		start_y;
	int		exit_x;
	int		exit_y;
	int		pre_e_x;
	int		pre_e_y;
	int		kao;
	int		collect;
	int		row;
	int		col;
}			t_mlx;

typedef struct s_game {
	int		high;
	int		width;
	char	**map;
	int		collect;
	int		fill_c;
	int		fill_e;
	int		x;
	int		y;
}			t_game;
//global
t_xy	g_xy;

void	init_xy(void);
//utils
void	init(t_game *game);
void	lop_song_stars(char **str);
//read map
void	nab_line(char *file, t_game *game);
void	maps_read(char *file, t_game *game);
void	get_maps(char *file, t_game *game);
//check map
int		strlen_no_newline(char *str);
void	check_siliam(t_game *game);
void	truat_map(t_game *game);
void	check_map_name(char *map, char *file, t_game *game);
void	nap_player(t_game *game);
void	nap_thang_org(t_game *game);
void	nap_items(t_game *game);
int		check_kamphaeng(t_game *game);
void	check_sth(t_game *game);
//error message
void	pim_error(char *s, t_game *game, int mode);
void	pim_str(char *s);
//flood fill
void	len_dai_mai(t_game *game);
void	ha_po_start(t_game *game);
char	**do_new_map(char **map, t_game *game);
void	flood(int x, int y, char **map, t_game *game);
//mlx
int		pid_win(t_mlx *mlx);
void	komnod(t_mlx *mlx, t_game *game);
void	copy_map(t_game *game, t_mlx *mlx);
int		key_hook(int key_code, t_mlx *mlx);
void	sesame_mlx(t_game *game, t_mlx *mlx);
//walking
int		check_walking(t_mlx *mlx, int x, int y);
void	end_game(t_mlx *mlx);
void	dern_keun(t_mlx *mlx, int x, int y);
void	dern_long(t_mlx *mlx, int x, int y);
void	dern_sai(t_mlx *mlx, int x, int y);
void	dern_kwa(t_mlx *mlx, int x, int y);
//free
void	free_game(t_game *game);
void	free_my_mlx(t_mlx *mlx); 
//show map
void	pim_map(t_mlx *mlx);
//render
void	render_game(t_mlx *mlx);
void	render_floor(t_mlx *mlx);
void	render_wall(t_mlx *mlx);
void	render_player(t_mlx *mlx);
void	render_collectible(t_mlx *mlx);
void	render_exit(t_mlx *mlx);

#endif