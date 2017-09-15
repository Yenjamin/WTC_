/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:09:40 by yechen            #+#    #+#             */
/*   Updated: 2017/06/09 10:32:40 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	d;
	int		i;

	d = (char)c;
	i = ft_strlen(s);
	while (i >= 0 && s[i] != d)
		i--;
	if (s[i] == d)
		return ((char*)&s[i]);
	else
		return (NULL);
}
