/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aligning_pointer_sprava.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:56:40 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/08 17:56:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static char		*ft_precision(char *output, t_data *data, int size)
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
	output = ft_strjoin(tmp, output);
	free(del_me);
	free(tmp);
	return (output);
}

static char		*ft_width(char *tmp, t_data *data)
{
	int		size_tmp2;
	char	*tmp2;
	char	*tmp_ret;

	tmp_ret = NULL;
	size_tmp2 = data->width - ft_strlen(tmp);
	tmp2 = ft_strnew(size_tmp2);
	size_tmp2 -= 1;
	if (data->width > 0 && (data->zero == 0 || data->dot == 1))
	{
		while (size_tmp2 >= 0)
			tmp2[size_tmp2--] = ' ';
		tmp_ret = ft_strjoin(tmp2, tmp);
	}
	else if (data->precision == 0 && data->zero == 1 && data->dot == 0)
	{
		while (size_tmp2 >= 0)
			tmp2[size_tmp2--] = '0';
		tmp_ret = ft_strjoin(tmp, tmp2);
	}
	free(tmp2);
	free(tmp);
	return (tmp_ret);
}

static char		*ft_zero(t_data *data)
{
	char	*tmp;
	char	*tmp2;
	char	*del_me;
	int		size_precision;
	int		i;

	i = 0;
	tmp2 = NULL;
	tmp = ft_strnew(3);
	tmp[0] = '0';
	tmp[1] = 'x';
	tmp[2] = '0';
	del_me = tmp;
	size_precision = data->precision - 1;
	if (data->precision > 0)
	{
		tmp2 = ft_strnew(size_precision);
		ft_memset(tmp2, 48, size_precision);
	}
	if (tmp2 != NULL)
		tmp = ft_strjoin(tmp, tmp2);
	if (data->width > (int)ft_strlen(tmp))
		tmp = ft_width(tmp, data);
	return (tmp);
}

void			ft_aligning_pointer_sprava(char *out, t_data *data)
{
	if (out[0] == '0' && data->dot == 0)
	{
		out = ft_zero(data);
		ft_output(out, data);
		return ;
	}
	if (data->precision >= (int)ft_strlen(out))
		out = ft_precision(out, data, ft_strlen(out));
	if ((int)ft_strlen(out) + 1 >= data->width &&
		data->hash == 1 && out[0] != '\0')
		out = ft_hash_hex(out);
	if (data->width > (int)ft_strlen(out))
	{
		if (data->zero == 0 && data->hash == 1)
			out = ft_hash_hex(out);
		out = ft_width(out, data);
	}
	if ((data->hash == 1 && data->zero == 1) || (out[0] == '0'))
	{
		out[0] = '0';
		out[1] = 'x';
	}
	ft_output(out, data);
}
