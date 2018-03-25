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

static void	ft_base64_decription_output(char *line, t_ssl *ssl)
{
	int		fd;

	fd = 0;
	if (ssl->o == 1)
	{
		if (ssl->file_name2)
		{
			fd = open(ssl->file_name2, O_WRONLY);
				if (fd == -1)
					ft_print_error();
		}
		else
			fd = ft_creat_file();
	}
	if (ssl->o == 1)
		ft_print_binary_fd(line, ssl, fd);
	else
		ft_print_binary(line, ssl);
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
	ssl->string_size = ft_strlen(ssl->ret_str) / 8;
	if (ft_strlen(ssl->ret_str) % 8 != 0)
		while(ft_strlen(ssl->ret_str) % 8 != 0)
			ssl->ret_str = ft_strjoin2(ssl->ret_str, "0", 1);
	if (ssl->a == 1)
		ft_des_decription(ssl);
	else
		ft_base64_decription_output(ssl->ret_str, ssl);
	//ft_print_binary(ssl->ret_str, ssl);
}

void	ft_base64_decode(t_ssl *ssl)
{
	char	*line;
	int		fd;

	ssl->ret_str = ft_strnew(0);
	fd = 0;
	if (ssl->i == 1)
	{
		if (ssl->file_name)
		{
			fd = open(ssl->file_name, O_RDONLY);
				if (fd == -1)
					ft_print_error();
		}
		else
			fd = ft_nofilename();		
		line = ft_read_file2(fd);
	}
	else
		line = ft_read_term2();
	ft_pieceof(line, ssl);
}