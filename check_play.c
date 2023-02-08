/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:43:46 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/07 00:13:32 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ha_po_start(t_game *game)
{
	t_game	map;

	map.y = 0;
	while (map.y < game->high)
	{
		map.x = 0;
		while (map.x < game->width)
		{
			if (game->map[map.y][map.x] == 'P')
			{
				game->y = map.y;
				game->x = map.x;
			}
			map.x++;
		}
		map.y++;
	}
}

char	**do_new_map(char **map, t_game *game)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * (game->high + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (map[i])
	{
		tmp[i] = ft_strdup(map[i]);
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

void	flood(int x, int y , char **map, t_game *game)
{
	if (map == NULL)
		return ;
	if (x < 0 || y < 0 || x > game->width || y > game->high || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		game->fill_c++;
	if (map[y][x] == 'E')
		game->fill_e++;
	map[y][x] = '1';
	flood(x - 1, y, map, game);
	flood(x, y - 1, map, game);
	flood(x + 1, y, map, game);
	flood(x, y + 1, map, game);
}

void	len_dai_mai(t_game *game)
{
	char	**new_map;
	t_game	map;

	ha_po_start(game);
	map.x = game->x;
	map.y = game->y;
	new_map = do_new_map(game->map, game);
	game->fill_c = 0;
	game->fill_e = 0;
	flood(map.x, map.y, new_map, game);
	if (game->fill_c != game->collect && game->fill_e != 1)
		pim_error("-w-\n", game, 0);
	// for (int i = 0; new_map[i]; i++)
	// {
	// 	printf("map[%d] = %s\n", i, new_map[i]);
	// }
	lop_song_stars(new_map);
}