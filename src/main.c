/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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

static	int	g_plaintext_perm_tab[64] ={58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44,\
		36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24,\
		16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61,\
		53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};

static	int g_comp_perm_tab[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,\
		23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,41, 52, 31, 37, 47, 55, 30, 40,\
		51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

static int g_perm_tab[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2,\
		59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15,\
		7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};

static char *ft_covert_2(int tmp)
{
	char 	*str;
	int 	n;

	n = 8;
	str = ft_strnew(n);
	n -= 1;
	while (n + 1)
	{
		str[n] = tmp % 2 + 48;
		tmp /= 2;
		n--;
	}
	//free(buffer);
	return (str);
}

char *comp_permutation(char *line)
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

char *permutation(char *str)
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

char	*ft_conv(char c)
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

void	ft_split_key(char *key, t_ssl *ssl)
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
		ssl->half_r[n++]  = key[i++];
}

char	*rotation(char *str, int i)
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
// 0000000000111111110000001010
// 00000000011111111000000100
void	ft_rot_one_or_two(int round, t_ssl *ssl, int i)
{
	char	*ret;

	ssl->half_l = rotation(ssl->half_l, i);
	//printf("half-l after rot = %s\n", ssl->half_l);
	ssl->half_r = rotation(ssl->half_r, i);
	//printf("half-r after rot = %s\n", ssl->half_r);
	ret = ft_strjoin2(ssl->half_l, ssl->half_r, 3);
	//printf("ret = %s\n", ret);
	ssl->sub_keys[round] = comp_permutation(ret);
	printf("key #%.2d = %s\n",round, ssl->sub_keys[round]);
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

char	*ft_add_padding(char *line)
{
	int 			n;
	int				size;
	unsigned char	ret;
	int				i;

	i = 0;
	size = ft_strlen(line);
	n = 0;
	if (size % 64 != 0)
		while (size % 64 != 0)
		{
			size += 8;
			n++;
		}
	else if (size % 64 == 0)
		n = 8;
	while (i < n)
	{
		ret = n;
		line = ft_strjoin2(line, ft_covert_2(ret), 1);
		i++;
	}
	return (line);
}

char	**ft_split_sting(char *line)
{
	char **ret;
	int	count;
	int	line_size;
	int	i;
	int	n;

	i = 0;
	n = 0;
	line_size = ft_strlen(line);
	count = 0;
	while(line_size)
	{
		line_size = line_size / 64;
		count++;
	}
	printf("%d\n", count);
	ret =(char**)malloc(sizeof(char*) * count + 1);
	ret[count] = NULL;
	while (count--)
	{
		ret[i++] = ft_strsub(line, n, 64);
		n += 64;
	}
	free (line);
	return (ret);
}

void	ft_split_mes(char *ret, t_ssl *ssl)
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
	printf("splited mes %s %s\n", ssl->half_l_m, ssl->half_r_m);
}

char	*ft_xor(char *ret, t_ssl *ssl, int round)
{
	int i;

	i = 0;
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

char *ft_expand_r(char *line)
{
	char *ret;
	int i;

	i = 0;
	ret = ft_strnew(48);
	printf("line == %s\n", line);
	while (i < 48)
	{
		ret[i] = line[g_expand_tab[i] - 1];
		i++;
	}
	printf("right expand = %s\n", ret);
	free(line);
	return (ret);
}

char *permutation_text(char *str)
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

void	ft_make_arr_sbox(char **ret, t_ssl *ssl)
{
	char	*row;
	char	*colum;
	int		i;
	int		n;
	int		m;

	n = 0;
	m = 0;
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
		// printf("row #%d %s\n", i, row);
		colum = ft_strsub(ret[i], 1, 4);
		// printf("colum #%d %s\n", i, colum);
		// printf("row conv #%d %d\n", i, ft_reveres_itoa(row, 2));
		// printf("colum conv #%d %d\n", i, ft_reveres_itoa(colum, 8));
		ssl->ar_s[0][i] = i;
		ssl->ar_s[1][i] = ft_reveres_itoa(row, 2);
		ssl->ar_s[2][i] = ft_reveres_itoa(colum, 8);
		i++;
	}
	while (ssl->ar_s[n])
	{
		printf("turn #%d ", n);
		while (ssl->ar_s[n][m] != -666)
			printf("%d ", ssl->ar_s[n][m++]);
		m = 0;
		printf("\n");
		n++;
	}
}

