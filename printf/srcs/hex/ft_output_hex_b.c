/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:43:38 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/12 15:43:39 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static int		ft_l(t_data *data, va_list ptr)
{
	char	*point_string;

	point_string = unsigned_itoa_base((va_arg(ptr, unsigned long int)), 16);
	if (data->minus == 1)
		ft_aligning_number_sleva_hex_b(point_string, data);
	else
		ft_aligning_number_sprava_hex_b(point_string, data);
	return (1);
}

static int		ft_ll(t_data *data, va_list ptr)
{
	char	*point_string;

	point_string = unsigned_itoa_base((va_arg(ptr, uint64_t)), 16);
	if (data->minus == 1)
		ft_aligning_number_sleva_hex_b(point_string, data);
	else
		ft_aligning_number_sprava_hex_b(point_string, data);
	return (1);
}

static int		ft_h(t_data *data, va_list ptr)
{
	unsigned int	d;
	char			*point_string;

	d = va_arg(ptr, int);
	d = (unsigned short)d;
	point_string = unsigned_itoa_base(d, 16);
	if (data->minus == 1)
		ft_aligning_number_sleva_hex_b(point_string, data);
	else
		ft_aligning_number_sprava_hex_b(point_string, data);
	return (1);
}

static int		ft_hh(t_data *data, va_list ptr)
{
	unsigned int	d;
	char			*point_string;

	d = va_arg(ptr, int);
	d = (unsigned char)d;
	point_string = unsigned_itoa_base(d, 16);
	if (data->minus == 1)
		ft_aligning_number_sleva_hex_b(point_string, data);
	else
		ft_aligning_number_sprava_hex_b(point_string, data);
	return (1);
}

void			ft_output_hex_b(t_data *data, va_list ptr)
{
	unsigned int	d;
	char			*point_string;

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
		d = va_arg(ptr, unsigned int);
		point_string = unsigned_itoa_base(d, 16);
		if (data->minus == 1)
			ft_aligning_number_sleva_hex_b(point_string, data);
		else
			ft_aligning_number_sprava_hex_b(point_string, data);
	}
}
