#include "lemin.h"

void    ft_error(void)
{
    ft_putendl("Error");
    exit(-1);
}

int     ft_checkcomments(char *str)
{
    if (ft_strlen(str) > 0 && str[0] == '#')
        return (1);
    return (0);
}

/*int	    ft_arrlen(char **arr)
{
	int	    i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_free2d(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}*/