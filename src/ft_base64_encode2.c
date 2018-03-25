/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_encode2.c                                :+:      :+:    :+:   */
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

// void	ft_print(t_ssl *ssl)
// {
// 	char *base64;

// 	base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
// 	printf("%c", base64[ssl->ret_encode]);
// }

static char *ft_add_zero(char *line, t_ssl *ssl)
{
	int 	size;
	char 	*ret;
	int		size_line;

	size_line = ft_strlen(line);
	ssl->counter = size_line / 6;
	if (size_line != 0)
		ssl->counter++;
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

// static char *ft_convert(int tmp, char *buffer)
// {
// 	char 	*str;
// 	int 	n;

// 	n = 8;
// 	str = ft_strnew(n);
// 	n -= 1;
// 	while (n + 1)
// 	{
// 		str[n] = tmp % 2 + 48;
// 		tmp /= 2;
// 		n--;
// 	}
// 	free(buffer);
// 	return (str);
// }


void	ft_base64_encode2(t_ssl *ssl, char	*str, int fd)
{
	// char 			*buffer;
	// char 			*line;
	// int				ret;
	// unsigned char 	tmp;

	// ret = 1;
	// line = ft_strnew(0);
	// buffer = ft_strnew(BUFF_SIZE);
	// while(ret)
	// {	
	// 	ret = read(0, buffer, BUFF_SIZE);
	// 	if (ret == 0)
	// 		break ;
	// 	buffer[ret] = '\0';
	// 	tmp = *buffer;
	// 	buffer = ft_convert(tmp, buffer);
	// 	line = ft_strjoin2(line, buffer, 1);		
	// }
	// free (buffer);
	//printf("do %s\n", str);
	if ((ft_strlen(str) % 24))
	 	str = ft_add_zero(str, ssl);
	 else
	 	ssl->counter = ft_strlen(str) / 6;
	//printf("line = %s\n", str);
	 if (ssl->o == 1)
	 	ft_print_base64_fd(str, ssl, ssl->counter, fd);
	 else
	 	ft_print_base64(str, ssl, ssl->counter);
}