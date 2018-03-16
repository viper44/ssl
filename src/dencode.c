/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dencode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 08:32:07 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/16 08:32:10 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

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

void	ft_almost_done(t_ssl *ssl)
{
	char			*ret;
	int				i;
	unsigned char	c;

	i = 0;
	//printf("%s\n", "test");
	while(ssl->ret_str[i] && ssl->string_size)
	{
		ret = ft_strsub(ssl->ret_str, i, 8);
		c = ft_reveres_itoa(ret, 128);
		write (1, &c, 1);
		i += 8;
		ssl->string_size--;
	}
	//printf("\n");
}

void	ft_pre_decode(int i, t_ssl *ssl)
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
	ssl->ret_str = ft_strjoin(ssl->ret_str, str);
	//printf("ssl->ret_str =  = %s\n", ssl->ret_str);
}

void	ft_pieceof(char *str, t_ssl *ssl)
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
		ft_pre_decode(n, ssl);
		i++;
	}
	ssl->string_size = ft_strlen(ssl->ret_str) / 8;
	//printf("razmer = %d\n", ssl->string_size);
	if (ft_strlen(ssl->ret_str) % 8 != 0)
		while(ft_strlen(ssl->ret_str) % 8 != 0)
			ssl->ret_str = ft_strjoin(ssl->ret_str, "0");
	//printf("ssl->ret_str after %s\n", ssl->ret_str);
	ft_almost_done(ssl);
}

void	ft_decode(t_ssl *ssl)
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
		if (*buffer == '=')
			break ;
		if (ret == 0)
			break ;
		if (ret == -1)
			return ;
		buffer[ret] = '\0';
		line = ft_strjoin(line, buffer);
	}
	ft_printf("line = %s\n", line);
	ft_pieceof(line, ssl);
}
