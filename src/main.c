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




// 00000000001111111100000010100100110000101110000101010000
// 111000001000001000101010110000100011001010011000

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
	printf("ret2 === %s\n", ret);
	free(line);
	return (ret);
}

char *permutation(char *str)
{
	char *ret;
	int	i;

	i = 0;
	printf("str == %s\n", str);
	ret = ft_strnew(56);
	while (i < 56)
	{
		printf("g_perm_t ==   %d\n", g_perm_tab[i] - 1);
		ret[i] = str[g_perm_tab[i] - 1];
		i++;
	}
	ft_printf("ret == %s\n", ret);
	free(str);
	return (ret);
}

char	*ft_conv(char c)
{
	char *table[16];
	int i;

	//printf("elem = %c\n", c);
	i = c - 48;
	//printf("i == %d\n", i);
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
	//printf("i = %d small string == %s\n", i, table[i]);
	return (table[i]);
}


// 110100001011111111010001100000001101000010111000110100001011001011010000101101011101000110000010000010100000000000000000
// 11010000101111111101000110000000110100001011100011010000101100101101000010110101110100011000001000001010

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
	printf("key == %59s\n", key);
	printf("half_l == %-56s\n", ssl->half_l);
	printf("half_r == %56s\n", ssl->half_r);
}

void	ft_rot_one_or_two(t_ssl *ssl, int i, char tmp)
{
	char	*ret_l;
	char	*ret_r;
	char	*tmp;

	tmp = ft_strnew(i);
	ret_l = ft_strnew(26);
	ret_r = ft_strnew(26);

}

void	ft_shift_cycle(t_ssl *ssl)
{
	int 	round;
	char 	*number;
	char	tmp;

	tmp = '\0';
	number = "1122222212222221";
	ssl->sub_keys = (char**)malloc(sizeof(char) * 17);
	ssl->sub_keys[16] = NULL;
	round = 0;
	while(round < 16)
		ft_rot_one_or_two(ssl, number[round++] - 48, tmp);
}

void	ft_des(t_ssl *ssl)
{
	int		ret;
	char	*buf;
	char	*line;
	int		i;

	ssl->maj_key = ft_strnew(0);
	buf = ft_strnew(BUFF_SIZE);
	line = ft_strnew(0);
	ret = 1;
	i = 0;
	ssl->ret_encode = 0;
	write(1, "enter des key in hex: ", 22);
	line = getpass(line);
	if (ft_strlen(line) * 4 != 64)
		while(ft_strlen(line) * 4 != 64)
			line = ft_strjoin(line, "0");
	while(line[i])
		ssl->maj_key = ft_strjoin(ssl->maj_key, ft_conv(line[i++]));
	free(line);
	ssl->maj_key = permutation(ssl->maj_key);
	ft_split_key(ssl->maj_key, ssl);
	ft_shift_cycle(ssl);
	//line = comp_permutation(line);
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
	int		i;

	i = 0;
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
