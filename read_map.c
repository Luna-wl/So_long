/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:12:52 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/07 13:16:47 by wluedara         ###   ########.fr       */
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

int	nab_line(char *file, t_game *game)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		pim_error(YEL"Poet mai dai!!! (ಥ﹏ಥ)\n", game, 1);
	line = get_next_line(fd);
	count = 0;
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (count);
}

void	maps_read(char *file, t_game *game)
{
	int		i;
	int		fd;
	int		line;

	i = 0;
	line = nab_line(file, game);
	fd = open(file, O_RDONLY);
	game->map = malloc(sizeof(char *) * (line + 1));
	if (!game->map)
		return ;
	game->map[i] = get_next_line(fd);
	game->width = ft_strlen(game->map[i]) - 1;
	while (game->map[i])
	{
		i++;
		game->high++;
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
	printf(BLU"high[%d]"RESET, game->high);
	printf(BLU"width[%d]"RESET, game->width);
	// for (int i = 0; game->map[i]; i++)
	// {
	// 	printf(YEL"map[%d] = %s"RESET, i, game->map[i]);
	// }
	// printf("\n");
	truat_map(game);
}
