/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:44:45 by msemenov          #+#    #+#             */
/*   Updated: 2018/03/12 09:44:48 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"


int	ft_valid_command(const char *s)
{
	if (ft_strcmp(s, "base64") && ft_strcmp(s, "des") != 0)
		return (1);
	else if (ft_strcmp(s, "des") && ft_strcmp(s, "base64") != 0)
		return (1);
	else
		return (0);
}

// static int	ft_find_char(char *str, char c)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			return (i);
// 		i++;
// 	}
// 	return (0);
// }

// void	ft_print_options(void)
// {
// 	printf("%s\n", "Error");
// }

// int		ft_check_hex(char *str)
// {
// 	char	*hex;
// 	int		i;

// 	i = 0;
// 	hex = "0123456789ABCDEF";
// 	while (str[i])
// 	{
// 		if (!ft_find_char(hex, str[i++]))
// 			return (0);
// 	}
// 	return (1);
// }

// int		ft_valid_flag(t_ssl *ssl)
// {
// 	int		i;
// 	char	*flags;

// 	i = 2;
// 	//int n = 2;
// 	// while (n < ssl->flags_count)
// 	// 	printf("%s\n", ssl->flags[n++]);
// 	flags = "-e-d-a-k-i-o-base64";
// 	while (i < ssl->flags_count)
// 	{
// 		if (!ft_strstr(flags, ssl->flags[i]))
// 			return (0);
// 		//printf("%s\n", "test");
// 		if (ft_strstr("-k", ssl->flags[i]))
// 			if(!ft_check_hex(ssl->flags[++i]))
// 				return (0);
// 		i++;
// 	}
// 	return (1);
// }

// void	ft_collect_flags(t_ssl *ssl)
// {
// 	int		i;

// 	i = 2;
// 	while (i < ssl->flags_count)
// 	{
// 		if (ft_strstr(ssl->flags[i], "-e"))
// 			ssl->e = 1;
// 		else if (ft_strstr(ssl->flags[i], "-d"))
// 			ssl->d = 1;
// 		else if (ft_strstr(ssl->flags[i], "-a"))
// 			ssl->a = 1;
// 		else if (ft_strstr(ssl->flags[i], "-k"))
// 			ssl->k = 1;
// 		else if (ft_strstr(ssl->flags[i], "-i"))
// 			ssl->i = 1;
// 		else if (ft_strstr(ssl->flags[i], "-o"))
// 			ssl->o = 1;
// 		else if (ft_strstr(ssl->flags[i], "-base64"))
// 			ssl->base64 = 1;
// 		else
// 			ssl->hex = ft_strdup(ssl->flags[i]);
// 		i++;
// 	}
// }

// void	ft_check_des(t_ssl *ssl)
// {
// 	if (!ft_valid_flag(ssl))
// 	{
// 		ft_print_options();
// 		return ;
// 	}
// 	ft_collect_flags(ssl);
// 	if (ssl->flags_count == 5)
// 	{
// 		if (ssl->e == 1 && ssl->k == 1)
// 			ft_des_encription2(ssl, ssl->hex);
// 		else if (ssl->d == 1 && ssl->k == 1)
// 			ft_des_decription2(ssl, ssl->hex);
// 		else if (ssl->a == 1 && ssl->k == 1)
// 			ft_des_encription3(ssl, ssl->hex);
// 	}
// 	// if (ssl->flags_count == 6)
// 	// {
// 	// 	if (ssl->a == 1 && ssl->k == 1 && ssl->d == 1)
// 	// 		ft_base64_decode2();
// 	// }
// }

int		main(int argc, char const **argv)
{
	t_ssl	*ssl;

	ssl = ft_memalloc(sizeof(t_ssl));
	if (argc == 1 )
	{
		printf("%s\n", "usage: ft_ssl command [command opts] [command args]");
		return(0);
	}
	if (ft_valid_command(argv[1]))
		printf("Error %s is an invalid command.\n\nStandart commands:\n\n\
Message Digest commands:\n\nCipher commands:\n\
base64\ndes\ndes-ecb\ndec-cbc\n" , argv[1]);
	ssl->flags =(char**)malloc(sizeof(char*) * argc + 1);
	ssl->flags[argc] = NULL;
	ssl->flags_count = argc;
	while (--argc)
		ssl->flags[argc] = ft_strdup(argv[argc]);
	if (!ft_strcmp(argv[1], "des"))
		ft_check_des(ssl);
	if (!ft_strcmp(argv[1], "base64"))
		ft_check_base64(ssl);
	// if (!ft_strcmp(argv[1], "base64") && !ft_strcmp(argv[2], "-d"))
	// 	ft_base64_decode(ssl);
	// if (!ft_strcmp(argv[1], "base64"))
	// 	ft_base64_encode(ssl);
		// ft_check_base64(ssl);
	// if (argc == 2)
	// {
	// 	if (!ft_strcmp(argv[1], "des"))
	// 		ft_des_encription(ssl);
	// 	if (!ft_strcmp(argv[1], "base64") && argc == 2)
	// 		ft_encode(ssl);
	// }
	// if (argc == 3)
	// {
	// 	if (!ft_strcmp(argv[2], "-e"))
	// 		ft_encode(ssl);
	// 	if (!ft_strcmp(argv[2], "-d"))
	// 		ft_decode(ssl);	
	// }
	// if (argc == 5)
	// {
	// 	if (!ft_strcmp(argv[1], "des") && !ft_strcmp(argv[2], "-d") && !ft_strcmp(argv[3], "-k"))
	// 		ft_des_decription2(ssl, argv[4]);
	// 	if (!ft_strcmp(argv[1], "des") && !ft_strcmp(argv[2], "-e") && !ft_strcmp(argv[3], "-k"))
	// 		ft_des_encription2(ssl, argv[4]);
	// }
	return (0);
}
