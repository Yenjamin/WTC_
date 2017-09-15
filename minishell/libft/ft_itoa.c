/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:48:14 by yechen            #+#    #+#             */
/*   Updated: 2017/08/31 15:08:11 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nbr)
{
	int		tmp;
	int		len;
	int		neg;
	char	*str;

	tmp = nbr;
	len = 2;
	neg = (nbr < 0) ? 1 : 0;
	while (tmp /= 10)
		len++;
	len = len + neg;
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = ft_abs(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
