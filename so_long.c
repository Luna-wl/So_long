/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:50:54 by wluedara          #+#    #+#             */
/*   Updated: 2023/01/30 14:48:35 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_maps(char *map)
{
	int		fd;
	int		i;
	char	*thaeo;

	check_map_name(map, ".ber");
	fd = open(map, O_RDONLY);
	printf("fd = %d\n", fd);
	if (fd < 0)
		pim_error("Poet mai dai!!! (ಥ﹏ಥ)\n", 1);
	thaeo = get_next_line(fd);
	i = 1;
	while (thaeo && i <= 10)
	{
		printf("line%d: %s", i, thaeo);
		free(thaeo);
		thaeo = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		get_maps(av[1]);
	}
	else if (ac > 2)
		pim_error("Disculpe?, Do u know how to run this project? (눈_눈)\n", 1);
	else
		pim_error("Mai me map kah!! (ノಠ益ಠ)ノ彡┻━┻\n", 1);
	return (0);
}