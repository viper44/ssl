/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 08:32:07 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/16 08:32:10 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	ft_print_binary_fd(char *ret, t_ssl *ssl, int fd)
{
	int				i;
	char			*str;
	unsigned char	c;

	i = 0;
	while(ret[i] && ssl->string_size)
	{
		str = ft_strsub(ret, i, 8);
		c = ft_reveres_itoa(str, 128);
		write (fd, &c, 1);
		i += 8;
		ssl->string_size--;
		free (str);
	}
	free (ret);
	close (fd);
	//printf("\n");
}
