/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_the_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	ft_cut_the_tail(t_ssl *ssl, char *ret)
{
	int		i;
	char	*tmp;

	//printf("ret = 	%s\n", ret);
	//printf("razmer = %d\n", ssl->string_size);
	tmp = ft_strsub(ret, ft_strlen(ret) - 8, 8);
	i = ft_reveres_itoa(tmp, 128);
	//printf("%d\n", i);
	ssl->string_size -= i;
	ssl->cut++;
	free (tmp);
}