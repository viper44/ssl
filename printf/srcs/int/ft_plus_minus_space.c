/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_minus_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:27:06 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/12 16:27:08 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

char	*ft_plus_minus_space(char *output, char *tmp, t_data *data)
{
	if (output[0] == '-')
		tmp[0] = '-';
	else if (data->plus == 1 && output[0] != '-')
	{
		tmp[0] = '+';
		data->plus = 0;
	}
	else if (data->space == 1)
	{
		tmp[0] = ' ';
		data->space = 0;
	}
	return (tmp);
}
