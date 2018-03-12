/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_same.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:33:17 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/20 11:33:20 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_swap(char *s1, int start, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		s1[start - 1] = 32;
		start--;
		i++;
	}
	return (s1);
}

char		*ft_del_same(char *big, char *small)
{
	t_pack	xxx;

	xxx.count = 0;
	xxx.n = 0;
	xxx.m = 0;
	xxx.o = ft_strlen(small);
	while (big[xxx.n] != '\0')
	{
		while (big[xxx.n] == small[xxx.m] && small[xxx.m] != '\0')
		{
			xxx.n++;
			xxx.m++;
		}
		if (xxx.m == xxx.o)
			xxx.count++;
		xxx.m = 0;
		if (xxx.count > 1)
		{
			ft_swap(big, xxx.n, xxx.o);
			xxx.count--;
		}
		xxx.n++;
	}
	return (big);
}
