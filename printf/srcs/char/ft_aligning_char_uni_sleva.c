/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aligning_char_uni_sleva.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:52:00 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/06 17:52:01 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static void		ft_mask(unsigned int nb, t_data *data)
{
	write(1, &nb, 1);
	if (data->width > 0)
		data->ret = data->width;
	else
		data->ret = 1;
}

static void		ft_mask1(unsigned int nb, t_data *data)
{
	int mask1;
	int res;
	int mask;

	mask = 128;
	res = 0;
	mask1 = 192;
	res = (nb >> 6);
	res = mask1 | res;
	write(1, &res, 1);
	res = (nb << 26) >> 26;
	res = mask | res;
	write(1, &res, 1);
	if (data->width > 0)
		data->ret = data->width + 2;
	else
		data->ret = 2;
}

static void		ft_mask2(unsigned int nb, t_data *data)
{
	int mask1;
	int mask;
	int res;

	res = 0;
	mask = 128;
	mask1 = 224;
	res = (nb >> 12);
	res = mask1 | res;
	write(1, &res, 1);
	res = mask | ((nb << 20) >> 26);
	write(1, &res, 1);
	res = mask | ((nb << 26) >> 26);
	write(1, &res, 1);
	if (data->width > 0)
		data->ret = data->width + 3;
	else
		data->ret = 3;
}

static void		ft_mask3(unsigned int nb, t_data *data)
{
	int mask1;
	int res;
	int mask;

	mask = 128;
	res = 0;
	mask1 = 240;
	res = (nb >> 18);
	res = mask1 | res;
	write(1, &res, 1);
	res = mask | ((nb << 14) >> 26);
	write(1, &res, 1);
	res = mask | ((nb << 20) >> 26);
	write(1, &res, 1);
	res = mask | ((nb << 26)) >> 26;
	write(1, &res, 1);
	if (data->width > 0)
		data->ret = data->width + 4;
	else
		data->ret = 4;
}

void			ft_aligning_char_uni_sleva(int nb, t_data *data)
{
	char	*width;
	int		i;

	i = 0;
	width = NULL;
	if (nb > 127 && nb < 2048)
		ft_mask1(nb, data);
	else if (nb > 2047 && nb < 65536)
		ft_mask2(nb, data);
	else if (nb > 65535)
		ft_mask3(nb, data);
	else
		ft_mask(nb, data);
	if (data->width > 0)
	{
		width = ft_strnew(data->width);
		while (i < (data->width))
		{
			width[i] = ' ';
			i++;
		}
		write(1, width, ft_strlen(width));
		free(width);
	}
}
