/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:41:49 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/15 12:32:18 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*s_new;
	size_t			i;

	i = 0;
	s_new = NULL;
	if (s != NULL)
	{
		s_new = (char*)malloc(sizeof(char) * len + 1);
		if (s_new == NULL)
			return (NULL);
		while (i < len)
		{
			s_new[i] = s[start];
			i++;
			start++;
		}
		s_new[i] = '\0';
	}
	return (s_new);
}
