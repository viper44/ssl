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
	if (size < 64)
		while (size < 64)
		{
			size += 8;
			n++;
		}
	else if (size == 64)
		n = 8;
	while (i < n)
	{
		ret = n;
		line = ft_strjoin2(line, ft_covert_2(ret), 1);
		i++;
	}
	return (line);
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
	if (ft_strlen(line) <= 64)
		line = ft_add_padding(line);
	ssl->message = NULL;
	printf("message = %s\n", line);
	//ssl->message = permutation(line);
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
