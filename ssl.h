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
#include <fcntl.h>
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
	char		*right_expand;
	int			raund;
	char		*new_hrm;
	int			**ar_s;
	char		*half_l;
	char		*half_r;
	char		**sub_keys;
	char		**message;
	int			mes_size;
	char		*final;
	int			cut;
	char		**flags;
	int			flags_count;
	int			e;
	int			d;
	int			a;
	int			k;
	int			base64;
	int			i;
	int			o;
	char		*hex;
	char		*file_name;
	char		*file_name2;
	int			no_filename;
}			   t_ssl;

char			*itoa_base(long long int value, int base);
int				ft_reveres_itoa(char *str, int base);
void			ft_base64_encode(t_ssl *ssl);
void			ft_base64_encode2(t_ssl *ssl, char	*str, int fd);
void			ft_base64_decode(t_ssl *ssl);
void			ft_base64_decode2(t_ssl *ssl);
void			ft_des_encription(t_ssl *ssl);
char 			*final_perm(char *str);
char			*ft_convert_2(int tmp, int base);
void			ft_message(t_ssl *ssl);
void			ft_message_enc(t_ssl *ssl);
void			ft_rolling(t_ssl *ssl);
void			ft_s_box_work(t_ssl *ssl);
void			ft_shift_cycle(t_ssl *ssl);
void			ft_swap(t_ssl *ssl);
void			ft_print_binary(char *ret, t_ssl *ssl);
void			ft_des_encription2(t_ssl *ssl, const char *str);
void			ft_des_encription3(t_ssl *ssl, const char *ret);
void			ft_des_encription4(t_ssl *ssl, const char *ret);
void			ft_rolling2(t_ssl *ssl);
void			ft_des_decription(t_ssl *ssl);
void			ft_message_decription(t_ssl *ssl);
void			ft_message_decription3(t_ssl *ssl, char *ptext);
void			ft_message_decription4(t_ssl *ssl, char *file_name);
void			ft_des_decription2(t_ssl *ssl, const char *str);
void			ft_des_decription3(t_ssl *ssl, char *ptext, const char *key);
void			ft_des_decription4(t_ssl *ssl, const char *key, char *message);
void			ft_cut_the_tail(t_ssl *ssl, char *ret);
void			ft_print_base64(char *line, t_ssl *ssl, int i);
void			ft_print_base64_fd(char *line, t_ssl *ssl, int i, int fd);
void			ft_check_base64(t_ssl *ssl);
void			ft_check_des(t_ssl *ssl);
void			ft_print_binary_fd(char *ret, t_ssl *ssl, int fd);	
char			*ft_read_file(int fd);
char			*ft_read_file2(int fd);
char			*ft_read_term(void);
int				ft_nofilename(void);
int				ft_creat_file(void);
void			ft_print_error(void);
char			*ft_butcher(char *str);
char			*ft_read_term2(void);

#endif