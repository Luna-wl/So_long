/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:26:28 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/09 16:35:00 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walking(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x] == '0' || mlx->map[y][x] == 'C')
	{
		mlx->kao++;
		if (mlx->map[y][x] == 'C')
			mlx->collect--;
		return (1);
	}
	if (mlx->map[y][x] == 'E')
	{
		mlx->kao++;
		if (mlx->collect == 0)
			end_game(mlx);
		else
			return (1);
	}
	return (0);
}

void	dern_keun(t_mlx *mlx, int x, int y)
{
	if (check_walking(mlx, x, y))
	{
		mlx->map[y][x] = 'P';
		mlx->map[y + 1][x] = '0';
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
		mlx->map[y][x] = 'P';
		mlx->map[y - 1][x] = '0';
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
		mlx->map[y][x] = 'P';
		mlx->map[y][x + 1] = '0';
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
		mlx->map[y][x] = 'P';
		mlx->map[y][x - 1] = '0';
		mlx->start_x = x;
		mlx->start_y = y;
		ft_printf(YEL"Step: %d\n"RESET, mlx->kao);
		pim_map(mlx);
	}
	return ;
}

void	end_game(t_mlx *mlx)
{
	free_my_mlx(mlx);
	pim_str(GRN"----> Game Complete <----\n"RESET);
	exit(1);
}