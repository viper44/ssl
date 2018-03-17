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

static	int g_comp_perm_tab[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,\
		23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,41, 52, 31, 37, 47, 55, 30, 40,\
		51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

static int g_perm_tab[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2,\
		59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15,\
		7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};

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