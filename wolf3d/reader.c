#include "wolf3d.h"

void    reader(char *av, t_data *all)
{
    int     fd;
    char    *line;
    t_thing *tmp;

    tmp = NULL;
    all->thing = NULL;
    fd = open(av, O_RDONLY);
    all->y = 0;
    while (get_next_line(fd, &line) > 0)
    {
        all->x = 0;
        while (line[all->x])
        {
            if (line[all->x] == '1')
            {
                if (all->thing == NULL && tmp == NULL)
                {
                    if (!(tmp = (t_thing*)malloc(sizeof(t_thing))))
                        error("unable to malloc");
                    tmp->x = all->x * WS;
                    tmp->y = all->y * WS;
                    tmp->x2 = tmp->x + WS;
                    tmp->y2 = tmp->y + WS;
                    all->thing = tmp;
                }
                else
                {
                    if (!(tmp->next = (t_thing*)malloc(sizeof(t_thing))))
                        error("unable to malloc");
                    tmp = tmp->next;
                    tmp->x = all->x * WS;
                    tmp->y = all->y * WS;
                    tmp->x2 = tmp->x + WS;
                    tmp->y2 = tmp->y + WS;
                }
            }
            all->x++;
        }
        all->y++;
    }
    close(fd);
}