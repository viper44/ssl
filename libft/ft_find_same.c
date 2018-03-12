/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_same.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:27:48 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/20 10:27:49 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_same(char *big, char *small)
{
	int o;
	int count;
	int n;
	int m;

	count = 0;
	n = 0;
	m = 0;
	o = ft_strlen(small);
	while (big[n] != '\0')
	{
		while (big[n] == small[m] && small[m] != '\0')
		{
			n++;
			m++;
		}
		if (m == o)
			count++;
		m = 0;
		n++;
	}
	return (count);
}
