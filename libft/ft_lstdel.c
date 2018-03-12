/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:06:05 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/14 15:43:55 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*nextptr;

	ptr = (*alst);
	if (alst != NULL && del != NULL)
	{
		while (ptr != NULL)
		{
			nextptr = ptr->next;
			del(ptr->content, ptr->content_size);
			free(ptr);
			ptr = nextptr;
		}
	}
	(*alst) = NULL;
}
