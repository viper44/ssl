/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_enc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static	int	g_plaintext_perm_tab[64] ={58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44,\
		36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24,\
		16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61,\
		53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};

static void	ft_split_mes(char *ret, t_ssl *ssl)
{
	int i;
	int n;

	i = 0;
	n = 0;
	ssl->half_l_m = ft_strnew(32);
	ssl->half_r_m = ft_strnew(32);
	while(i < 32)
	{
		ssl->half_l_m[i] = ret[i];
		i++;
	}
	while(i < 64)
		ssl->half_r_m[n++]  = ret[i++];
	//printf("splited mes %s %s\n", ssl->half_l_m, ssl->half_r_m);
}

static char *permutation_text(char *str)
{
	char *ret;
	int	i;

	i = 0;
	ret = ft_strnew(64);
	while (i < 64)
	{
		ret[i] = str[g_plaintext_perm_tab[i] - 1];
		i++;
	}
	free(str);
	return (ret);
}

void	ft_message_enc(t_ssl *ssl)
{
	int i;
	char	*ret;

	i = 0;
	while (ssl->message[i])
	{
		//printf("mes%s\n", ssl->message[i]);
		ret = permutation_text(ssl->message[i]);
		ft_split_mes(ret, ssl);
		ft_rolling(ssl);
		i++;
	}
}
