#include "fdf.h"

void	case1(t_data *all, t_bres *p, int color)
{
	mlx_pixel_put(all->mlx, all->win, p->x, p->y, color);
	p->f = 2 * p->dy - p->dx;
	p->inc1 = 2 * (p->dy - p->dx);
	p->inc2 = 2 * p->dy;
	p->i = 0;
	while (p->i < p->dx)
	{
		if (p->f >= 0)
		{
			p->y += p->incy;
			p->f += p->inc1;
		}
		else
			p->f += p->inc2;
		p->x += p->incx;
		mlx_pixel_put(all->mlx, all->win, p->x, p->y, color);
		p->i++;
	}
}

void	case2(t_data *all, t_bres *p, int color)
{
	mlx_pixel_put(all->mlx, all->win, p->x, p->y, color);
	p->f = 2 * p->dx - p->dy;
	p->inc1 = 2 * (p->dx - p->dy);
	p->inc2 = 2 * p->dx;
	p->i = 0;
	while (p->i < p->dy)
	{
		if (p->f >= 0)
		{
			p->x += p->incx;
			p->f += p->inc1;
		}
		else
			p->f += p->inc2;
		p->y += p->incy;
		mlx_pixel_put(all->mlx, all->win, p->x, p->y, color);
		p->i++;
	}
}

void	bresenham(t_points *a, t_points *b, t_data *all)
{
	t_bres *p;

	if (!(p = (t_bres*)malloc(sizeof(t_bres))))
		error();
	p->dx = ft_abs(b->xp - a->xp);
	p->dy = ft_abs(b->yp - a->yp);
	p->incx = (b->xp < a->xp) ? -1 : 1;
	p->incy = (b->yp < a->yp) ? -1 : 1;
	p->x = a->xp;
    p->y = a->yp;
	if (p->dx > p->dy)
		case1(all, p, all->colour);
	else
		case2(all, p, all->colour);
}

void	draw(t_data *all)
{
	int i;

	i = 0;
	while (all->point[i])
	{
		if ((i + 1) % all->x_max != 0)
			bresenham(all->point[i], all->point[i + 1], all);
		if (i < ((all->x_max * all->y_max) - all->x_max))
			bresenham(all->point[i], all->point[i + all->x_max], all);
		i++;
	}
}
