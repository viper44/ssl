/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_des.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static int	ft_find_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

static void	ft_print_options(void)
{
	printf("%s\n", "Error");
}

static int		ft_check_hex(char *str)
{
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789ABCDEF";
	while (str[i])
	{
		if (!ft_find_char(hex, str[i++]))
			return (0);
	}
	return (1);
}

int	ft_check_o(char *big, int i, t_ssl *ssl)
{
	if (ssl->flags[++i])
	{
		if (ft_strstr(big, ssl->flags[i]))
		{
			i--;
			ssl->no_filename = 1;
		}
		else
			ssl->file_name2 = ft_strdup(ssl->flags[i]);
	}
	return (i);
}

int	ft_check_i(char *big, int i, t_ssl *ssl)
{
	if (ssl->flags[++i])
	{
		if (ft_strstr(big, ssl->flags[i]))
		{
			i--;
			ssl->no_filename = 1;
		}
		else
			ssl->file_name = ft_strdup(ssl->flags[i]);
	}
	else
	{
		ssl->no_filename = 1;
		i = 0;
	}
	return (i);
}

int	ft_check_k(int i, t_ssl *ssl)
{
	if (ssl->flags[++i])
	{
		if(!ft_check_hex(ssl->flags[i]))
			return (0);
		else
			ssl->hex = ft_strdup(ssl->flags[i]);
	}
	else
		return (0);
	return (i);
}

static int		ft_valid_flag(t_ssl *ssl)
{
	int		i;
	char	*flags;

	i = 2;
	flags = "-e-d-a-k-i-o-base64";
	while (i < ssl->flags_count)
	{
		if (!ft_strstr(flags, ssl->flags[i]))
			return (0);
		if (ft_strstr("-k", ssl->flags[i]))
			if (!(i = ft_check_k(i, ssl)))
				return (0);
		if (ft_strstr("-i", ssl->flags[i]))
			i = ft_check_i(flags, i, ssl);
		if (i == 0)
			break ;
		if (ft_strstr("-o", ssl->flags[i]))
			i = ft_check_o(flags, i, ssl);
		i++;
	}
	return (1);
}

static void	ft_collect_flags(t_ssl *ssl)
{
	int		i;

	i = 2;
	while (i < ssl->flags_count)
	{
		if (ft_strstr(ssl->flags[i], "-e"))
			ssl->e = 1;
		else if (ft_strstr(ssl->flags[i], "-d"))
			ssl->d = 1;
		else if (ft_strstr(ssl->flags[i], "-a"))
			ssl->a = 1;
		else if (ft_strstr(ssl->flags[i], "-k"))
			ssl->k = 1;
		else if (ft_strstr(ssl->flags[i], "-i"))
			ssl->i = 1;
		else if (ft_strstr(ssl->flags[i], "-o"))
			ssl->o = 1;
		else if (ft_strstr(ssl->flags[i], "-base64"))
			ssl->base64 = 1;
		i++;
	}
}

void	ft_check_des(t_ssl *ssl)
{
	if (!ft_valid_flag(ssl))
	{
		ft_print_options();
		return ;
	}
	ft_collect_flags(ssl);
	if (ssl->e == 1 || (ssl->e == 0 && ssl->d == 0))
		ft_des_encription(ssl);
	else if (ssl->d == 1 && ssl->a == 1)
		ft_base64_decode(ssl);
	else if (ssl->d == 1)
		ft_des_decription(ssl);
}