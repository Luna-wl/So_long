/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_natang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:33:04 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/09 16:39:30 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pim_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[i])
	{
		ft_printf(CYA"%s"RESET, mlx->map[i]);
		i++;
	}
	write(1, "\n", 1);
}

int	pid_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	free_my_mlx(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	komnod(t_mlx *mlx, t_game *game)
{
	mlx->win = 0;
	mlx->init = 0;
	mlx->player = 0;
	mlx->enemy = 0;
	mlx->exit = 0;
	mlx->collectible = 0;
	mlx->collect = game->collect;
	mlx->floor = 0;
	mlx->wall = 0;
	mlx->kao = 0;
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
	mlx->win = mlx_new_window(mlx->init, game->width * 64, game->high * 64,\
	"My awesome So_long >3<");
	free(game);
	mlx_hook(mlx->win, 17, 1L<<0, pid_win, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	// mlx_loop_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->init);
}