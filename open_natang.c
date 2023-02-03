/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_natang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:33:04 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/03 23:17:41 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pid_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	lop_song_stars(mlx->map);
	exit(0);
}

void	komnod(t_mlx *mlx, t_game *game)
{
	mlx->win = 0;
	mlx->init = 0;
	mlx->player = 0;
	mlx->enemy = 0;
	mlx->exit = 0;
	mlx->collectible = 0;
	mlx->floor = 0;
	mlx->wall = 0;
	mlx->width = game->x;
	mlx->hight = game->y;
}

int	key_hook(int key_code, t_mlx *mlx)
{
	int	row;
	int	col;

	row = mlx->width;
	col = mlx->hight;
	if (key_code == KEY_ESC)
		pid_win(mlx);
	return (0);
}

void	sesame_mlx(t_game *game, t_mlx *mlx)
{
	komnod(mlx, game);
	// mlx->init = mlx_init();
	// mlx->win = mlx_new_window(mlx->init, mlx->width, mlx->hight, "My awesome So_long >3<");
	// mlx_key_hook(mlx->win, key_hook, mlx);
	// mlx_hook(mlx->win, 17, 0L, pid_win, mlx);
	// mlx_loop(mlx->init);
}