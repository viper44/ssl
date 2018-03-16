/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aligning_string_sprava.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:43:13 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/01 16:43:14 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

static	char	*ft_string_width(char *string, t_data *data)
{
	char	*tmp;
	int		i;
	char	*del_me;

	i = 0;
	del_me = string;
	tmp = ft_strnew((data->width) - (int)ft_strlen(string));
	if (data->zero == 0)
		while (i < (data->width - (int)ft_strlen(string)))
			tmp[i++] = ' ';
	else
		while (i < (data->width - (int)ft_strlen(string)))
			tmp[i++] = '0';
	string = ft_strjoin(tmp, string);
	free(tmp);
	free(del_me);
	return (string);
}

static	char	*ft_string_precision(char *string, t_data *data)
{
	char *output;

	output = ft_strsub(string, 0, data->precision);
	free(string);
	return (output);
}

void			ft_aligning_string_sprava(char *string, t_data *data)
{
	char *string2;

	string2 = ft_strdup(string);
	if (data->dot == 1)
		string2 = ft_string_precision(string2, data);
	if ((size_t)data->width > ft_strlen(string2))
		string2 = ft_string_width(string2, data);
	data->ret = ft_strlen(string2);
	write(1, string2, data->ret);
	free(string2);
}
