#include "fdf.h"

void	DDA(t_points *a, t_points *b, t_data *all)
{
    t_bres *p;

    if (!(p = (t_bres*)malloc(sizeof(t_bres))))
        error();
    p->dx=b->xp - a->xp;
    p->dy=b->yp - a->yp;

    if(p->dx >= p->dy)
    p->f = p->dx;
    else
    p->f = p->dy;

    p->dx = p->dx / p->f;
    p->dy = p->dy / p->f;

    p->x = a->xp;
    p->y = a->yp;

    p->i = 1;
    while(p->i <= p->f)
    {
        mlx_pixel_put(all->mlx, all->win, p->x, p->y, all->colour);
        p->x = p->x + p->dx;
        p->y = p->y + p->dy;
        p->i++;
    }
}

void	draw(t_data *all)
{
    int     i;

    i = 0;
    while (all->point[i])
	{
		if ((i + 1) % all->x_max != 0)
			DDA(all->point[i], all->point[i + 1], all);
        if (i < ((all->x_max * all->y_max) - all->x_max))
            DDA(all->point[i], all->point[i + all->x_max], all);
            i++;
    }
}