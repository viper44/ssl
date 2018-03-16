/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:06:16 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/12 15:06:18 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static int		ft_l(t_data *data, va_list ptr)
{
	ft_output_char_uni(data, ptr);
	return (1);
}

void			ft_output_char(t_data *data, va_list ptr, char const *format)
{
	char c;

	if ((data->l == 1 && ft_l(data, ptr)))
		return ;
	if (*format == '%')
	{
		c = '%';
		if (data->minus == 1)
			ft_aligning_char_sleva(c, data);
		else
			ft_aligning_char_sprava(c, data);
		return ;
	}
	else
	{
		c = va_arg(ptr, int);
		c = (char)c;
		if (data->minus == 1)
			ft_aligning_char_sleva(c, data);
		else
			ft_aligning_char_sprava(c, data);
	}
}
