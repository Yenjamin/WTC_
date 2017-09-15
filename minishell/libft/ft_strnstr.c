/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 10:23:44 by yechen            #+#    #+#             */
/*   Updated: 2017/06/09 11:53:41 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	i = 0;
	b = (char*)big;
	l = (char*)little;
	if (little[i] == '\0')
		return (b);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (b[i + j] == l[j] && (i + j) < len)
		{
			if (l[j + 1] == '\0')
				return (b + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
