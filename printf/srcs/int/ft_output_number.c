/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:38:23 by msemenov          #+#    #+#             */
/*   Updated: 2018/01/23 15:38:26 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static int		ft_l(t_data *data, va_list ptr)
{
	char *point_string;

	point_string = itoa_base((va_arg(ptr, long int)), 10);
	if (point_string[0] == '-')
		data->negative = 1;
	if (data->minus == 1)
		ft_aligning_number_sleva(point_string, data);
	else
		ft_aligning_number_sprava(point_string, data);
	return (1);
}

static int		ft_ll(t_data *data, va_list ptr)
{
	char *point_string;

	point_string = itoa_base((va_arg(ptr, long long int)), 10);
	if (point_string[0] == '-')
		data->negative = 1;
	if (data->minus == 1)
		ft_aligning_number_sleva(point_string, data);
	else
		ft_aligning_number_sprava(point_string, data);
	return (1);
}

static int		ft_h(t_data *data, va_list ptr)
{
	int		d;
	char	*point_string;

	d = va_arg(ptr, int);
	d = (short)d;
	point_string = itoa_base(d, 10);
	if (point_string[0] == '-')
		data->negative = 1;
	if (data->minus == 1)
		ft_aligning_number_sleva(point_string, data);
	else
		ft_aligning_number_sprava(point_string, data);
	return (1);
}

static int		ft_hh(t_data *data, va_list ptr)
{
	int		d;
	char	*point_string;

	d = va_arg(ptr, int);
	d = (signed char)d;
	point_string = itoa_base(d, 10);
	if (point_string[0] == '-')
		data->negative = 1;
	if (data->minus == 1)
		ft_aligning_number_sleva(point_string, data);
	else
		ft_aligning_number_sprava(point_string, data);
	return (1);
}

void			ft_output_number(t_data *data, va_list ptr, const char *f)
{
	int		d;
	char	*point_string;

	if (*f == 'D' && ft_ll(data, ptr))
		return ;
	if ((data->ll == 1 || data->z == 1 || data->j == 1) && (ft_ll(data, ptr)))
		return ;
	else if ((data->l == 1) && (ft_l(data, ptr)))
		return ;
	else if ((data->hh == 1) && (ft_hh(data, ptr)))
		return ;
	else if ((data->h == 1) && (ft_h(data, ptr)))
		return ;
	else
	{
		d = va_arg(ptr, int);
		point_string = itoa_base(d, 10);
		if (point_string[0] == '-')
			data->negative = 1;
		if (data->minus == 1)
			ft_aligning_number_sleva(point_string, data);
		else
			ft_aligning_number_sprava(point_string, data);
	}
}
