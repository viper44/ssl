/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_perm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static int					g_final_perm[64] = \
{40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};

char *final_perm(char *str)
{
	char *ret;
	int	i;

	i = 0;
	ret = ft_strnew(64);
	while (i < 64)
	{
		ret[i] = str[g_final_perm[i] - 1];
		i++;
	}
	free(str);
	return (ret);
}
