#include "wolf3d.h"

void    initialize(char *av, t_data *all)
{
    all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, 1900, 1500, av);
}