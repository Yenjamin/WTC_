#ifndef _LEMIN_H_
# define _LEMIN_H_

#include "libft/includes/libft.h"

# define NEITHER 0
# define START 1
# define END 2
# define TRUE 1
# define FALSE 0
# define UNSET -1
# define f full
# define w weight

typedef struct      s_node
{
    char            *name;
    int             type;
    int             weight;
    int             full;
    char            *links;
    int             moved;
    struct s_node   *next;
}                   t_node;

void    ft_error(void);
int     ft_checkcomments(char *str);
int     ft_checkstart_end(char *str);
int	    ft_arrlen(char **arr);
void	ft_free2d(char **arr);
t_node  *ft_createroom(char *line, int type);
//void    ft_addstart(t_node **rooms, char *line, int type);
//void    ft_addon(t_node **rooms, char *line, int type);
//void    ft_nodes(t_node **rooms, char *line);
int     ft_antnumber(void);
int     ft_getinfo(t_node **rooms);

#endif