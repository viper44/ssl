/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:31:05 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/12 15:31:06 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

char	*ft_hash_hex(char *output)
{
	char *hash;
	char *ret;

	if (output[0] != '0' || ((int)ft_strlen(output) > 2))
	{
		hash = ft_strnew(2);
		hash[0] = '0';
		hash[1] = 'x';
		ret = ft_strjoin(hash, output);
		free(output);
		free(hash);
		return (ret);
	}
	else
	{
		return (output);
	}
}
