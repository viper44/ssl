/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aligning_number_sprava_hex.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:11:26 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/02 16:11:28 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static char		*ft_precision(char *output, t_data *data)
{
	char	*tmp;
	int		size_precision;
	int		size_output;

	size_precision = data->precision;
	size_output = ft_strlen(output);
	tmp = ft_strnew(size_precision);
	while (size_output >= 0)
		tmp[size_precision--] = output[size_output--];
	while (size_precision >= 0)
		tmp[size_precision--] = '0';
	free(output);
	return (tmp);
}

static char		*ft_width(char *tmp, t_data *data)
{
	int		size_tmp2;
	char	*tmp2;
	char	*tmp_ret;

	size_tmp2 = data->width - ft_strlen(tmp);
	tmp2 = ft_strnew(size_tmp2);
	size_tmp2 -= 1;
	if (data->width > 0 && (data->zero == 0 || data->dot == 1))
		while (size_tmp2 >= 0)
			tmp2[size_tmp2--] = ' ';
	else if (data->precision == 0 && data->zero == 1 && data->dot == 0)
		while (size_tmp2 >= 0)
			tmp2[size_tmp2--] = '0';
	tmp_ret = ft_strjoin(tmp2, tmp);
	free(tmp2);
	free(tmp);
	return (tmp_ret);
}

void			ft_aligning_number_sprava_hex(char *output, t_data *data)
{
	if (output[0] == '0' && data->dot == 1 &&
		data->precision == 0 && ft_strlen(output) == 1)
		output[0] = '\0';
	if (data->precision >= (int)ft_strlen(output))
		output = ft_precision(output, data);
	if ((int)ft_strlen(output) + 1 >= data->width &&
		data->hash == 1 && output[0] != '\0')
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
