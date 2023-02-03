/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error418.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:40:19 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/04 00:19:38 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lop_song_stars(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	pim_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	pim_error(char *s, t_game *game, int mode)
{
	pim_str(RED"Error\n"RESET);
	pim_str(s);
	if (mode == 1)
		exit(EXIT_FAILURE);
	else
	{
		if (game->map)
			lop_song_stars(game->map);
		free(game);
		exit(0);
	}
}
