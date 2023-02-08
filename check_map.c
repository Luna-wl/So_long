/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:35:54 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/07 00:12:16 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_name(char *map, char *file, t_game *game)
{
	int		len;
	char	*ber;

	ber = ft_strrchr(map, '.');
	len = ft_strlen(ber);
	if (ft_strncmp(ber, file, len) != 0)
		pim_error(RED"Ru jak [.ber] mai kah. つ´Д`)つ\n", game, 0);
}

void	nap_player(t_game *game)
{
	t_game	m;
	int		p;

	p = 0;
	m.y = 0;
	while (m.y < game->high)
	{
		m.x = 0;
		while (m.x < game->width)
		{
			if (game->map[m.y][m.x] == 'P')
				p++;
			m.x++;
		}
		m.y++;
	}
	if (p == 0)
		pim_error(GRN"Do u know that we need player in game? (´･ω･`)\n" \
		, game, 0);
	else if (p > 1)
		pim_error(YEL"Really? player > 1 Σ(￣ロ￣lll)\n", game, 0);
}

void	nap_thang_org(t_game *game)
{
	t_game	m;
	int		exit;

	exit = 0;
	m.y = 0;
	while (m.y < game->high)
	{
		m.x = 0;
		while (m.x < game->width)
		{
			if (game->map[m.y][m.x] == 'E')
				exit++;
			m.x++;
		}
		m.y++;
	}
	if (exit == 0)
		pim_error(BLU"Do u know that game must have exit? (╯⊙ ⊱ ⊙╰ )\n", \
		game, 0);
	else if (exit > 1)
		pim_error(PP"Game can have only 1 exit. _へ__(‾◡◝ )\n", game, 0);
}

void	nap_items(t_game *game)
{
	t_game	map;
	int		c;

	map.y = 0;
	c = 0;
	game->collect = 0;
	while (map.y < game->high)
	{
		map.x = 0;
		while (map.x < game->width)
		{
			if (game->map[map.y][map.x] == 'C')
			{
				game->collect++;
				c++;
			}
			map.x++;
		}
		map.y++;
	}
	if (c == 0)
		pim_error(CYA"Where is my item? (╬ ≖_≖)つ\n", game, 0);
}

void	check_sth(t_game *game)
{
	int		who;
	int		y;
	int		x;

	who = 0;
	y = 0;
	while (y < game->high)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0' && \
			game->map[y][x] != 'C' && game->map[y][x] != 'P' && \
			game->map[y][x] != 'E')
				who++;
			x++;
		}
		y++;
	}
	if (who != 0)
		pim_error(CYA"What have u done with the map? ಠ.ಠ)\n", game, 0);
}
