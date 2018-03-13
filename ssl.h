/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 10:18:37 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 10:18:38 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
# define SSL_H
# include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
# define BUFF_SIZE 1

typedef struct s_data
{
	int			ret;
	int			*arr_ret;
	int			*arr_base;
	int			arr_size;
	int			byte_counter;
}			   t_data;


char			*itoa_base(long long int value, int base);

#endif