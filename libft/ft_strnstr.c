/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 10:48:01 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/14 16:59:24 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_checker2(char *s1, char *s2, size_t len)
{
	int		o;
	int		i;

	o = 0;
	i = 0;
	while (s2[o])
		o++;
	while (s1[i] == s2[i] && s2[i] != '\0' && i < (int)len)
	{
		i++;
	}
	if (i == o)
		return (1);
	else
		return (0);
}

char		*ft_strnstr(const char *big, const char *small, size_t len)
{
	char	*pb;
	char	*ps;
	size_t	n;

	pb = (char*)big;
	ps = (char*)small;
	n = 0;
	if (*small == '\0')
		return (pb);
	if (*ps == '\0')
		return (pb);
	while (n < len)
	{
		if (pb[n] == 0)
			return (NULL);
		if (pb[n] == ps[0])
		{
			if (ft_checker2(&pb[n], ps, len - n))
				return (&pb[n]);
		}
		n++;
	}
	return (NULL);
}
