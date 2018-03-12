/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:59:12 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/14 15:40:41 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*ptr;
	t_list	*ret;

	ret = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new = f(lst);
		if (ret == NULL)
			ret = new;
		else
		{
			ptr = ret;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new;
		}
		lst = lst->next;
	}
	return (ret);
}
