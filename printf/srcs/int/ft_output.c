/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:16:09 by msemenov          #+#    #+#             */
/*   Updated: 2018/01/23 16:16:29 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

void	ft_output(char *output, t_data *data)
{
	data->ret = (int)ft_strlen(output);
	write(1, output, ft_strlen(output));
	free(output);
}
