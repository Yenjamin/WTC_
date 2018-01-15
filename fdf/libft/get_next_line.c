/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 13:47:12 by yechen            #+#    #+#             */
/*   Updated: 2018/01/15 13:35:33 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	readline(int fd, char **part)
{
	char	*b;
	char	*t;
	int		i;

	b = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_bzero(b, (BUFF_SIZE + 1));
	if (b == NULL)
		return (-1);
	i = read(fd, b, BUFF_SIZE);
	if (i > 0)
	{
		t = ft_strjoin(*part, b);
		if (!t)
			return (-1);
		free(*part);
		*part = t;
	}
	free(b);
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s;
	char		*p;
	int			i;

	if (!s && (s = ft_strnew(sizeof(*s))) == NULL)
		return (-1);
	p = ft_strchr(s, '\n');
	while (p == NULL)
	{
		if ((i = readline(fd, &s)) == 0)
		{
			if (ft_strlen(s) == 0)
				return (0);
			s = ft_strjoin(s, "\n");
		}
		if (i < 0)
			return (-1);
		else
			p = ft_strchr(s, '\n');
	}
	*line = ft_strsub(s, 0, ft_strlen(s) - ft_strlen(p));
	p = ft_strdup(p + 1);
	free(s);
	s = p;
	return (1);
}
