/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:12:52 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/03 23:42:19 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*maps_read(int fd, t_game *game)
{
	char	*thaeo;
	char	*maps;

	thaeo = get_next_line(fd);
	game->hight = 0;
	game->width = ft_strlen(thaeo) - 1;
	maps = malloc(sizeof(char));
	if (!maps)
		return (0);
	maps[0] = '\0';
	maps = ft_strjoin(maps, thaeo);
	free(thaeo);
	while (thaeo)
	{
		game->hight++;
		thaeo = get_next_line(fd);
		if (thaeo)
			maps = ft_strjoin(maps, thaeo);
		free(thaeo);
	}
	close(fd);
	return (maps);
}

void	truat_map(t_game *game, char *line)
{
	int		len;
	int		len_map;

	len = ft_strlen(line);
	len_map = (len - game->hight) + 1;
	if ((game->hight * game->width) != len_map)
		pim_error(BLU"Do you call this {rectangular}? (☉̃ₒ☉)\n", game, 0);
	if (check_kamphaeng(game) == 0)
		pim_error(CYA"Mai me map ti dee kwa ne laew ror? (๑´╹‸╹`๑)\n", game, 0);
	nap_player_thang_org(line, len, game);
	nap_items(line, len, game);
	check_sth(line, len, game);
	len_dai_mai(game);
}

void	get_maps(char *file, t_game *game)
{
	char	*map_line;
	int		fd;
	int		i = 0;

	check_map_name(file, ".ber", game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		pim_error(YEL"Poet mai dai!!! (ಥ﹏ಥ)\n", game, 1);
	map_line = maps_read(fd, game);
	game->map = ft_split(map_line, '\n');
	// for (int i = 0; map[i]; i++)
	// {
	// 	printf("map[%d] = %s\n", i, map[i]);
	// }
	truat_map(game, map_line);
	free(map_line);
}
