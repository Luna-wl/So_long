/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:00:21 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/11 18:05:03 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_step(t_mlx *mlx)
{
	char	*step;

	step = ft_itoa(mlx->kao);
	mlx_string_put(mlx->init, mlx->win, 750, 20, 125, "Step : ");
	mlx_string_put(mlx->init, mlx->win, 800, 20, 125, step);
	if (step)
		free(step);
}
