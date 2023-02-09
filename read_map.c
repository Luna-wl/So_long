/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:12:52 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/09 12:45:18 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *game)
{
	game->collect = 0;
	game->fill_c = 0;
	game->fill_e = 0;
	game->high = 0;
	game->width = 0;
	game->x = 0;
	game->y = 0;
	game->map = NULL;
}

void	nab_line(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		pim_error(YEL"Poet mai dai!!! (ಥ﹏ಥ)\n", game, 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->high++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	maps_read(char *file, t_game *game)
{
	int		i;
	int		fd;
	int		line;

	i = 0;
	nab_line(file, game);
	fd = open(file, O_RDONLY);
	game->map = malloc(sizeof(char *) * (game->high + 1));
	if (!game->map)
		return ;
	game->map[i] = get_next_line(fd);
	game->width = ft_strlen(game->map[i]) - 1;
	while (game->map[i])
	{
		i++;
		game->map[i] = get_next_line(fd);
	}
	close(fd);
}

void	truat_map(t_game *game)
{
	check_siliam(game);
	if (check_kamphaeng(game) == 0)
		pim_error(CYA"Mai me map ti dee kwa ne laew ror? (๑´╹‸╹`๑)\n", game, 0);
	nap_player(game);
	nap_thang_org(game);
	nap_items(game);
	check_sth(game);
	len_dai_mai(game);
}

void	get_maps(char *file, t_game *game)
{
	check_map_name(file, ".ber", game);
	maps_read(file, game);
	truat_map(game);
}
