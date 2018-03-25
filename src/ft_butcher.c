/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_butcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

char	*ft_butcher(char *str)
{
	int 	i;
	int 	n;
	char 	*line;

	n = 0;
	i = ft_strlen(str);
	line = ft_strnew(0);
	if (ft_strlen(str) % 64 != 0)
	{
		while (i >= 64)
		{
			line = ft_strjoin2(line, ft_strsub(str, n, 64), 1);
			n += 64;
			i -= 64;
		}
	}
	return (line);
}
