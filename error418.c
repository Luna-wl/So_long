/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error418.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:40:19 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/02 19:41:09 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	pim_error(char *s, int mode)
{
	pim_str(RED"Error\n"RESET);
	pim_str(s);
	if (mode == 1)
		exit(EXIT_FAILURE);
	else
		exit(0);
}
