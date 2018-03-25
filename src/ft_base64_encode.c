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

static void	ft_base64_encription_output(char *line, t_ssl *ssl)
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
		ft_print_base64_fd(line, ssl, ssl->counter, fd);
	else
		ft_print_base64(line, ssl, ssl->counter);
}

void	ft_base64_encode(t_ssl *ssl)
{
	char	*line;
	int		fd;

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
		line = ft_read_file(fd);
	}
	else
		line = ft_read_term();
	if ((ft_strlen(line) % 24))
	 	line = ft_add_zero(line, ssl);
	else
	 	ssl->counter = ft_strlen(line) / 6;
	ft_base64_encription_output(line, ssl);
}
