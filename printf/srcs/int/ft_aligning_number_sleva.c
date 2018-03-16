/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aligning_number_sleva.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:47:54 by msemenov          #+#    #+#             */
/*   Updated: 2018/01/23 15:47:59 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static char		*ft_precision(char *output, t_data *data)
{
	char	*tmp;
	int		size_precision;
	int		size_output;

	if (data->plus == 1 || output[0] == '-' || data->space == 1)
		size_precision = data->precision + 1;
	else
		size_precision = data->precision;
	size_output = ft_strlen(output);
	tmp = ft_strnew(size_precision);
	while (size_output >= 0)
		tmp[size_precision--] = output[size_output--];
	if (output[0] == '-')
		tmp[size_precision++] = '0';
	while (size_precision >= 0)
		tmp[size_precision--] = '0';
	tmp = ft_plus_minus_space(output, tmp, data);
	free(output);
	return (tmp);
}

static char		*ft_special_case(t_data *data)
{
	int		size;
	char	*tmp;

	if (data->plus == 1)
		size = 1;
	else
		size = 0;
	tmp = ft_strnew(size);
	if (data->plus == 1)
	{
		tmp[0] = '+';
		data->plus = 0;
	}
	return (tmp);
}

static char		*ft_plus(char *output)
{
	char	*tmp;
	int		size_output;
	int		size_tmp;

	size_output = ft_strlen(output);
	size_tmp = size_output + 1;
	tmp = ft_strnew(size_tmp);
	while (size_output >= 0)
	{
		tmp[size_tmp] = output[size_output];
		size_tmp--;
		size_output--;
	}
	tmp[0] = '+';
	free(output);
	return (tmp);
}

static char		*ft_width_left(char *tmp, t_data *data)
{
	int		size_tmp2;
	char	*tmp2;
	char	*tmp_ret;

	if (data->plus == 1 && tmp[0] != '-')
		tmp = ft_add_plus(tmp);
	if (data->space == 1 && tmp[0] != '-' && tmp[0] != '+')
		tmp = ft_add_space(tmp, data);
	size_tmp2 = data->width - ft_strlen(tmp);
	tmp2 = ft_strnew(size_tmp2);
	size_tmp2 -= 1;
	while (size_tmp2 >= 0)
		tmp2[size_tmp2--] = ' ';
	tmp_ret = ft_strjoin(tmp, tmp2);
	if (data->plus == 1 && data->dot != 1 &&
		data->precision == 0 && data->zero == 1)
		tmp_ret = ft_kostil(tmp_ret, data);
	data->space = 0;
	free(tmp2);
	free(tmp);
	return (tmp_ret);
}

void			ft_aligning_number_sleva(char *output, t_data *data)
{
	char *tmp;

	tmp = NULL;
	if (data->dot == 1 && data->precision == 0 && output[0] == '0')
		tmp = ft_special_case(data);
	if (data->precision >= (int)ft_strlen(output))
		tmp = ft_precision(output, data);
	if (tmp != NULL)
	{
		if (data->width > data->precision)
		{
			data->plus = 0;
			data->space = 0;
			tmp = ft_width_left(tmp, data);
		}
	}
	else if (data->width > (int)ft_strlen(output))
		tmp = ft_width_left(output, data);
	else if (data->plus == 1 && *output != '-')
		output = ft_plus(output);
	if (tmp != NULL)
		ft_output(tmp, data);
	else
		ft_output(output, data);
}
