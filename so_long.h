/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:52:33 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/01 13:50:07 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./gnl/get_next_line.h"

typedef struct s_game {
	int		hight;
	int		width;
	char	**map;
}			t_game;

//utils
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(char *map, char *sth, unsigned int n);
int		strlen_no_newline(char *s);
void	lop_split(char **str);
//split
int		check_word(char *s, char c);
int		count_letter(char *s, char c);
char	*my_split(char *s, char c);
char	**ft_split(char *s, char c);
//read map
char	*maps_read(int fd, t_game *game);
void	get_maps(char *file, t_game *game);
//check map
void	check_map_name(char *map, char *file);
void	check_player(char *map);
//error message
void	pim_error(char *s, int mode);
void	pim_str(char *s);

#endif