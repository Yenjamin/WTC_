/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:22:20 by yechen            #+#    #+#             */
/*   Updated: 2017/07/20 11:03:02 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	b;

	b = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar('-');
		b = (b * -1);
	}
	if (b >= 10)
	{
		ft_putnbr(b / 10);
		ft_putnbr(b % 10);
	}
	else
		ft_putchar(b + 48);
}
