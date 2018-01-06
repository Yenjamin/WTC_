#include "fdf.h"

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
}

void    str_atoi(t_data *all)
{
    int     x;
    int     y;

    if (!(all->points = (int **)malloc(sizeof(int *) * all->y_max)))
        error();
    y = 0;
    while (all->str[y])
    {
        if (!(all->str2 = ft_strsplit(all->str[y], ' ')))
            error();
        if (!(all->points[y] = (int *)malloc(sizeof(int) * all->x_max)))
            error();
        x = 0;
        while (all->str2[x])
        {
            all->points[y][x] = ft_atoi(all->str2[x]);
            x++;
        }
        ft_free2d(all->str2);
        y++;
    }
    ft_free2d(all->str);
}

void    save_points(t_data *all)
{
    int         x;
    int         y;
    int         i;

    if (!(all->point = (t_points **)malloc(sizeof(t_points) * all->x_max * all->y_max)))
        error();
    y = 0;
    i = 0;
    while (y < all->y_max)
    {
        x = 0;
        while (x < all->x_max)
        {
            if (!(all->point[i] = (t_points *)malloc(sizeof(t_points))))
                error();
            all->point[i]->y = y;
            all->point[i]->x = x;
            all->point[i]->z = all->points[y][x];
            i++;
            x++;
        }
        y++;
    }
}