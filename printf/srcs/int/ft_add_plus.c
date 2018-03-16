/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:54:16 by msemenov          #+#    #+#             */
/*   Updated: 2018/01/23 15:54:18 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

char	*ft_add_plus(char *tmp)
{
	char	*plus;
	char	*ptr;

	ptr = tmp;
	plus = ft_strnew(1);
	plus[0] = '+';
	tmp = ft_strjoin(plus, tmp);
	free(ptr);
	free(plus);
	return (tmp);
}
