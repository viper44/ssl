/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reveres_itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 09:08:10 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/16 09:08:11 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int		ft_reveres_itoa(char *str, int base)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	//printf("str = %s\n", str);
	while (base >= 1)
	{
		if (str[i] == '1')
			ret = base + ret;
		base /= 2;
		i++;
	}
	//printf("ret = %d\n", ret);
	return (ret);
}
