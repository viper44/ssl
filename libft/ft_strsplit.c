/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:28:27 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/15 14:42:13 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(const char *s, char c)
{
	int			i;
	int			n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if ((s[0] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			n++;
		i++;
	}
	return (n);
}

static int		ft_iter(char *s, char c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

static t_var	varible(void)
{
	t_var		v;

	v.m = 0;
	v.i = 0;
	v.p = 0;
	return (v);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**s2;
	t_var		v;

	v = varible();
	if (s == NULL)
		return (NULL);
	v.n = ft_word_count(s, c);
	if (!(s2 = (char **)malloc(sizeof(char*) * v.n + 1)))
		return (NULL);
	while (s[v.i] != '\0')
	{
		v.i = ft_iter((char*)s, c, v.i);
		v.o = v.i;
		while (s[v.i] != c && s[v.i] != '\0')
			v.i++;
		v.k = v.i - v.o;
		if (v.n-- != 0)
		{
			if (!(s2[v.m] = (char*)malloc(sizeof(char) * v.k + 1)))
				return (NULL);
			s2[v.m++] = ft_strsub(s, v.o, v.k);
		}
	}
	s2[v.m] = (char*)'\0';
	return (s2);
}
