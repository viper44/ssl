/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_dencode2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 08:32:07 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/16 08:32:10 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static int	ft_find_char(char *str, char c)
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


static void	ft_pre_decode(int i, t_ssl *ssl)
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
	ssl->ret_str = ft_strjoin2(ssl->ret_str, str, 1);
}

static void	ft_pieceof(char *str, t_ssl *ssl)
{	
	char 	*base64;
	int		i;
	int		n;

	n = 0;
	i = 0;
	base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	while(str[i])
	{
		if (str[i] == '=')
			break ;
		n = ft_find_char(base64, str[i]);
		ft_pre_decode(n, ssl);
		i++;
	}
	//printf("ret-str %s\n", ssl->ret_str);
	ssl->string_size = ft_strlen(ssl->ret_str) / 8;
	// if (ft_strlen(ssl->ret_str) % 8 != 0)
	// 	while(ft_strlen(ssl->ret_str) % 8 != 0)
	// 		ssl->ret_str = ft_strjoin2(ssl->ret_str, "0", 1);
	//ft_print_binary(ssl->ret_str, ssl);
}

void	ft_base64_decode2(t_ssl *ssl)
{
	char 	*buffer;
	char 	*line;
	int		ret;

	ret = 1;
	ssl->ret_str = ft_strnew(0);
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
		line = ft_strjoin2(line, buffer, 1);
	}
	ft_pieceof(line, ssl);
	ft_des_decription(ssl);
	//printf("%s\n", "Test");
	//ft_des_decription3(ssl, ssl->ret_str, key);
}