/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:26:28 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/10 21:52:05 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dern_keun(t_mlx *mlx, int x, int y)
{
	if (check_walking(mlx, x, y))
	{
		if (mlx->start_x == mlx->exit_x && mlx->start_y == mlx->exit_y)
			mlx->map[y + 1][x] = 'E';
		else
			mlx->map[y + 1][x] = '0';
		mlx->map[y][x] = 'P';
		mlx->start_x = x;
		mlx->start_y = y;
		ft_printf(YEL"Step: %d\n"RESET, mlx->kao);
		pim_map(mlx);
	}
	return ;
}

void	dern_long(t_mlx *mlx, int x, int y)
{
	if (check_walking(mlx, x, y))
	{
		if (mlx->start_x == mlx->exit_x && mlx->start_y == mlx->exit_y)
			mlx->map[y - 1][x] = 'E';
		else
			mlx->map[y - 1][x] = '0';
		mlx->map[y][x] = 'P';
		mlx->start_x = x;
		mlx->start_y = y;
		ft_printf(YEL"Step: %d\n"RESET, mlx->kao);
		pim_map(mlx);
	}
	return ;
}

void	dern_sai(t_mlx *mlx, int x, int y)
{
	if (check_walking(mlx, x, y))
	{
		if (mlx->start_x == mlx->exit_x && mlx->start_y == mlx->exit_y)
			mlx->map[y ][x + 1] = 'E';
		else
			mlx->map[y][x + 1] = '0';
		mlx->map[y][x] = 'P';
		mlx->start_x = x;
		mlx->start_y = y;
		ft_printf(YEL"Step: %d\n"RESET, mlx->kao);
		pim_map(mlx);
	}
	return ;
}

void	dern_kwa(t_mlx *mlx, int x, int y)
{
	if (check_walking(mlx, x, y))
	{
		if (mlx->start_x == mlx->exit_x && mlx->start_y == mlx->exit_y)
			mlx->map[y][x - 1] = 'E';
		else
			mlx->map[y][x - 1] = '0';
		mlx->map[y][x] = 'P';
		mlx->start_x = x;
		mlx->start_y = y;
		ft_printf(YEL"Step: %d\n"RESET, mlx->kao);
		pim_map(mlx);
	}
	return ;
}
