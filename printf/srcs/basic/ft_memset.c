/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:19:10 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/15 12:41:41 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

void		*ft_memset(void *memptr, int val, size_t num)
{
	char	*s1;
	size_t	n;

	n = 0;
	s1 = memptr;
	while (n < num)
	{
		s1[n] = val;
		n++;
	}
	return (s1);
}
