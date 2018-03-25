/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void	ft_print_options(void)
{
	printf("%s\n", "Error");
}

static int		ft_valid_flag(t_ssl *ssl)
{
	int		i;
	char	*flags;

	i = 2;
	flags = "-e-d-i-o";
	while (i < ssl->flags_count)
	{
		if (!ft_strstr(flags, ssl->flags[i]))
			return (0);
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
		else if (ft_strstr(ssl->flags[i], "-i"))
			ssl->i = 1;
		else if (ft_strstr(ssl->flags[i], "-o"))
			ssl->o = 1;
		i++;
	}
}

void	ft_check_base64(t_ssl *ssl)
{
	if (!ft_valid_flag(ssl))
	{
		ft_print_options();
		return ;
	}
	ft_collect_flags(ssl);
	if (ssl->e == 1 || (ssl->e == 0 && ssl->d == 0))
		ft_base64_encode(ssl);
	else if (ssl->d == 1)
		ft_base64_decode(ssl);
}