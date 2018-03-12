/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:27:10 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/15 12:41:55 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *out, const void *in, size_t n)
{
	unsigned char		*s1;
	size_t				i;
	unsigned const char	*s2;

	i = 0;
	s1 = out;
	s2 = in;
	if (out == NULL && in == NULL)
		return (0);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
