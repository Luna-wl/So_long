/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:35:54 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/01 14:02:21 by wluedara         ###   ########.fr       */
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
		pim_error("Ru jak [.ber] mai kah. つ´Д`)つ\n", 1);
}

void	check_player(char *map)
{
	int	i;
	int	len;
	int	p;

	i = 0;
	p = 0;
	len = ft_strlen(map);
	while (i < len)
	{
		if (map[i] == 'P')
			p++;
		i++;
	}
	if (p == 0)
		pim_error("Do u know that we need player in game? (´･ω･`)\n", 1);
	else if (p > 1)
		pim_error("Really? player > 1 Σ(￣ロ￣lll)\n", 1);
}