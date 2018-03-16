/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aligning_string_sleva.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:43:24 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/01 16:43:25 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static	char	*ft_string_width(char *string, t_data *data)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	tmp = ft_strnew((data->width) - (int)ft_strlen(string));
	while (i < (data->width - (int)ft_strlen(string)))
	{
		tmp[i] = ' ';
		i++;
	}
	string = ft_strjoin(string, tmp);
	free(tmp);
	return (string);
}

static	char	*ft_string_precision(char *string, t_data *data)
{
	char *output;

	output = ft_strsub(string, 0, data->precision);
	return (output);
}

void			ft_aligning_string_sleva(char *string, t_data *data)
{
	if (data->dot == 1)
		string = ft_string_precision(string, data);
	if ((size_t)data->width > ft_strlen(string))
		string = ft_string_width(string, data);
	data->ret = ft_strlen(string);
	write(1, string, data->ret);
}