char	**ft_split_xored(char *xored, t_ssl *ssl)
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
	return (ret);
}

// void	ft_s_box_work(char **splited)
// {
// 	char	*row;
// 	char	*colum;
// 	int		i;

// 	i = 0;
// 	fow = ft_strnew(2);
// 	colum = ft_strnew(4);
// 	while (splited[i])
// 	{

// 	}
// }

void	ft_rolling(t_ssl *ssl)
{
	int		round;
	char	*xored;
	char	**splited;

	round = 0;
	while (round < 16)
	{
		xored = ft_xor(ssl->half_r_m, ssl, round);
		splited = ft_split_xored(xored, ssl);
		printf("test %s\n", splited[0]);
		//ft_s_box_work(splited);
		round++;
	}
}

void	ft_message_enc(t_ssl *ssl)
{
	int i;
	char	*ret;

	i = 0;
	while (ssl->message[i])
	{
		// printf("mess = %s\n", ssl->message[i]);
		ret = permutation_text(ssl->message[i]);
		// printf("mess after permutation = %s\n", ret);
		ft_split_mes(ret, ssl);
		ssl->half_r_m = ft_expand_r(ssl->half_r_m);
		ft_rolling(ssl);
		i++;
	}
}

void	ft_message(t_ssl *ssl)
{
	char 			*buffer;
	char 			*line;
	int				ret;
	unsigned char 	tmp;

	ret = 1;
	line = ft_strnew(0);
	buffer = ft_strnew(BUFF_SIZE);
	while(ret)
	{	
		ret = read(0, buffer, BUFF_SIZE);
		if (ret == 0)
			break ;
		if (ret == -1)
			return ;
		buffer[ret] = '\0';
		tmp = *buffer;
		buffer = ft_covert_2(tmp);
		line = ft_strjoin2(line, buffer, 1);		
	}
	if (ft_strlen(line) % 64 != 0 || ft_strlen(line) == 64)
		line = ft_add_padding(line);
	printf("hole line = %s\n", line);
	ssl->message = ft_split_sting(line);
	ft_message_enc(ssl);
	//ssl->message = permutation(line);
}

void	ft_des(t_ssl *ssl)
{
	char	*line;
	int		i;

	ssl->maj_key = ft_strnew(0);
	line = ft_strnew(0);
	i = 0;
	ssl->ret_encode = 0;
	write(1, "enter des key in hex: ", 22);
	line = getpass(line);
	if (ft_strlen(line) * 4 != 64)
		while(ft_strlen(line) * 4 != 64)
			line = ft_strjoin2(line, "0", 1);
	while(line[i])
		ssl->maj_key = ft_strjoin2(ssl->maj_key, ft_conv(line[i++]), 1);
	free(line);
	ssl->mid_key = permutation(ssl->maj_key);
	ft_split_key(ssl->mid_key, ssl);
	ft_shift_cycle(ssl);
	ft_message(ssl);
}

int	ft_valid_command(const char *s)
{
	if (ft_strcmp(s, "base64") && ft_strcmp(s, "des") != 0)
		return (1);
	else if (ft_strcmp(s, "des") && ft_strcmp(s, "base64") != 0)
		return (1);
	else
		return (0);
}

int		main(int argc, char const **argv)
{
	t_ssl	*ssl;

	ssl = ft_memalloc(sizeof(t_ssl));
	if (argc == 1 )//|| ft_strcmp(argv[2], "-d" ))
	{
		printf("%s\n", "usage: ft_ssl command [command opts] [command args]");
		return(0);
	}
	if (ft_valid_command(argv[1]))
		printf("Error %s is an invalid command.\n\nStandart commands:\n\n\
Message Digest commands:\n\nCipher commands:\n\
base64\ndes\ndes-ecb\ndec-cbc\n" , argv[1]);
	//printf("%d\n", argc);
	if (!ft_strcmp(argv[1], "des"))
			ft_des(ssl);
	if (!ft_strcmp(argv[1], "base64") && argc == 2)
		ft_encode(ssl);
	if (argc == 3)
	{
		if (!ft_strcmp(argv[2], "-e"))
			ft_encode(ssl);
		if (!ft_strcmp(argv[2], "-d"))
			ft_decode(ssl);	
	}
	// if(!ft_check_command)

	return (0);
}
