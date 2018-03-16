/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string_uni.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:22:05 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/07 11:22:06 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static int	ft_check_size(int i)
{
	int ret;

	ret = 0;
	if (i < 128)
		ret = 1;
	else if (i > 127 && i < 2048)
		ret = 2;
	else if (i > 2047 && i < 65536)
		ret = 3;
	else if (i > 65535)
		ret = 4;
	return (ret);
}

static int	ft_printf_spaces(t_data *data)
{
	int i;

	i = 0;
	if (data->zero == 1)
	{
		while (i < data->width)
		{
			write(1, "0", 1);
			i++;
		}
	}
	else
	{
		while (i < data->width)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i);
}

static void	ft_widht_right(unsigned int *array, t_data *data)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	if (data->dot == 1)
		while (array[i] != '\0')
		{
			if ((size + ft_check_size(array[i]) <= data->precision)
				&& data->dot == 1)
				size = size + ft_check_size(array[i]);
			i++;
		}
	else
		while (array[i] != '\0')
			size += ft_check_size(array[i++]);
	i = 0;
	if (data->width > size)
	{
		data->width = data->width - size;
		i = ft_printf_spaces(data);
	}
	data->ret = data->ret + i;
}

static void	ft_null(t_data *data)
{
	char *null;

	null = "(null)";
	if (data->minus == 1)
		ft_aligning_string_sleva(null, data);
	else
		ft_aligning_string_sprava(null, data);
}

void		ft_output_string_uni(t_data *data, va_list ptr)
{
	unsigned int	*array;
	int				i;
	int				size;

	size = 0;
	i = 0;
	array = va_arg(ptr, unsigned int*);
	if (array == NULL)
	{
		ft_null(data);
		return ;
	}
	if (data->minus != 1 && data->width > data->precision)
		ft_widht_right(array, data);
	while (array[i] != '\0')
	{
		if ((size += ft_check_size(array[i])) <= data->precision &&
		data->dot == 1)
			ft_aligning_string_uni(array[i], data);
		else if (data->dot == 0)
			ft_aligning_string_uni(array[i], data);
		i++;
	}
	if (data->minus == 1 && data->width > data->precision)
		ft_widht_right(array, data);
}
