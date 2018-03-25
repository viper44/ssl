/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_cycle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static	int g_comp_perm_tab[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,\
		23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,41, 52, 31, 37, 47, 55, 30, 40,\
		51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

static char *comp_permutation(char *line)
{
	char *ret;
	int i;

	i = 0;
	ret = ft_strnew(48);
	while (i < 48)
	{
		ret[i] = line[g_comp_perm_tab[i] - 1];
		i++;
	}
	free(line);
	return (ret);
}

static char	*rotation(char *str, int i)
{
	char	*ret;
	int		n;
	int		m;
	char	*tmp;

	n = 0;
	m = 0;
	tmp = ft_strnew(i);
	ret = ft_strnew(28);
	while (n < i)
	{
		tmp[n] = str[n];
		n++;
	}
	while (n < 28)
		ret[m++] = str[n++];
	n = 0;
	while (n < i)
		ret[m++] = tmp[n++];
	//free(str);
	free(tmp);
	return(ret);
}

static void	ft_rot_one_or_two(int round, t_ssl *ssl, int i)
{
	char	*ret;

	ssl->half_l = rotation(ssl->half_l, i);
	ssl->half_r = rotation(ssl->half_r, i);
	ret = ft_strjoin2(ssl->half_l, ssl->half_r, 3);
	ssl->sub_keys[round] = comp_permutation(ret);
	//printf("key #%.2d = %s\n",round, ssl->sub_keys[round]);
}

void	ft_shift_cycle(t_ssl *ssl)
{
	int 	round;
	char 	*number;

	number = "1122222212222221";
	ssl->sub_keys = (char**)malloc(sizeof(char) * 17);
	ssl->sub_keys[16] = NULL;
	round = 0;
	while(round < 16)
	{
		ft_rot_one_or_two(round, ssl, number[round] - 48);
		round++;
	}
}