#include "fdf.h"

void    error(void)
{
    ft_putendl("error");
    exit(0);
}

int     escape(int keycode, t_data *all)
{
	if (keycode == 53)
	{
		mlx_clear_window(all->mlx, all->win);
		free(all->points);
		free(all);
		exit(0);
	}
	return (0);
}

int     main(int ac, char **av)
{
    t_data  *all;

    if (ac != 2)
        error();
    if (!ft_strstr(av[1], ".fdf"))
        error();
    if (!(all = (t_data*)malloc(sizeof(t_data))))
        error();
    initialize(av[1], all);
    reader(av[1], all);
    max_size(all);
    str_atoi(all);
    save_points(all);
    isometric_points(all);
    draw(all);
    mlx_key_hook(all->win, escape, all);
    mlx_loop(all->mlx);
    return (0);
}