/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_too.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:27:39 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/11 18:42:37 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_floor(t_mlx *mlx)
{
	init_xy();
	while (g_xy.y < mlx->col)
	{
		g_xy.x = 0;
		while (g_xy.x < mlx->row)
		{
			mlx->img.floor = mlx_xpm_file_to_image(mlx->init, \
			"./image/F3.xpm", &mlx->size, &mlx->size);
			mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.floor, \
			(g_xy.x * mlx->size), (g_xy.y * mlx->size));
			g_xy.x++;
		}
		g_xy.y++;
	}
}

void	render_game(t_mlx *mlx)
{
	init_xy();
	while (g_xy.y < mlx->col)
	{
		g_xy.x = 0;
		while (g_xy.x < mlx->row)
		{
			if (mlx->map[g_xy.y][g_xy.x] == '1')
				render_wall(mlx, g_xy.y, g_xy.x);
			else if (mlx->map[g_xy.y][g_xy.x] == 'C')
				render_collectible(mlx, g_xy.y, g_xy.x);
			else if (mlx->map[g_xy.y][g_xy.x] == 'E')
				render_exit(mlx, g_xy.y, g_xy.x);
			else if (mlx->map[g_xy.y][g_xy.x] == 'P')
				render_player(mlx, g_xy.y, g_xy.x);
			g_xy.x++;
		}
		g_xy.y++;
	}
}

int	looping(t_mlx *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	render_floor(mlx);
	render_game(mlx);
	return (0);
}
