/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:11:25 by yechen            #+#    #+#             */
/*   Updated: 2017/08/09 13:15:51 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*ret_start;

	if (lst == NULL)
		return (NULL);
	ret_start = f(lst);
	lst = lst->next;
	ret = ret_start;
	while (lst)
	{
		ret->next = f(lst);
		ret = ret->next;
		lst = lst->next;
	}
	ret = NULL;
	return (ret_start);
}
