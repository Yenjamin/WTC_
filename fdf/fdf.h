#ifndef FDF_H
# define FDF_H

# include "miniLibX/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct		s_bres
{
	float			dx;
	float			dy;
	int				i;
	float			f;
	//int				inc1;
	//int				inc2;
	float			incx;
	float			incy;
	float			x;
	float			y;
}					t_bres;

typedef struct      s_points
{
    double          x;
    double          y;
    double          z;
    double          xg;
    double          yg;
    double          zp;
    double          xp;
    double          yp;
}                   t_points;

typedef struct      s_data
{
    void            *mlx;
    void            *win;
    int             height;
    double          width;
    double          length;
    int             size;
    int             x_start;
    int             y_start;
    int             colour;
    char            **str;
    char            **str2;
    int             **points;
    t_points        **point;
    int             x_max;
    int             y_max;
}                   t_data;

void    error(void);
void    initialize(char *av, t_data *all);
void    join_content(char *buff, char **content);
char    *get_content(int fd);
void    reader(char *av, t_data *all);
int		ft_countword(char const *s);
void	max_size(t_data *all);
void    str_atoi(t_data *all);
void	ft_free2d(char **arr);
void    save_points(t_data *all);
void    isometric_points(t_data *all);
void	draw(t_data *all);
void	DDA(t_points *a, t_points *b, t_data *all);
//void	bresenham(t_points *a, t_points *b, t_data *all);
//void	case1(t_data *all, t_bres *p, int color);
//void	case2(t_data *all, t_bres *p, int color);

#endif