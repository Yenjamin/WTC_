/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 13:47:12 by yechen            #+#    #+#             */
/*   Updated: 2017/09/04 15:25:05 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		fill_buf(const int fd, char **ptr)
{
	char	*buf;
	int		ret;
	char	*newstr;

	if ((buf = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret > 0)
	{
		newstr = ft_strjoin(*ptr, buf);
		free(*ptr);
		*ptr = newstr;
	}
	if (buf)
		free(buf);
	return (ret);
}

int		ft_new(char **buf, char **endl_ptr)
{
	if ((*endl_ptr = ft_strdup(*endl_ptr + 1)) == NULL)
		return (-1);
	free(*buf);
	*buf = *endl_ptr;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buf;
	char		*endl_ptr;
	int			ret;

	if (buf == NULL && (buf = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (-1);
	endl_ptr = ft_strchr(buf, '\n');
	while (endl_ptr == NULL)
	{
		ret = fill_buf(fd, &buf);
		if (ret == 0)
		{
			if ((endl_ptr = ft_strchr(buf, '\0')) == buf)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			endl_ptr = ft_strchr(buf, '\n');
	}
	if ((*line = ft_strsub(buf, 0, (endl_ptr - buf))) == NULL)
		return (-1);
	return (ft_new(&buf, &endl_ptr));
}