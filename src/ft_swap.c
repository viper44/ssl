/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char	*ft_xor2(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] == '0' && str2[i] == '0')
			str1[i] = '0';
		else if ((str1[i] == '1' && str2[i] == '0') ||
			(str1[i] == '0' && str2[i] == '1'))
			str1[i] = '1';
		else
			str1[i] = '0';
		i++;
	}
	return (str1);
}

void	ft_swap(t_ssl *ssl)
{
	char	*tmp;

	tmp = ft_strdup(ssl->half_r_m);
	ssl->half_r_m = ft_xor2(ssl->new_hrm, ssl->half_l_m);
	ssl->half_l_m = tmp;
	ssl->raund++;
}