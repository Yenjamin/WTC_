#include "lemin.h"
#include <stdio.h>

int     main(void)
{
    t_node  *rooms;
    int     ants;

    rooms = NULL;
    ants = ft_antnumber();
    ft_getinfo(&rooms);
    ft_putchar('\n');
    return (0);
}