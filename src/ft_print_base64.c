/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_encription2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	ft_print_base64(char *line, t_ssl *ssl, int i)
{
	char 	*str;
	int		n;
	char 	*base64;

	base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	n = 0;
	while (i)
	{
		str = ft_strsub(line, n, 6);
		n += 6;
		ssl->ret_encode = ft_reveres_itoa(str, 32);
		//printf("%d\n", ssl->ret_encode);
		//printf("%s\n", base64);
		printf("%c", base64[ssl->ret_encode]);
		i--;
		free (str);
	}
	while(ssl->byte_counter--)
		printf("%c", '=');
	printf("\n");
}