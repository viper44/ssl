/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:41:33 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/12 16:41:34 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

char	*ft_hash(char *output)
{
	char *hash;
	char *ret;

	hash = ft_strnew(1);
	hash[0] = '0';
	ret = ft_strjoin(hash, output);
	free(output);
	free(hash);
	return (ret);
}
