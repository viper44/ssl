/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 11:17:48 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/08 11:17:49 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

void	ft_output_pointer(t_data *data, va_list ptr)
{
	unsigned long int	d;
	char				*point_string;
	int					size;

	d = va_arg(ptr, unsigned long int);
	point_string = unsigned_itoa_base_sx(d, 16);
	size = ft_strlen(point_string);
	data->hash = 1;
	if (data->minus == 1)
		ft_aligning_pointer_sleva(point_string, data);
	else
		ft_aligning_pointer_sprava(point_string, data);
}
