/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:28:17 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/06 14:10:05 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dst, const char *src, size_t length)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (dst[i] != '\0')
		i++;
	while (src[n] != '\0' && length > 0)
	{
		dst[i] = src[n];
		n++;
		i++;
		length--;
	}
	dst[i] = '\0';
	return (dst);
}
