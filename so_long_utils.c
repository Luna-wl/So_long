/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:51:15 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/01 17:38:02 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(char *map, char *sth, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((map[i] != '\0' || sth[i] != '\0') && i < n)
	{
		if (map[i] != sth[i])
			return (map[i] - sth[i]);
		i++;
	}
	return (0);
}

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*s;
	char	ch;

	ch = c;
	s = (char *)str;
	len = ft_strlen(s) - 1;
	if (ch == '\0')
		return (&s[len + 1]);
	while (len >= 0)
	{
		if (s[len] == ch)
			return (&s[len]);
		len--;
	}
	return (0);
}

void	lop_split(char **str)
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
