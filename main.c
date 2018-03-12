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
// void	ft_fill_commands(char **commands)
// {
// 	commands[0] = ft_strnew (6);
// }

// int		ft_check_command(char *str)
// {
// 	while ()
// 	ft_strcmp(str, )
// }

void	ft_read_input(t_data *data)
{
	char 	*buffer;
	char 	*line;
	int		ret;

	ret = 1;
	line = NULL;
	buffer = ft_strnew(BUFF_SIZE);
	while(ret > 0)
	{
		ret = read(0, buffer, BUFF_SIZE);
		if (ret == -1)
			return ;
		buffer[ret] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free (buffer);
	printf("%s\n", line);

}

int		main(int argc, char const **argv)
{
	//char **commands[5];
	t_data *data;

	data = ft_memalloc(sizeof(t_data));
	//commands[4] = NULL;
	//ft_fill_commands(commands);
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
