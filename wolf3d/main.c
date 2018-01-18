#include "wolf3d.h"

void	error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int     main(int ac, char **av)
{
    t_data  *all;

    if (ac != 2)
        error("incorrect number of file(s) entered");
    if (!(all = (t_data*)malloc(sizeof(t_data))))
        error("unable to malloc");
    initialize(av[1], all);
    reader(av[1], all);
    /*while (all->thing)
    {
        ft_putchar('(');
        ft_putnbr(all->thing->x);
        ft_putchar(':');
        ft_putnbr(all->thing->y);
        ft_putchar(')');
        ft_putchar(' ');
        ft_putchar('(');
        ft_putnbr(all->thing->x2);
        ft_putchar(':');
        ft_putnbr(all->thing->y2);
        ft_putchar(')');
        ft_putchar('\n');
        all->thing = all->thing->next;
    }*/
    all->px = 950;
    all->py = 350;
    mlx_pixel_put(all->mlx, all->win, all->px, all->py, 0x0099FF);
    mlx_key_hook(all->win, keyhook, all);
    mlx_loop(all->mlx);
}