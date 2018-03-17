/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 08:31:56 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/16 08:31:58 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

// void	ft_h_m_p(int i, t_ssl *ssl)
// {
// 	int a;
// 	int b;

// 	b = i % 6;
// 	a = 0;
// 	ssl->counter = i / 6;
// 	if (i != 0)
// 		ssl->counter++;
// }

void	ft_print(t_ssl *ssl)
{
	char *base64;

	base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	printf("%c", base64[ssl->ret_encode]);
}

void	ft_pre_encode(char *line, t_ssl *ssl)
{
	char 	*str;
	int		n;
	int		i;

	i = 0;
	n = 0;
	str = ft_strnew(6);
	while (ssl->counter)
	{
		while (line[n])
		{
			str[i++] = line[n++];
			if (n % 6 == 0)
			break; 
		}
		i = 0;
		ssl->ret_encode = ft_reveres_itoa(str, 32);
		ssl->counter--;
		ft_print(ssl);
	}
	if (ssl->byte_counter != 0)
		while(ssl->byte_counter--)
			printf("%c", '=');
	printf("\n");
}

char *ft_add_zero(char *line, t_ssl *ssl)
{
	int 	i;
	int 	size;
	char 	*ret;
	int		size_line;

	i = 0;
	size_line = ft_strlen(line);
	//ft_h_m_p(ft_strlen(line), ssl);
	ssl->counter = size_line / 6;
	//printf("%d\n", ssl->counter);
	if (size_line != 0)
		ssl->counter++;
	//printf("%d\n", ssl->counter);
	while(size_line > 24)
		size_line -= 24;
	size = 24 - size_line;
	if (size == 8)
		ssl->byte_counter = 1;
	else if (size == 16)
		ssl->byte_counter = 2;
	ret = ft_strnew(size);
	while (--size >= 0 )
		ret[size] = '0';
	line = ft_strjoin2(line, ret, 1);
	ssl->string_size = ft_strlen(line);
	free (ret);
	return (line);
}

char *ft_covert_2(int tmp, char *buffer)
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
	free(buffer);
	return (str);
}

void	ft_encode(t_ssl *ssl)
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
		buffer = ft_covert_2(tmp, buffer);
		line = ft_strjoin2(line, buffer, 1);		
	}
	free (buffer);
	if ((ft_strlen(line) % 24))
		line = ft_add_zero(line, ssl);
	ft_printf("line = %s\n", line);
	ft_pre_encode(line, ssl);
}