/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:32:30 by yechen            #+#    #+#             */
/*   Updated: 2017/06/21 15:12:48 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*t;

	t = malloc(size);
	{
		if (t == NULL)
			return (NULL);
		else
		{
			ft_bzero(t, size);
			return (t);
		}
	}
}
