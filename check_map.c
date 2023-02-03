/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:35:54 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/03 10:28:26 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_name(char *map, char *file)
{
	int		len;
	char	*ber;

	ber = ft_strrchr(map, '.');
	len = ft_strlen(ber);
	if (ft_strncmp(ber, file, len) != 0)
		pim_error(RED"Ru jak [.ber] mai kah. つ´Д`)つ\n", 1);
}

void	nap_player_thang_org(char *map, int len)
{
	int	i;
	int	p;
	int	exit;

	i = 0;
	p = 0;
	exit = 0;
	while (i++ < len)
	{
		if (map[i] == 'P')
			p++;
		if (map[i] == 'E')
			exit++;
	}
	if (p == 0)
		pim_error(GRN"Do u know that we need player in game? (´･ω･`)\n", 0);
	else if (p > 1)
		pim_error(YEL"Really? player > 1 Σ(￣ロ￣lll)\n", 0);
	if (exit == 0)
		pim_error(BLU"Do u know that game must have exit? (╯⊙ ⊱ ⊙╰ )\n", 0);
	else if (exit > 1)
		pim_error(PP"Game can have only 1 exit. _へ__(‾◡◝ )\n", 0);
}

void	nap_items(char *map, int len, t_game *game)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	game->collect = 0;
	while (i++ < len)
	{
		if (map[i] == 'C')
		{
			game->collect++;
			c++;
		}
	}
	if (c == 0)
		pim_error(CYA"Where is my item? (╬ ≖_≖)つ\n", 0);
}

int	check_kamphaeng(t_game *game)
{
	t_game	map;

	map.y = 0;
	while (map.y < game->hight)
	{
		map.x = 0;
		while (map.x < game->width)
		{
			if (map.y == 0 || map.y == (game->hight - 1))
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

void	check_sth(char *map, int len)
{
	int	i;
	int	who;

	i = 0;
	who = 0;
	while (i++ < len - 1)
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'C' \
		&& map[i] != 'P' && map[i] != 'E' && map[i] != '\n')
			who++;
	}
	if (who != 0)
		pim_error(CYA"What have u done with the map? ಠ.ಠ)\n", 0);
}
