/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kostil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:54:40 by msemenov          #+#    #+#             */
/*   Updated: 2018/01/23 15:54:42 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static char		*swap_plus(char *tmp_ret)
{
	int i;

	i = 0;
	while (tmp_ret[i] != '\0')
	{
		if (tmp_ret[i] == '+')
			tmp_ret[i] = '0';
		i++;
	}
	tmp_ret[0] = '+';
	return (tmp_ret);
}

static char		*swap_minus(char *tmp_ret)
{
	int i;

	i = 0;
	while (tmp_ret[i] != '\0')
	{
		if (tmp_ret[i] == '-')
			tmp_ret[i] = '0';
		i++;
	}
	tmp_ret[0] = '-';
	return (tmp_ret);
}

char			*ft_kostil(char *tmp_ret, t_data *data)
{
	int i;

	i = 0;
	if (data->plus == 1 && data->negative == 0)
		tmp_ret = swap_plus(tmp_ret);
	else if (data->negative == 1)
		tmp_ret = swap_minus(tmp_ret);
	else if (data->space == 1)
		tmp_ret[0] = ' ';
	return (tmp_ret);
}
