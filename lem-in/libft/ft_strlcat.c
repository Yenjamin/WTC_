/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:20:57 by yechen            #+#    #+#             */
/*   Updated: 2017/06/21 13:40:08 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	t;
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	t = 0;
	if (size < i)
		return (j + size);
	t = i;
	while ((t + 1) < size && src)
	{
		dst[t] = *src;
		t++;
		src++;
	}
	dst[t] = '\0';
	return (i + j);
}
