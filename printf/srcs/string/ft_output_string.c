/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:13:11 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/01 16:13:13 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static void	ft_null(t_data *data)
{
	char *null;

	null = "(null)";
	if (data->minus == 1)
		ft_aligning_string_sleva(null, data);
	else
		ft_aligning_string_sprava(null, data);
}

static int	ft_l(t_data *data, va_list ptr)
{
	ft_output_string_uni(data, ptr);
	return (1);
}

void		ft_output_string(t_data *data, va_list ptr)
{
	char *string;

	if ((data->l == 1 && ft_l(data, ptr)))
		return ;
	else
	{
		string = va_arg(ptr, char*);
		if (string == NULL)
		{
			ft_null(data);
			return ;
		}
		if (data->minus == 1)
			ft_aligning_string_sleva(string, data);
		else
			ft_aligning_string_sprava(string, data);
	}
}
