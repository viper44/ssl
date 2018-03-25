/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_encription4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static int g_perm_tab[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2,\
		59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15,
		7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};

static char	*ft_conv(char c)
{
	char *table[16];
	int i;

	i = c - 48;
	table[0] = "0000";
	table[1] = "0001";
	table[2] = "0010";
	table[3] = "0011";
	table[4] = "0100";
	table[5] = "0101";
	table[6] = "0110";
	table[7] = "0111";
	table[8] = "1000";
	table[9] = "1001";
	table[10] = "1010";
	table[11] = "1011";
	table[12] = "1100";
	table[13] = "1101";
	table[14] = "1110";
	table[15] = "1111";
	if (i > 10)
		i = i - 7;
	return (table[i]);
}

static void	ft_split_key(char *key, t_ssl *ssl)
{
	int i;
	int n;

	i = 0;
	n = 0;
	ssl->half_l = ft_strnew(28);
	ssl->half_r = ft_strnew(28);
	while(i < 28)
	{
		ssl->half_l[i] = key[i];
		i++;
	}
	while(i < 56)
		ssl->half_r[n++] = key[i++];
}

static char *key_permutation(char *str)
{
	char *ret;
	int	i;

	i = 0;
	ret = ft_strnew(56);
	while (i < 56)
	{
		ret[i] = str[g_perm_tab[i] - 1];
		i++;
	}
	free(str);
	return (ret);
}

void	ft_des_encription4(t_ssl *ssl, const char *ret)
{
	char	*line;
	int		i;
	int		fd;

	ssl->final = ft_strnew(0);
	ssl->maj_key = ft_strnew(0);
	i = 0;
	ssl->ret_encode = 0;
	line = ft_strdup(ret);
	if (ft_strlen(line) * 4 != 64)
		while(ft_strlen(line) * 4 != 64)
			line = ft_strjoin2(line, "0", 1);
	while(line[i])
		ssl->maj_key = ft_strjoin2(ssl->maj_key, ft_conv(line[i++]), 1);
	// free(line);
	ssl->mid_key = key_permutation(ssl->maj_key);
	ft_split_key(ssl->mid_key, ssl);
	ft_shift_cycle(ssl);
	ft_message(ssl);
	fd = creat("des_encript_ouput", S_IRUSR | S_IWUSR);
	ft_print_binary_fd( ssl->final, ssl, fd);
	// while (ft_strlen(ssl->final) % 24 != 0)
	// 	ssl->final = ft_strjoin2(ssl->final, "0", 1);
	// printf("%s\n", ssl->final);
	//ft_print_base64(ssl->final, ssl, ft_strlen(ssl->final) / 6);
}