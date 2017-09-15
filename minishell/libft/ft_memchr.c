/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:39:30 by yechen            #+#    #+#             */
/*   Updated: 2017/07/20 11:13:39 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	d;
	unsigned char	*t;
	size_t			i;

	d = (unsigned char)c;
	t = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (t[i] == d)
			return (&t[i]);
		i++;
	}
	return (NULL);
}
