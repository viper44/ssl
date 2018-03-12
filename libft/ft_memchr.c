/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:57:11 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/15 12:46:16 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *src, int c, size_t lenght)
{
	unsigned char		*s1;
	size_t				i;

	s1 = (unsigned char*)src;
	i = 0;
	while (i < lenght)
	{
		if (*s1 == ((unsigned char)c))
			return (s1);
		i++;
		s1++;
	}
	return (NULL);
}
