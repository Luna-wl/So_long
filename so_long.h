/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:52:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/01/30 14:41:00 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./gnl/get_next_line.h"

typedef struct s_game {
	int	hight;
	int	width;
}	t_game;

//check map
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(char *map, char *sth, unsigned int n);
void	check_map_name(char *map, char *file);
//error message
void	pim_error(char *s, int mode);

#endif