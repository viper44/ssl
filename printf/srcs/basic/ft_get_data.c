/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:23:27 by msemenov          #+#    #+#             */
/*   Updated: 2018/01/23 15:23:28 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static const char	*ft_check_hh(const char *f, t_data *data)
{
	int h;

	h = 0;
	while (*f == 'h')
	{
		h++;
		f++;
	}
	if (h % 2 == 0)
		data->hh = 1;
	else
		data->h = 1;
	f--;
	return (f);
}

static const char	*ft_get_precision(const char *f, t_data *data)
{
	data->dot = 1;
	data->precision = 0;
	f++;
	if (ft_isdigit(*f))
	{
		data->precision = ft_atoi(f);
		while (ft_isdigit(*f))
			f++;
	}
	f--;
	return (f);
}

static void			ft_get_modes(const char *f, t_data *data)
{
	if (*f == '#')
		data->hash = 1;
	if (*f == '0')
		data->zero = 1;
	if (*f == '-')
		data->minus = 1;
	if (*f == '+')
		data->plus = 1;
	if (*f == 'j')
		data->j = 1;
	if (*f == 'z')
		data->z = 1;
	if (*f == ' ')
		data->space = 1;
	if (*f == '%')
		data->percent += 1;
}

static int			ft_valid(const char *f)
{
	if (*f != '#' && *f != '0' && *f != '-' && *f != '+'
		&& *f != 'j' && *f != 'z' && *f != 'h' && *f != 'l'
		&& *f != '.' && ft_isdigit(*f) != 1 && *f != ' ')
		return (0);
	return (1);
}

const char			*ft_get_data(const char *f, t_data *data)
{
	while (*f != '\0' && *f != 'c' && *f != 'd' && *f != 's' && *f != 'i'
		&& *f != 'S' && *f != 'p' && *f != 'D' && *f != 'o' && *f != 'O'
		&& *f != 'u' && *f != 'x' && *f != 'X' && *f != 'C' && *f != '%')
	{
		if (!ft_valid(f))
			return (f);
		ft_get_modes(f, data);
		if (*f == 'h')
			f = ft_check_hh(f, data);
		if (*f == 'l')
			data->l = 1;
		if (*f == 'l')
		{
			f++;
			if (*f == 'l')
				data->ll = 1;
			f--;
		}
		if (ft_isdigit(*f))
			f = ft_get_width(f, data);
		if (*f == '.')
			f = ft_get_precision(f, data);
		f++;
	}
	return (f);
}
