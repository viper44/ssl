/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:57:44 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/05 15:48:04 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin2(char const *s1, char const *s2, int del)
{
	char	*s_new;
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s_new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s_new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s_new[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
		s_new[i++] = s2[n++];
	s_new[i] = '\0';
	if (del == 1)
		free((char*)s1);
	else if(del == 2)
		free((char*)s2);
	return (s_new);
}
