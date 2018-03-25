/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rolling2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static  int	g_expand_tab[48] = {32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10,\
		11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22,\
		23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};


static void	ft_make_arr_sbox(char **ret, t_ssl *ssl)
{
	char	*row;
	char	*colum;
	int		i;

	i = 0;
	ssl->ar_s =(int**)malloc(sizeof(int*) * 4);
	ssl->ar_s[3] = NULL;
	ssl->ar_s[0] = (int*)malloc(sizeof(int) * 9);
	ssl->ar_s[0][8] = -666;
	ssl->ar_s[1] = (int*)malloc(sizeof(int) * 9);
	ssl->ar_s[1][8] = -666;
	ssl->ar_s[2] = (int*)malloc(sizeof(int) * 9);
	ssl->ar_s[2][8] = -666;
	while (ret[i])
	{
		row = ft_strjoin2(ft_strsub(ret[i], 0, 1), ft_strsub(ret[i], 5, 1), 4);
		colum = ft_strsub(ret[i], 1, 4);
		ssl->ar_s[0][i] = i;
		ssl->ar_s[1][i] = ft_reveres_itoa(row, 2);
		ssl->ar_s[2][i] = ft_reveres_itoa(colum, 8);
		i++;
	}
}

static void	ft_split_xored(char *xored, t_ssl *ssl)
{
	char **ret;
	int	i;
	int	n;

	i = 0;
	n = 0;
	ret =(char**)malloc(sizeof(char*) * 8 + 1);
	ret[8] = NULL;
	while (i < 8)
	{
		ret[i++] = ft_strsub(xored, n, 6);
		n += 6;
	}
	ft_make_arr_sbox(ret, ssl);
	free (xored);
	free(ret);
}

static char	*ft_xor(char *str, t_ssl *ssl, int round)
{
	int i;
	char *ret;

	i = 0;
	ret = ft_strdup(str);
	while (ret[i])
	{
		if (ret[i] == '0' && ssl->sub_keys[round][i] == '0')
			ret[i] = '0';
		else if ((ret[i] == '1' && ssl->sub_keys[round][i] == '0') ||
			(ret[i] == '0' && ssl->sub_keys[round][i] == '1'))
			ret[i] = '1';
		else
			ret[i] = '0';
		i++;
	}
	return (ret);
}

static char *ft_expand_r(char *line)
{
	char *ret;
	int i;

	i = 0;
	ret = ft_strnew(48);
	while (i < 48)
	{
		ret[i] = line[g_expand_tab[i] - 1];
		i++;
	}
	return (ret);
}

void	ft_rolling2(t_ssl *ssl)
{
	int		round;
	char	*xored;
	char	*ret;

	round = 15;
	while (round >= 0)
	{
		ssl->right_expand = ft_expand_r(ssl->half_r_m);
		xored = ft_xor(ssl->right_expand, ssl, round);
		ft_split_xored(xored, ssl);
		ft_s_box_work(ssl);
		ft_swap(ssl);
		round--;
	}
	ret = ft_strjoin2(ssl->half_r_m, ssl->half_l_m, 4);
	ret = final_perm(ret);
	ssl->final = ft_strjoin2(ssl->final, ret, 2);
}