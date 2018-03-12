/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:40:12 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/14 15:46:49 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_new_string(char *s, int i, unsigned int p, int m)
{
	int				k;

	k = 0;
	while (i >= 0)
	{
		k = p % 10;
		p = p / 10;
		s[i] = k + 48;
		i--;
	}
	if (m > 0)
		s[0] = '-';
	return (s);
}

char				*ft_itoa(int n)
{
	t_var			v;
	char			*s;
	unsigned int	p;

	v.i = 0;
	v.m = 0;
	if (n < 0)
	{
		v.m = 1;
		n = -n;
	}
	if (n == 0)
		v.i++;
	p = n;
	while (n != 0)
	{
		n = n / 10;
		v.i++;
	}
	s = (char*)malloc(sizeof(char) * (v.i + v.m) + 1);
	if (s == NULL)
		return (NULL);
	s[v.i + v.m] = '\0';
	v.i = v.i + v.m - 1;
	return (ft_new_string(s, v.i, p, v.m));
}
