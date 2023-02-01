/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error418.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:40:19 by wluedara          #+#    #+#             */
/*   Updated: 2023/01/31 18:01:36 by wluedara         ###   ########.fr       */
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
	pim_str(s);
	if (mode == 1)
		exit(EXIT_FAILURE);
}