/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:22:50 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/07 14:29:51 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*a;
	size_t	n;

	a = NULL;
	i = 0;
	if (s != NULL)
	{
		n = ft_strlen(s);
		a = (char*)malloc(sizeof(char) * n + 1);
		if (a != NULL)
		{
			while (i < n)
			{
				a[i] = f(s[i]);
				i++;
			}
			a[i] = '\0';
		}
	}
	return (a);
}
