/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_too.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:11:43 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/07 13:14:00 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen_no_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void	check_siliam(t_game *game)
{
	t_game	map;
	int		line;
	
	map.y = 0;
	line = 0;
	while (map.y < game->high)
	{
		line = strlen_no_newline(game->map[map.y]);
		if (line != game->width)
			pim_error(BLU"Do you call this {rectangular}? (☉̃ₒ☉)\n", game, 0);
		map.y++;
	}
}

int	check_kamphaeng(t_game *game)
{
	t_game	map;

	map.y = 0;
	while (map.y < game->high)
	{
		map.x = 0;
		while (map.x < game->width)
		{
			if (map.y == 0 || map.y == (game->high - 1))
			{
				if (game->map[map.y][map.x] != '1')
					return (0);
			}
			else if (map.x == 0 || map.x == (game->width - 1))
			{
				if (game->map[map.y][map.x] != '1')
					return (0);
			}
			map.x++;
		}
		map.y++;
	}
	return (1);
}
