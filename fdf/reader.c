#include "fdf.h"

void    join_content(char *buff, char **content)
{
    char    *tmp;

    if (*content)
    {
        tmp = ft_strjoin(*content, buff);
        free(*content);
        *content = ft_strdup(tmp);
        free(tmp);
        tmp = NULL;
    }
    else
        *content = ft_strdup(buff);
}

char    *get_content(int fd)
{
    char    *content;
    char    *buff;
    int     c;

    c = 0;
    content = ft_strnew(BUFF_SIZE);
    buff = ft_strnew(BUFF_SIZE);
    while ((c = read(fd, buff, BUFF_SIZE)))
    {
        if (c == -1)
            error();
        buff[c] = '\0';
        join_content(buff, &content);
    }
    free(buff);
    buff = NULL;
    return (content);
}

void    reader(char *av, t_data *all)
{
    int     fd;
    char    *content;
    int     i;

    i = 0;
    fd = open(av, O_RDONLY);
    content = get_content(fd);
    close(fd);
    while (content[i])
    {
        if (content[i] == ' ' || content[i] == '-' || (content[i] >= 48 && content[i] <= 57) || content[i] == '\n' || content[i] == ',' || content[i] == 'x' || content[i] == 'F')
            i++;
        else
            error();
    }
    all->str = ft_strsplit(content, '\n');
	ft_strdel(&content);
}

void	max_size(t_data *all)
{
	int	y;
	int	x;
	int	tmp;

	y = 0;
	x = 0;
	while (all->str[y])
	{
		tmp = 0;
		tmp = ft_countword(all->str[y]);
		if (y == 0)
			x = tmp;
		if (x != tmp)
			error();
		y++;
	}
	if (y == 0 && x == 0)
        error();
    all->y_max = y;
    all->x_max = x;
}