/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:30:45 by yechen            #+#    #+#             */
/*   Updated: 2017/06/09 11:51:35 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int				i;
	int				j;
	char			*b;
	char			*l;

	i = 0;
	b = (char *)big;
	l = (char *)little;
	if (little[i] == '\0')
		return (b);
	while (big[i] != '\0')
	{
		j = 0;
		while (l[j] == b[i + j])
		{
			if (l[j + 1] == '\0')
				return (b + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
