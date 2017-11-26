/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 15:51:23 by yechen            #+#    #+#             */
/*   Updated: 2017/07/28 15:56:23 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *t, size_t size)
{
	char	*n;

	if (!size && t)
	{
		if (!(n = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&t);
		return (n);
	}
	if (!(n = (char *)malloc(size)))
		return (NULL);
	if (t)
	{
		ft_memcpy(n, t, size);
		ft_memdel(&t);
	}
	return (n);
}
