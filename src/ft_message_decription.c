/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_decription.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static	int	g_plaintext_perm_tab[64] ={58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44,\
		36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24,\
		16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61,\
		53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};

static void	ft_split_mes(char *ret, t_ssl *ssl)
{
	int i;
	int n;

	i = 0;
	n = 0;
	ssl->half_l_m = ft_strnew(32);
	ssl->half_r_m = ft_strnew(32);
	while(i < 32)
	{
		ssl->half_l_m[i] = ret[i];
		i++;
	}
	while(i < 64)
		ssl->half_r_m[n++]  = ret[i++];
	//printf("splited mes %s %s\n", ssl->half_l_m, ssl->half_r_m);
}

static char *permutation_text(char *str)
{
	char *ret;
	int	i;

	i = 0;
	ret = ft_strnew(64);
	while (i < 64)
	{
		ret[i] = str[g_plaintext_perm_tab[i] - 1];
		i++;
	}
	free(str);
	return (ret);
}

static void	ft_message_dec(t_ssl *ssl)
{
	int i;
	char	*ret;

	i = 0;
	while (ssl->message[i])
	{
		ret = permutation_text(ssl->message[i]);
		ft_split_mes(ret, ssl);
		ft_rolling2(ssl);
		i++;
	}
}

static char	**ft_split_string(char *line)
{
	char **ret;
	int	count;
	int	line_size;
	int	i;
	int	n;

	i = 0;
	n = 0;
	line_size = ft_strlen(line);
	count = 0;
	while(line_size)
	{
		line_size = line_size - 64;
		count++;
	}
	ret =(char**)malloc(sizeof(char*) * count + 1);
	ret[count] = NULL;
	while (count--)
	{
		ret[i++] = ft_strsub(line, n, 64);
		n += 64;
	}
	free (line);
	return (ret);
}

void	ft_message_decription(t_ssl *ssl)
{
	char	*line;
	int		fd;

	fd = 0;
	if (ssl->a == 1)
		line = ft_butcher(ssl->ret_str);
	else if (ssl->i == 1)
	{
		if (ssl->file_name)
		{
			fd = open(ssl->file_name, O_RDONLY);
				if (fd == -1)
					ft_print_error();
		}
		else
			fd = ft_nofilename();		
		line = ft_read_file(fd);
	}
	ssl->string_size = ft_strlen(line) / 8;
	if (ft_strlen(line) % 64 != 0)
		exit(1);
	ssl->message = ft_split_string(line);
	ft_message_dec(ssl);
}
