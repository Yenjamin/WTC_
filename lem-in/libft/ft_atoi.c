/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:11:23 by yechen            #+#    #+#             */
/*   Updated: 2017/08/15 16:03:30 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long	c;
	int				d;
	int				i;
	unsigned long	t;

	c = 0;
	i = 0;
	d = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		d = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		t = c;
		c = c * 10 + (str[i] - '0');
		i++;
		if (t > c)
			return (d == -1 ? 0 : -1);
	}
	c = c * d;
	return (c);
}
