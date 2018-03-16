/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aligning_char_sprava.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:20:46 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/08 14:20:47 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

void	ft_aligning_char_sprava(char c, t_data *data)
{
	char	*width;
	int		i;

	i = 0;
	if (data->width > 0)
	{
		width = ft_strnew(data->width);
		width[data->width - 1] = '\0';
		while (i < (data->width - 1))
		{
			if (data->zero == 1)
				width[i] = '0';
			else
				width[i] = ' ';
			i++;
		}
		write(1, width, ft_strlen(width));
		write(1, &c, 1);
		data->ret = (int)ft_strlen(width) + 1;
		free(width);
		return ;
	}
	write(1, &c, 1);
	data->ret = 1;
	return ;
}
