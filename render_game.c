/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:52:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/11 18:37:54 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_xy(void)
{
	g_xy.x = 0;
	g_xy.y = 0;
}

void	render_wall(t_mlx *mlx, int y, int x)
{
	mlx->img.wall = mlx_xpm_file_to_image(mlx->init, \
	"./image/wall1_1.xpm", &mlx->size, &mlx->size);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.wall, \
	(x * mlx->size), (y * mlx->size));
}

void	render_player(t_mlx *mlx, int y, int x)
{
	mlx->img.player = mlx_xpm_file_to_image(mlx->init, \
	mlx->img.p1, &mlx->size, &mlx->size);
	mlx_put_image_to_window(mlx->init, mlx->win, \
	mlx->img.player, (x * mlx->size), (y * mlx->size));
}

void	render_collectible(t_mlx *mlx, int y, int x)
{
	mlx->img.collect = mlx_xpm_file_to_image(mlx->init, \
	"./image/C1_1.xpm", &mlx->size, &mlx->size);
	mlx_put_image_to_window(mlx->init, mlx->win, \
	mlx->img.collect, (x * mlx->size), \
	(y * mlx->size));
}

void	render_exit(t_mlx *mlx, int y, int x)
{
	mlx->img.exit = mlx_xpm_file_to_image(mlx->init, \
	"./image/e.xpm", &mlx->size, &mlx->size);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.exit, \
	(x * mlx->size), (y * mlx->size));
}

// void	render_wall(t_mlx *mlx)
// {
// 	init_xy();
// 	while (g_xy.y < mlx->col)
// 	{
// 		g_xy.x = 0;
// 		while (g_xy.x < mlx->row)
// 		{
// 			if (mlx->map[g_xy.y][g_xy.x] == '1')
// 			{
// 				mlx->img.wall = mlx_xpm_file_to_image(mlx->init, \
// 				"./image/wall1_1.xpm", &mlx->size, &mlx->size);
// 				mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.wall, \
// 				(g_xy.x * mlx->size), (g_xy.y * mlx->size));
// 			}
// 			g_xy.x++;
// 		}
// 		g_xy.y++;
// 	}
// }

// void	init_pic(t_mlx *mlx)
// {
// 	mlx->img.player = mlx_xpm_file_to_image(mlx->init, \
// 	mlx->img.p1, &mlx->size, &mlx->size);
// 	mlx->img.player = mlx_xpm_file_to_image(mlx->init, \
// 	mlx->img.p2, &mlx->size, &mlx->size);
// 	mlx->img.player = mlx_xpm_file_to_image(mlx->init, \
// 	mlx->img.p3, &mlx->size, &mlx->size);
// }

// void	render_player(t_mlx *mlx)
// {
// 	init_xy();
// 	while (g_xy.y < mlx->col)
// 	{
// 		g_xy.x = 0;
// 		while (g_xy.x < mlx->row)
// 		{
// 			if (mlx->map[g_xy.y][g_xy.x] == 'P')
// 			{
// 				mlx->img.player = mlx_xpm_file_to_image(mlx->init, \
// 				mlx->img.p1, &mlx->size, &mlx->size);
// 				mlx_put_image_to_window(mlx->init, mlx->win, \
// 				mlx->img.player, (g_xy.x * mlx->size), (g_xy.y * mlx->size));
// 			}
// 			g_xy.x++;
// 		}
// 		g_xy.y++;
// 	}
// }

// void	render_collectible(t_mlx *mlx)
// {
// 	init_xy();
// 	while (g_xy.y < mlx->col)
// 	{
// 		g_xy.x = 0;
// 		while (g_xy.x < mlx->row)
// 		{
// 			if (mlx->map[g_xy.y][g_xy.x] == 'C')
// 			{
// 				mlx->img.collect = mlx_xpm_file_to_image(mlx->init, \
// 				"./image/C1_1.xpm", &mlx->size, &mlx->size);
// 				mlx_put_image_to_window(mlx->init, mlx->win, \
// 				mlx->img.collect, (g_xy.x * mlx->size), \
// 				(g_xy.y * mlx->size));
// 			}
// 			g_xy.x++;
// 		}
// 		g_xy.y++;
// 	}
// }

// void	render_exit(t_mlx *mlx)
// {
// 	init_xy();
// 	while (g_xy.y < mlx->col)
// 	{
// 		g_xy.x = 0;
// 		while (g_xy.x < mlx->row)
// 		{
// 			if (mlx->map[g_xy.y][g_xy.x] == 'E')
// 			{
// 				mlx->img.exit = mlx_xpm_file_to_image(mlx->init, \
// 				"./image/e.xpm", &mlx->size, &mlx->size);
// 				mlx_put_image_to_window(mlx->init, mlx->win, mlx->img.exit, \
// 				(g_xy.x * mlx->size), (g_xy.y * mlx->size));
// 			}
// 			g_xy.x++;
// 		}
// 		g_xy.y++;
// 	}
// }
