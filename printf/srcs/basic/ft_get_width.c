/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:27:20 by msemenov          #+#    #+#             */
/*   Updated: 2018/01/23 15:27:23 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

const char	*ft_get_width(const char *f, t_data *data)
{
	if (ft_atoi(f) > 0)
	{
		data->width = ft_atoi(f);
		while (ft_isdigit(*f))
			f++;
		f--;
	}
	return (f);
}
