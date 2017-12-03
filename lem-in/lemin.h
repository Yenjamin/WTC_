#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"

typedef struct		s_ant
{
	char			*name;
	char			*room;
	int				end;
	unsigned int	index;
}					t_ant;

typedef struct		s_room
{
	char			*name;
	int				start;
	int				end;
	int				full;
	int				visited;
	struct s_room	*rooms[10000];
}					t_room;

typedef struct		s_data
{
	char			*file;
	int				antnum;
	int				start;
	int				end;
	char			**links;
	int				link1;
	int				link2;
	int				count;
	char			**split;
	t_room			*rooms[10000];
	int				room_index;
	t_ant			**ants;
	char			***paths;
	int				path_index;
	int				i;
	int				j;
	int				k;
	int				l;
	int				move;
}					t_data;

typedef struct		s_path
{
	char			*data;
	struct s_path	*next;
}					t_path;

void				get_info(t_data *data);
void				startend(t_data *data);
void				make_room(t_data *data);
void				make_link(t_data *data);
void				save_ant_info(t_data *data);
void				save_room_info(t_data *data);
void				possible_routes(t_data *data);
void				find_routes(t_room *room_lst, t_path *head, t_path *list, t_data *data);
void				save_route(t_path *head, t_data *data);
void				sort(char ***arr);
void				ft_error(void);
size_t				ft_arrlen(char **arr);
void				move_ants(t_data *data);
void				confirm_routes(t_data *data);
void				confirm_room(t_data *data);
void				movement(t_data *data, int *loop);
int					move_from(t_data *data);
void				free_ants(t_data *data);
void				free_paths(t_data *data);
void				free_rooms(t_data *data);
void				ft_frees(t_data *data);
void				ft_free2d(char **arr);

#endif
