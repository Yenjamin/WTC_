/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:54:15 by yechen            #+#    #+#             */
/*   Updated: 2017/06/21 15:14:57 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*d;
	unsigned char	g;
	size_t			n;

	n = 0;
	g = (unsigned char)c;
	d = (char*)b;
	while (n < len)
	{
		d[n] = g;
		n++;
	}
	return (d);
}
