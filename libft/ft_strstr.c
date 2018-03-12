/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 09:01:49 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/14 15:45:11 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checker(char *s1, char *s2)
{
	int		o;
	int		i;

	o = 0;
	i = 0;
	while (s2[o])
		o++;
	while (s1[i] == s2[i] && s2[i] != '\0')
	{
		i++;
	}
	if (i == o)
		return (1);
	else
		return (0);
}

char		*ft_strstr(const char *big, const char *small)
{
	char	*pb;
	char	*ps;
	int		i;

	pb = (char*)big;
	ps = (char*)small;
	i = 0;
	if (*small == '\0')
		return (pb);
	if (*ps == '\0')
		return (pb);
	while (pb[i] != '\0')
	{
		if (pb[i] == ps[0])
		{
			if (ft_checker(&pb[i], ps))
				return (&pb[i]);
		}
		i++;
	}
	return (NULL);
}
