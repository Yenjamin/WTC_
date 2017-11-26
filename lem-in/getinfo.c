#include "lemin.h"

/*void    ft_nodes(t_node **rooms, char *line)
{
    if (ft_strcmp(line, "##START") == 0)
    {
        get_next_line(0, &line);
        ft_addstart(rooms, line, START);
        ft_putendl(line);
        free(line);
    }
    else if (ft_strcmp(line, "##end") == 0)
    {
        get_next_line(0, &line);
        ft_addon(rooms, line, END);
        ft_putendl(line);
        free(line);
    }
    else
        ft_addon(rooms, line, NEITHER);
}*/

/*void    ft_links(t_node **rooms, char *line)
{
    char    **arr;

    arr = ft_strsplit(line, '-');
    if (ft_arrlen(arr) != 2)
    {
        free(line);
        ft_free2d(arr);
        ft_error();
    }

}*/

int     ft_antnumber(void)
{
    char    *line;
    int     ants;

    line = NULL;
    if (get_next_line(0, &line) < 1)
        ft_error();
    while (ft_checkcomments(line))
    {
        ft_putendl(line);
        free(line);
        line = NULL;
        get_next_line(0, &line);
    }
    ft_putendl(line);
    if (ft_atoi(line) < 1)
    {
        free(line);
        ft_error();
    }
    ants = ft_atoi(line);
    free(line);
    return (ants);
}

int     ft_getinfo(t_node **rooms)
{
    char    *line;
    int     r;

    while ((r = get_next_line(0, &line)) > 0)
    {
        ft_putendl(line);
        while (ft_checkcomments(line))
        {
            free(line);
            r = get_next_line(0, &line);
            ft_putendl(line);
        }
        /*if (!ft_strchr(line, '-'))
            ft_nodes(rooms, line);
        else
            ft_links(rooms, line);*/
        free(line);
    }
    if (r == -1)
    {
        free(line);
        ft_error();
    }
    return (1);
}