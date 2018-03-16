/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:40:53 by msemenov          #+#    #+#             */
/*   Updated: 2018/01/23 15:40:59 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static char		*ft_b(char *ret, int size, int minus)
{
	size = size - 1 + minus;
	while (size >= 0)
	{
		ret[size] = '0';
		size--;
	}
	return (ret);
}

static char		*ft_make_str(int minus, char *ret, int base, uint64_t nb)
{
	int	size;
	int	tmp;

	size = 0;
	while (ret[size] != '\0')
		size++;
	size -= 1;
	while (size >= 0)
	{
		tmp = nb % base;
		if (tmp >= 10)
			ret[size] = ('A' + tmp % 10);
		else
			ret[size] = tmp + '0';
		nb = nb / base;
		size--;
	}
	if (minus == 1)
		ret[0] = '-';
	return (ret);
}

char			*itoa_base(long long int value, int base)
{
	unsigned long long int	nb;
	int						minus;
	int						size;
	char					*ret;

	minus = 0;
	size = 1;
	if (value == 0)
		size = 2;
	if (value < 0 && base == 10)
	{
		nb = -value;
		minus++;
	}
	else
		nb = value;
	while (value != 0)
	{
		value = value / base;
		size++;
	}
	ret = ft_strnew(size + minus);
	size -= 1;
	ret = ft_b(ret, size, minus);
	return (ft_make_str(minus, ret, base, nb));
}
