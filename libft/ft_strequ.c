/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:32:44 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/07 14:29:04 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (len1 != len2)
			return (0);
		else
		{
			while (i < len1)
			{
				if (s1[i] == s2[i])
					i++;
				else
					return (0);
			}
		}
	}
	return (1);
}
