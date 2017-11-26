/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:09:19 by yechen            #+#    #+#             */
/*   Updated: 2017/06/09 10:32:18 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;
	int		i;

	d = (char)c;
	i = 0;
	while (s[i] && s[i] != d)
		i++;
	if (s[i] == d)
		return ((char*)&s[i]);
	else
		return (NULL);
}
