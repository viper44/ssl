/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aligning_char_sleva.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:20:59 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/08 14:21:00 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

void	ft_aligning_char_sleva(char c, t_data *data)
{
	char	*width;
	int		i;

	i = 0;
	width = NULL;
	if (data->width > 0)
	{
		width = ft_strnew(data->width);
		width[data->width - 1] = '\0';
		while (i < (data->width - 1))
		{
			width[i] = ' ';
			i++;
		}
		write(1, &c, 1);
		write(1, width, ft_strlen(width));
		data->ret = (int)ft_strlen(width) + 1;
		free(width);
		return ;
	}
	write(1, &c, 1);
	data->ret = 1;
	return ;
}
