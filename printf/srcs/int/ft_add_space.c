/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:54:28 by msemenov          #+#    #+#             */
/*   Updated: 2018/01/23 15:54:30 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

char	*ft_add_space(char *tmp, t_data *data)
{
	char	*space;
	char	*ptr;

	ptr = tmp;
	space = ft_strnew(1);
	space[0] = ' ';
	tmp = ft_strjoin(space, tmp);
	data->space = 0;
	free(ptr);
	free(space);
	return (tmp);
}
