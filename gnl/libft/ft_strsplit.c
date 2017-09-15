/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 13:08:44 by yechen            #+#    #+#             */
/*   Updated: 2017/07/20 10:24:24 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordnbr(char const *s, char c)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		if (s[i])
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

static size_t	wordlen(char const *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**t;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	t = (char **)ft_memalloc(sizeof(char *) * wordnbr(s, c) + 1);
	if (t == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			t[j] = ft_strsub(s, i, wordlen(&s[i], c));
			j++;
			i += wordlen(&s[i], c);
		}
		while (s[i] && s[i] == c)
			i++;
	}
	t[j] = NULL;
	return (t);
}
