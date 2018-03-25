/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int		ft_creat_file(void)
{
	int				ret;
	char			*buffer;
	char			*line;
	int				fd;

	ret = 1;
	line = ft_strnew(0);
	buffer = ft_strnew(1);
	write(0, "please input filename: ", 22);
	while ((ret = read (0, buffer, 1)))
	{
		if (ret == -1)
			exit(1);
		if (ret == 0 || *buffer == '\0' || *buffer == '\n')
			break ;
		line = ft_strjoin2(line, buffer, 1);
	}
	free (buffer);
	fd = creat(line, S_IRUSR | S_IWUSR);
	if (fd == -1)
		exit(1);
	free (line);
	return (fd);
}
