/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:55:13 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/07 14:30:52 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	mem = (char*)malloc(sizeof(char) * size);
	if (mem == NULL)
		return (0);
	while (size != 0)
	{
		mem[i] = 0;
		i++;
		size--;
	}
	return (mem);
}
