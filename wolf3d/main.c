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
    reader(av[1], all);
    while (all->thing)
    {
        ft_putnbr(all->thing->x);
        ft_putchar('\n');
        ft_putnbr(all->thing->y);
        ft_putchar('\n');
        ft_putnbr(all->thing->x2);
        ft_putchar('\n');
        ft_putnbr(all->thing->y2);
        ft_putchar('\n');
        all->thing = all->thing->next;
    }
}