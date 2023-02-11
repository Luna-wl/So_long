/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_too.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:27:39 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/10 23:40:14 by wluedara         ###   ########.fr       */
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
	render_wall(mlx);
	render_collectible(mlx);
	render_exit(mlx);
	render_player(mlx);
}
