/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:50:54 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/06 22:23:28 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	t_mlx	*mlx;

	game = NULL;
	mlx = NULL;
	if (ac == 2)
	{
		game = malloc(sizeof(t_game));
		mlx = malloc(sizeof(t_mlx));
		init(game);
		get_maps(av[1], game);
		// sesame_mlx(game, mlx);
		lop_song_stars(game->map);
		free(game);
	}
	else if (ac > 2)
		pim_error(BBC"Disculpe?, Do u know how to run this project? (눈_눈)\n", game, 1);
	else
		pim_error(BLU"Mai me map kah!! (ノಠ益ಠ)ノ彡┻━┻\n", game, 1);
	return (0);
}

//malloc game in main
//malloc map in read_map.c
//malloc in split -> lop_split(game->map) after use game->map;
//malloc in ft_strdup in check_play.c
//malloc mlx in open_natang.c