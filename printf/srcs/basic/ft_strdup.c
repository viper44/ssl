/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:53:56 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/15 12:49:40 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

char		*ft_strdup(const char *str)
{
	size_t	n;
	char	*tmp;
	size_t	i;

	i = 0;
	n = 0;
	while (str[i] != '\0')
		i++;
	if ((tmp = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	while (n < i)
	{
		tmp[n] = str[n];
		n++;
	}
	tmp[n] = '\0';
	return (tmp);
}
