/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aligning_pointer_sleva.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:56:55 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/08 17:56:56 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static char	*ft_zero(t_data *data, char *output)
{
	char *tmp;

	data->hash = 0;
	if (output[0] == '0' && ft_strlen(output) == 1 &&
		data->width == 0 && data->dot == 1 && data->precision == 0)
	{
		tmp = ft_strnew(2);
		tmp[0] = '0';
		tmp[1] = 'x';
		data->ret = 2;
		return (tmp);
	}
	else
	{
		tmp = ft_strnew(3);
		tmp[0] = '0';
		tmp[1] = 'x';
		tmp[2] = '0';
		data->ret = 3;
		return (tmp);
	}
}

static char	*ft_precision(char *output, t_data *data, int size)
{
	char	*tmp;
	int		size_precision;
	int		i;
	char	*del_me;

	i = 0;
	del_me = output;
	size_precision = data->precision - size;
	tmp = ft_strnew(size_precision);
	while (i < size_precision)
	{
		tmp[i] = '0';
		i++;
	}
	output = ft_strjoin(output, tmp);
	free(del_me);
	free(tmp);
	return (output);
}

static char	*ft_width(char *tmp, t_data *data)
{
	int		size_tmp2;
	char	*tmp2;
	char	*tmp_ret;

	size_tmp2 = data->width - ft_strlen(tmp);
	tmp2 = ft_strnew(size_tmp2);
	size_tmp2 -= 1;
	while (size_tmp2 >= 0)
		tmp2[size_tmp2--] = ' ';
	tmp_ret = ft_strjoin(tmp, tmp2);
	free(tmp2);
	free(tmp);
	return (tmp_ret);
}

void		ft_aligning_pointer_sleva(char *output, t_data *data)
{
	int size;

	size = ft_strlen(output);
	if (output[0] == '0')
		output = ft_zero(data, output);
	if (data->precision >= size)
		output = ft_precision(output, data, size);
	if ((int)ft_strlen(output) + 1 >= data->width && data->hash == 1 &&
		output[0] != '\0')
		output = ft_hash_hex(output);
	if (data->width > (int)ft_strlen(output))
	{
		if (data->zero == 0 && data->hash == 1)
			output = ft_hash_hex(output);
		output = ft_width(output, data);
		if (data->hash == 1 && data->zero == 1)
		{
			output[0] = '0';
			output[1] = 'x';
		}
	}
	ft_output(output, data);
}
