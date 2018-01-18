#include "wolf3d.h"

int		keyhook(int keycode, t_data *all)
{
    ft_putnbr(keycode);
    ft_putchar('\n');
	if (keycode == 53)
	{
		mlx_clear_window(all->mlx, all->win);
		free(all);
		exit(0);
    }
    if (keycode == 126)
        all->py -= cos(POV * M_PI / 180) * 5;
    //up
    if (keycode == 125)
        all->py += cos(POV * M_PI / 180) * 5;
    //down
    if (keycode == 123)
        all->px -= sin(POV * M_PI / 180) * 5;
    //left
    if (keycode == 124)
        all->px += sin(POV * M_PI / 180) * 5;
    //right
    mlx_pixel_put(all->mlx, all->win, all->px, all->py, 0x0099FF);
	return (0);
}
