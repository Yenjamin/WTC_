#include "lemin.h"
#include <stdio.h>

/*t_node  *ft_createroom(char *line, int type)
{
    t_node  *new;
    char    **arr;
    int     i;

    i = 0;
    new = (t_node *)malloc(sizeof(t_node));
    arr = ft_strsplit(line, ' ');
    if (ft_arrlen(arr) != 2)
    {
        free(line);
        ft_free2d(arr);
        ft_error();
    }
    new->name = ft_strdup(arr[0]);
    new->type = type;
    new->weight = -1;
    new->full = FALSE;
    new->links = ft_strnew(0);
    new->moved = FALSE;
    new->next = NULL;
    return (new);
}*/

/*void    ft_addstart(t_node **rooms, char *line, int type)
{
    t_node  *t;
    t_node  *s;

    if (*rooms)
    {
        t = *rooms;
        s = ft_createroom(line, type);
        s->next = t;
        *rooms = s;
    }
    else
        *rooms = ft_createroom(line, type);
}*/

/*void    ft_addon(t_node **rooms, char *line, int type)
{
    t_node  *s;

    s = *rooms;
    if (*rooms)
    {
        while (s->next)
            s = s->next;
        s->next = ft_createroom(line, type);
    }
    else
        *rooms = ft_createroom(line, type);
}*/