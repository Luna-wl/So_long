/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:52:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/10 23:59:49 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_xy(void)
{
	g_xy.x = 0;
	g_xy.y = 0;
}

void	render_wall(t_mlx *mlx)
{
	init_xy();
	while (g_xy.y < mlx->col)
	{
		g_xy.x = 0;
		while (g_xy.x < mlx->row)
		{
			if (mlx->map[g_xy.y][g_xy.x] == '1')
			{
				mlx->img.wall = mlx_xpm_file_to_image(mlx->init, \
				"./image/wall1_1.xpm", &mlx->size, &mlx->size);
				mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.wall, \
				(g_xy.x * mlx->size), (g_xy.y * mlx->size));
			}
			g_xy.x++;
		}
		g_xy.y++;
	}
}

void	render_player(t_mlx *mlx)
{
	init_xy();
	while (g_xy.y < mlx->col)
	{
		g_xy.x = 0;
		while (g_xy.x < mlx->row)
		{
			if (mlx->map[g_xy.y][g_xy.x] == 'P')
			{
				mlx->img.player = mlx_xpm_file_to_image(mlx->init, \
				"./image/P.xpm", &mlx->size, &mlx->size);
				mlx_put_image_to_window(mlx->init, mlx->win, \
				mlx->img.player, (g_xy.x * mlx->size), (g_xy.y * mlx->size));
			}
			g_xy.x++;
		}
		g_xy.y++;
	}
}

void	render_collectible(t_mlx *mlx)
{
	init_xy();
	while (g_xy.y < mlx->col)
	{
		g_xy.x = 0;
		while (g_xy.x < mlx->row)
		{
			if (mlx->map[g_xy.y][g_xy.x] == 'C')
			{
				mlx->img.collect = mlx_xpm_file_to_image(mlx->init, \
				"./image/C1_1.xpm", &mlx->size, &mlx->size);
				mlx_put_image_to_window(mlx->init, mlx->win, \
				mlx->img.collect, (g_xy.x * mlx->size), \
				(g_xy.y * mlx->size));
			}
			g_xy.x++;
		}
		g_xy.y++;
	}
}

void	render_exit(t_mlx *mlx)
{
	init_xy();
	while (g_xy.y < mlx->col)
	{
		g_xy.x = 0;
		while (g_xy.x < mlx->row)
		{
			if (mlx->map[g_xy.y][g_xy.x] == 'E')
			{
				mlx->img.exit = mlx_xpm_file_to_image(mlx->init, \
				"./image/e.xpm", &mlx->size, &mlx->size);
				mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.exit, \
				(g_xy.x * mlx->size), (g_xy.y * mlx->size));
			}
			g_xy.x++;
		}
		g_xy.y++;
	}
}
