/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:53:15 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/15 12:44:06 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t length)
{
	unsigned char		*dest;
	unsigned char		*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (dest == source)
		return (dst);
	if (dest > source)
	{
		dest = dest + length - 1;
		source = source + length - 1;
		while (length-- > 0)
			*(dest--) = *(source--);
		return (dst);
	}
	while (length != 0)
	{
		*dest++ = *source++;
		length--;
	}
	return (dst);
}
