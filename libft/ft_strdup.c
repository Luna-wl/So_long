/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:28:11 by wluedara          #+#    #+#             */
/*   Updated: 2023/02/03 11:11:03 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*dest;
	char	*str;
	int		len;
	int		i;

	str = (char *)s1;
	len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
