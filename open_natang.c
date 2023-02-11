/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_natang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:33:04 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/11 18:42:05 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pid_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	free_my_mlx(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	pic_player(t_mlx *mlx)
{
	mlx->img.p1 = "./image/P.xpm";
	mlx->img.p2 = "./image/P2.xpm";
	mlx->img.p3 = "./image/P3.xpm";
}

void	komnod(t_mlx *mlx, t_game *game)
{
	mlx->win = 0;
	mlx->init = 0;
	pic_player(mlx);
	mlx->img.player = 0;
	mlx->img.exit = 0;
	mlx->img.collect = 0;
	mlx->img.floor = 0;
	mlx->img.wall = 0;
	mlx->kao = 0;
	mlx->exit_x = 0;
	mlx->exit_y = 0;
	mlx->size = 64;
	mlx->collect = game->collect;
	mlx->col = game->high;
	mlx->row = game->width;
	mlx->start_x = game->x;
	mlx->start_y = game->y;
	copy_map(game, mlx);
}

void	copy_map(t_game *game, t_mlx *mlx)
{
	int	y;

	y = 0;
	mlx->map = malloc(sizeof(char *) * (game->high + 1));
	while (y < game->high)
	{
		mlx->map[y] = ft_strdup(game->map[y]);
		y++;
	}
}

int	key_hook(int key_code, t_mlx *mlx)
{
	int	x;
	int	y;

	x = mlx->start_x;
	y = mlx->start_y;
	if (key_code == KEY_ESC)
		pid_win(mlx);
	if (key_code == KEY_UP || key_code == KEY_W)
		dern_keun(mlx, x, y - 1);
	else if (key_code == KEY_DOWN || key_code == KEY_S)
		dern_long(mlx, x, y + 1);
	else if (key_code == KEY_LEFT || key_code == KEY_A)
		dern_sai(mlx, x - 1, y);
	else if (key_code == KEY_RIGHT || key_code == KEY_D)
		dern_kwa(mlx, x + 1, y);
	return (0);
}

void	sesame_mlx(t_game *game, t_mlx *mlx)
{
	komnod(mlx, game);
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, mlx->row * 64, mlx->col * 64, \
	"My awesome So_long >3<");
	render_floor(mlx);
	render_game(mlx);
	free_game(game);
	mlx_hook(mlx->win, 17, 1L << 0, pid_win, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_loop_hook(mlx->init, looping, mlx);
	mlx_loop(mlx->init);
}
