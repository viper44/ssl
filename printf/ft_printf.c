/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:33:32 by msemenov          #+#    #+#             */
/*   Updated: 2018/01/11 14:33:35 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static t_data		ft_go_zero(void)
{
	t_data data;

	data.hh = 0;
	data.h = 0;
	data.l = 0;
	data.ll = 0;
	data.j = 0;
	data.z = 0;
	data.minus = 0;
	data.plus = 0;
	data.zero = 0;
	data.hash = 0;
	data.dot = 0;
	data.percent = 0;
	data.width = 0;
	data.precision = 0;
	data.space = 0;
	data.negative = 0;
	data.ret = 0;
	return (data);
}

static int			ft_c(const char *f, t_data *data)
{
	char c;

	c = *f;
	if (*f == 'd' || *f == 'i' || *f == 'D' || *f == 'o' || *f == 'x' ||
		*f == 'X' || *f == 'u' || *f == 'c' || *f == '%' || *f == 's' ||
		*f == 'U' || *f == 'C' || *f == 'S' || *f == 'p' || *f == 'O')
		return (1);
	else
	{
		if (data->minus == 1)
			ft_aligning_char_sleva(c, data);
		else
			ft_aligning_char_sprava(c, data);
		return (0);
	}
}

static int			ft_check(const char *format, va_list ptr)
{
	t_data	data;
	int		ret;

	ret = 0;
	while (*format != '\0')
	{
		data = ft_go_zero();
		while (*format != '%' && *format != '\0')
		{
			write(1, format, 1);
			ret += 1;
			format++;
		}
		if (*format == '%')
		{
			format++;
			format = ft_get_data(format, &data);
		}
		if (*format == '\0')
			break ;
		(!(ft_c(format, &data))) ? (format += 1) :
		(format = ft_check_conv(format, &data, ptr));
		ret += data.ret;
	}
	return (ret);
}

int					ft_printf(const char *format, ...)
{
	int			ret;
	va_list		(ptr);

	ret = 0;
	va_start(ptr, format);
	ret = ft_check(format, ptr);
	va_end(ptr);
	return (ret);
}
