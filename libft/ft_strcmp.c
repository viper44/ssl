/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:03:33 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/06 14:10:31 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *a, const char *b)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] == b[i])
			i++;
		else
			return ((unsigned char)a[i] - (unsigned char)b[i]);
	}
	return (0);
}
