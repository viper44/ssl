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
#include "printf.h"
# define BUFF_SIZE 1

typedef struct s_ssl
{
	int			ret_encode;
	int			string_size;
	int			ret_decode;
	int			*arr_ret;
	int			*arr_base;
	int			arr_size;
	int			byte_counter;
	int			counter;
	int			pad_count;
	char		*ret_str;
	char		*maj_key;
	char		*mid_key;
	char		*half_l_m;
	char		*half_r_m;
	int			**ar_s;
	char		*half_l;
	char		*half_r;
	char		**sub_keys;
	char		**message;
}			   t_ssl;

char			*itoa_base(long long int value, int base);
int				ft_reveres_itoa(char *str, int base);
void			ft_encode(t_ssl *ssl);
void			ft_decode(t_ssl *ssl);

#endif