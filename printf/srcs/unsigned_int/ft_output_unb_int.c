/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_unb_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:54:36 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/02 18:54:37 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

void	ft_output_unb_int(t_data *data, va_list ptr)
{
	char				*point_string;
	unsigned long long	d;

	d = va_arg(ptr, unsigned long long int);
	point_string = unsigned_itoa_base(d, 10);
	if (data->minus == 1)
		ft_aligning_number_sleva_octet(point_string, data);
	else
		ft_aligning_number_sprava_octet(point_string, data);
}
