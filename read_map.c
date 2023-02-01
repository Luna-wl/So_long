/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:12:52 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/01 14:01:55 by wluedara         ###   ########.fr       */
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
		if(thaeo)
			maps = ft_strjoin(maps, thaeo);
		free(thaeo);
	}
	close(fd);
	return (maps);
}

void	truat_map(t_game *game, char *line)
{
	(void)game;
	check_player(line);
}

void	get_maps(char *file, t_game *game)
{
	char	*map_line;
	int		fd;
	int		i = 0;

	check_map_name(file, ".ber");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		pim_error("Poet mai dai!!! (ಥ﹏ಥ)\n", 1);
	map_line = maps_read(fd, game);
	game->map = ft_split(map_line, '\n');
	while (game->map[i])
	{
		printf("map[%d] = %s\n", i, game->map[i]);
		i++;
	}
	// printf("map_line = \n%s\n", map_line);
	// printf("len map_line = %d\n", ft_strlen(map_line));
	truat_map(game, map_line);
	lop_split(game->map);
	free(map_line);
}