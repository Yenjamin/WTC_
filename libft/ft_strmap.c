/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:58:09 by yechen            #+#    #+#             */
/*   Updated: 2017/06/21 14:10:12 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*n;
	int		i;
	int		t;

	if (!s || !f)
		return (NULL);
	i = 0;
	t = ft_strlen(s);
	n = (char *)malloc(sizeof(char) * (t + 1));
	if (n == NULL)
		return (NULL);
	while (s[i])
	{
		n[i] = f(s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}
