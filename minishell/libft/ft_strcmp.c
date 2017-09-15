/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:29:24 by yechen            #+#    #+#             */
/*   Updated: 2017/06/02 14:40:50 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;
	int				c;

	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	c = a[i] - b[i];
	return (c);
}
