/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:16:48 by msemenov          #+#    #+#             */
/*   Updated: 2018/01/11 15:16:50 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_data
{
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			minus;
	int			plus;
	int			zero;
	int			hash;
	int			dot;
	int			width;
	int			precision;
	int			percent;
	int			space;
	int			negative;
	int			ret;
	int			flag;
}				t_data;

int				ft_isdigit(int c);
void			*ft_memset(void *memptr, int val, size_t num);
char			*ft_strdup(const char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strncpy(char *dst, const char *src, size_t length);
int				ft_atoi(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
char			*ft_strnew(size_t size);
char			*unsigned_itoa_base(unsigned long long int value, int base);
char			*unsigned_itoa_base_sx(unsigned long long int value, int base);
char			*itoa_base(long long int value, int base);
const char		*ft_get_data(const char *f, t_data *data);
const char		*ft_get_width(const char *f, t_data *data);
char			*ft_hash(char *output);
char			*ft_hash_hex(char *output);
char			*ft_hash_hex_b(char *output);
const char		*ft_check_conv(const char *format, t_data *data, va_list ptr);
void			ft_aligning_char_sleva(char c, t_data *data);
void			ft_aligning_char_sprava(char c, t_data *data);
void			ft_aligning_number_sleva_octet(char *output, t_data *data);
void			ft_aligning_number_sleva_hex(char *output, t_data *data);
void			ft_aligning_number_sleva_hex_b(char *output, t_data *data);
void			ft_aligning_number_sprava_octet(char *output, t_data *data);
void			ft_aligning_number_sprava_hex(char *output, t_data *data);
void			ft_aligning_number_sprava_hex_b(char *output, t_data *data);
void			ft_aligning_string_sleva(char *string, t_data *data);
void			ft_aligning_string_sprava(char *string, t_data *data);
void			ft_aligning_string_uni(int nb, t_data *data);
void			ft_aligning_number_sleva(char *output, t_data *data);
void			ft_aligning_number_sprava (char *output, t_data *data);
void			ft_output_number(t_data *data, va_list ptr, const char *format);
void			ft_output_char_uni(t_data *data, va_list ptr);
void			ft_aligning_char_uni_sprava(int nb, t_data *data);
void			ft_aligning_char_uni_sleva(int nb, t_data *data);
void			ft_aligning_pointer_sprava (char *output, t_data *data);
void			ft_aligning_pointer_sleva (char *output, t_data *data);
void			ft_output_unb_int(t_data *data, va_list ptr);
void			ft_output_hex(t_data *data, va_list ptr);
void			ft_output_pointer(t_data *data, va_list ptr);
void			ft_output_char(t_data *data, va_list ptr, char const *format);
void			ft_output_string(t_data *data, va_list ptr);
void			ft_output_string_uni(t_data *data, va_list ptr);
void			ft_output_un_int(t_data *data, va_list ptr);
void			ft_output_hex_b(t_data *data, va_list ptr);
void			ft_output_octet(t_data *data, va_list ptr, const char *output);
char			*ft_plus_minus_space(char *output, char *tmp, t_data *data);
char			*ft_add_space(char *tmp, t_data *data);
char			*ft_kostil(char *tmp_ret, t_data *data);
char			*ft_add_plus(char *tmp);
void			ft_output(char *output, t_data *data);
int				ft_printf(const char *format, ...);

#endif
