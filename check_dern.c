/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dern.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:50:29 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/10 21:51:38 by wluedara         ###   ########.fr       */
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
		mlx->exit_x = x;
		mlx->exit_y = y;
		mlx->kao++;
		if (mlx->collect == 0)
			end_game(mlx);
		else
			return (2);
	}
	return (0);
}

void	end_game(t_mlx *mlx)
{
	free_my_mlx(mlx);
	pim_str(GRN"----> You're the Winner <----\n"RESET);
	exit(1);
}

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
