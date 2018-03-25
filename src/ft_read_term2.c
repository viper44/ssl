/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_term2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

char	*ft_read_term2(void)
{
	char 			*buffer;
	char 			*line;
	int				ret;

	ret = 1;
	line = ft_strnew(0);
	buffer = ft_strnew(BUFF_SIZE);
	while((ret = read(0, buffer, BUFF_SIZE)))
	{	
		if (ret == 0)
			break ;
		if (ret == -1)
			exit(1);
		buffer[ret] = '\0';
		line = ft_strjoin2(line, buffer, 1);		
	}
	free (buffer);
	return (line);
}