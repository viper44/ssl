/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char	**ft_split_string(char *line)
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
	//printf("line = %s\n", line);
	while(line_size)
	{
		line_size = line_size - 64;
		count++;
	}
	//printf("razmer 2-m mass %d\n", count);
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

static char	*ft_add_padding(char *line)
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
		//printf("skolko dobavit ? %d\n", n);
		ret = n;
		line = ft_strjoin2(line, ft_convert_2(ret, 8), 1);
		i++;
	}
	return (line);
}

// int		ft_nofilename(void)
// {
// 	int				ret;
// 	char			*buffer;
// 	char			*line;
// 	int				fd;

// 	ret = 1;
// 	line = ft_strnew(0);
// 	buffer = ft_strnew(1);
// 	write(0, "please input filename: ", 22);
// 	while ((ret = read (0, buffer, 1)))
// 	{
// 		if (ret == -1)
// 			exit(1);
// 		if (ret == 0 || *buffer == '\0' || *buffer == '\n')
// 			break ;
// 		line = ft_strjoin2(line, buffer, 1);
// 	}
// 	free (buffer);
// 	fd = open(line, O_RDONLY);
// 	if (fd == -1)
// 		exit(1);
// 	free (line);
// 	return (fd);
// }

void	ft_message(t_ssl *ssl)
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
	line = ft_add_padding(line);
	ssl->string_size = ft_strlen(line) / 8;
	ssl->message = ft_split_string(line);
	ft_message_enc(ssl);
}
	// char 			*buffer;
	// char 			*line;
	// int				ret;
	// unsigned char 	tmp;

	// ret = 1;
	// line = ft_strnew(0);
	// buffer = ft_strnew(BUFF_SIZE);
	// while((ret = read(0, buffer, BUFF_SIZE)))
	// {	
	// 	if (ret == 0)
	// 		break ;
	// 	buffer[ret] = '\0';
	// 	tmp = *buffer;
	// 	line = ft_strjoin2(line, ft_convert_2(tmp, 8), 1);		
	// }
	// free (buffer);