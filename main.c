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
// void	ft_fill_commands(char **commands)
// {
// 	commands[0] = ft_strnew (6);
// }

// int		ft_check_command(char *str)
// {
// 	while ()
// 	ft_strcmp(str, )
// }

// int		ft_reveres_itoa(char *str, base)
// {
// 	int ret;
// 	int i;

// 	i = 0;
// 	ret = 0;
// 	while (base >= 1)
// 	{
// 		if (str[i] == 1)
// 			ret += base;
// 		base /= 2;
// 		i++;
// 	}
// 	return (ret);
// }

// void	ft_convert(t_data *data)
// {

// }

// void	ft_encode(char *line, t_data *data)
// {
// 	char 	*str;
// 	int		n;
// 	int		i;

// 	i = 0;
// 	n = 0;
// 	str = ft_strnew(6);
// 	while (1)
// 	{
// 		while (line[n])
// 		{
// 			str[i++] = line[n++]
// 			if (n % 5 == 0)
// 			break; 
// 		}
// 		n++;		
// 		if (ft_strlen(str) != 6)
// 			while (ft_strlen(str) != 6)
// 				str[i++] = '0'
// 		i = 0;
// 		data->ret = ft_reveres_itoa(str, 32);
// 		ft_convert(data);
// 	}
// }

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
	//printf("str = %s\n", str);
	free(buffer);
	return (str);
}

char *ft_add_zero(char *line)
{
	int i;
	int size;
	char *ret;

	i = 0;
	size = 24 - (int)ft_strlen(line);
	printf("%d\n", size);
	ret = ft_strnew(size);
	size -= 1;
	while (size >= 0 )
	{
		ret[size] = '0';
		size--;
	}
	line = ft_strjoin(line, ret);
	free (ret);
	return (line);
}

void	ft_read_input(t_data *data)
{
	char 	*buffer;
	char 	*line;
	int		ret;
	int 	tmp;

	ret = 1;
	line = ft_strnew(0);
	buffer = ft_strnew(BUFF_SIZE);
	while(ret > 0)
	{
		ret = read(0, buffer, BUFF_SIZE);
		if (ret == 0)
			break ;
		if (ret == -1)
			return ;
		buffer[ret] = '\0';
		tmp = *buffer;
		buffer = ft_covert_2(tmp, 2, buffer);
		line = ft_strjoin(line, buffer);
	}
	free (buffer);
	printf("line == %s\n", line);
	if ((ft_strlen(line) % 24))
		line = ft_add_zero(line);
	printf("%s\n", line);
	//ft_encode(line, data);
}

int		main(int argc, char const **argv)
{
	t_data	*data;
	int		i;

	i = 0;
	data = ft_memalloc(sizeof(t_data));
	if (argc == 1)
	{
		printf("%s\n", "usage: ft_ssl command [command opts] [command args]");
		return(0);
	}
	if (ft_strcmp("base64", argv[1]))
		printf("Error %s is an invalid command.\n\nStandart commands:\n\n\
Message Digest commands:\n\nCipher commands:\n\
base64\ndes\ndes-ecb\ndec-cbc\n" , argv[1]);
	ft_read_input(data);
	// if(!ft_check_command)

	return (0);
}
