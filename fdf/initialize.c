#include "fdf.h"

void    initialize(char *av, t_data *all)
{
    all->size = 25;
    all->x_start = 1000;
    all->y_start = 400;
    all->height = -10;
    all->colour = 0x0077FF;
    all->width = 0.25;
    all->length = 0.5;
    all->mlx = mlx_init();
    all->win = mlx_new_window(all->mlx, 1900, 1500, av);
}

int		ft_countword(char const *s)
{
	int	word;
	int	index;

	if (*s == '\0')
		return (0);
	index = 0;
	if (s[index] != ' ')
		word = 1;
	else
		word = 0;
	index++;
	while (s[index])
	{
		if (s[index - 1] == ' ' && s[index] != ' ')
			word++;
		index++;
	}
	return (word);
}

void    isometric_points(t_data *all)
{
    int     i;
    
    i = 0;
    while (all->point[i])
    {
        all->point[i]->xg = all->point[i]->x + (all->point[i]->x * all->size);
        all->point[i]->yg = all->point[i]->y + (all->point[i]->y * all->size);
        all->point[i]->zp = all->point[i]->z * all->height;
        all->point[i]->xp = (all->width * all->point[i]->xg) - (all->length * all->point[i]->yg);
        all->point[i]->yp = (all->point[i]->zp) + ((all->width / 2) * all->point[i]->xg) + ((all->length / 2) * all->point[i]->yg);
        all->point[i]->xp += all->x_start;
        all->point[i]->yp += all->y_start;
        i++;
    }
}