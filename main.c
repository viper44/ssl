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
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

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

void	ft_print(t_data *data)
{
	char *base64;

	base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	printf("%c", base64[data->ret_encode]);
}

void	ft_pre_encode(char *line, t_data *data)
{
	char 	*str;
	int		n;
	int		i;

	i = 0;
	n = 0;
	str = ft_strnew(6);
	while (data->counter)
	{
		while (line[n])
		{
			str[i++] = line[n++];
			if (n % 6 == 0)
			break; 
		}
		i = 0;
		data->ret_encode = ft_reveres_itoa(str, 32);
		data->counter--;
		ft_print(data);
	}
	if (data->byte_counter != 0)
		while(data->byte_counter--)
			printf("%c", '=');
	printf("\n");
}

char *ft_covert_2(int tmp, int base, char *buffer)
{
	int i;
	char *str;
	int n;

	i = 128;
	n = 8;
	str = ft_strnew(n);
	n -= 1;
	while (n + 1)
	{
		str[n] = tmp % 2 + 48;
		tmp /= 2;
		n--;
	}
	free(buffer);
	return (str);
}

void	ft_h_m_p(int i, t_data *data)
{
	int a;
	int b;

	b = i % 6;
	a = 0;
	data->counter = i / 6;
	if (i != 0)
		data->counter++;
}

char *ft_add_zero(char *line, t_data *data)
{
	int i;
	int size;
	char *ret;
	int		size_line;

	i = 0;
	size_line = ft_strlen(line);
	ft_h_m_p(ft_strlen(line), data);
	while(size_line > 24)
		size_line -= 24;
	size = 24 - size_line;
	if (size == 8)
		data->byte_counter = 1;
	else if (size == 16)
		data->byte_counter = 2;
	ret = ft_strnew(size);
	while (--size >= 0 )
		ret[size] = '0';
	line = ft_strjoin(line, ret);
	data->string_size = ft_strlen(line);
	free (ret);
	return (line);
}

void	ft_pre_decode(int i, t_data *data)
{
	char *str;
	int		n;

	n = 6;
	str = ft_strnew(6);
	
	while (n)
	{
		str[n - 1] = i % 2 + 48;
		i /= 2;
		n--; 
	}
	data->ret_str = ft_strjoin(data->ret_str, str);
	//printf("data->ret_str =  = %s\n", data->ret_str);
}

int	ft_find_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	ft_print_decode(int value)
{
	unsigned char	c;

	//printf("value = %d\n", value);
	c = value;
	write(1, &c, 1); 
}

void	ft_almost_done(t_data *data)
{
	char	*ret;
	int		i;

	i = 0;
	//printf("%s\n", "test");
	while(data->ret_str[i] && data->string_size)
	{
		ret = ft_strsub(data->ret_str, i, 8);
		ft_print_decode(ft_reveres_itoa(ret, 128));
		i += 8;
		data->string_size--;
	}
	//printf("\n");
}
// 011101000110111101110100011011110000101000
void	ft_pieceof(char *str, t_data *data)
{	
	char 	*base64;
	int		i;
	int		n;

	n = 0;
	i = 0;
	base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	while(str[i])
	{
		n = ft_find_char(base64, str[i]);
		ft_pre_decode(n, data);
		i++;
	}
	data->string_size = ft_strlen(data->ret_str) / 8;
	//printf("razmer = %d\n", data->string_size);
	if (ft_strlen(data->ret_str) % 8 != 0)
		while(ft_strlen(data->ret_str) % 8 != 0)
			data->ret_str = ft_strjoin(data->ret_str, "0");
	//printf("data->ret_str after %s\n", data->ret_str);
	ft_almost_done(data);
}

void	ft_decode(t_data *data)
{
	char 	*buffer;
	char 	*line;
	int		ret;

	ret = 1;
	data->ret_str = ft_strnew(0);
	
	line = ft_strnew(0);
	buffer = ft_strnew(BUFF_SIZE);
	while(ret > 0)
	{	
		ret = read(0, buffer, BUFF_SIZE);
		if (*buffer == '=')
			break ;
		if (ret == -1)
			return ;
		buffer[ret] = '\0';
		line = ft_strjoin(line, buffer);
	}
	ft_pieceof(line, data);
}

void	ft_encode(t_data *data)
{
	char 	*buffer;
	char 	*line;
	int		ret;
	unsigned char 	tmp;

	ret = 1;
	line = ft_strnew(0);
	buffer = ft_strnew(BUFF_SIZE);
	while(ret > 0)
	{	
		ret = read(0, buffer, BUFF_SIZE);
		// if (ret == 0)
		// 	break ;
		if (ret == -1)
			return ;
		buffer[ret] = '\0';
		tmp = *buffer;
		buffer = ft_covert_2(tmp, 2, buffer);
		line = ft_strjoin(line, buffer);
	}
	free (buffer);
	if ((ft_strlen(line) % 24))
		line = ft_add_zero(line, data);
	ft_pre_encode(line, data);
}
// 110100001011111111010001100000001101000010111000110100001011001011010000101101011101000110000010000010100000000000000000
// 11010000101111111101000110000000110100001011100011010000101100101101000010110101110100011000001000001010
void	ft_des(t_data *data)
{
	int ret;
	char *buf;
	char *line;

	buf = ft_strnew(BUFF_SIZE);
	line = ft_strnew(0);
	ret = 1;
	write(1, "enter des key in hex: ", 22);
	// while (ret > 0)
	// {
	// 	ret = read(0, buf, BUFF_SIZE);
	// 	if (*buf == '\n')
	// 		break ;
	// 	if (ret == -1)
	// 		return ;
	// 	buf[ret] = '\0';
	// 	line = ft_strjoin(line, buf);
	// }
	line = getpass(line);
	if (ft_strlen(line) * 4 != 64)
		while(ft_strlen(line) * 4 != 64)
			line = ft_strjoin(line, "0");
	printf("line == %s\n", line);
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
	t_data	*data;
	int		i;

	i = 0;
	data = ft_memalloc(sizeof(t_data));
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
			ft_des(data);
	if (!ft_strcmp(argv[1], "base64") && argc == 2)
		ft_encode(data);
	if (argc == 3)
	{
		if (!ft_strcmp(argv[2], "-e"))
			ft_encode(data);
		if (!ft_strcmp(argv[2], "-d"))
			ft_decode(data);	
	}
	// if(!ft_check_command)

	return (0);
}
