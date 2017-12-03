#include "lemin.h"

void	save_route(t_path *head, t_data *data)
{
	t_path	*lst;
	int		i;
	char	**path;

	lst = head;
	i = 0;
	while (lst && lst->data)
	{
		i++;
		lst = lst->next;
	}
	path = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	lst = head;
	i = 0;
	while (lst && lst->data)
	{
		path[i] = ft_strdup(lst->data);
		i++;
		lst = lst->next;
	}
	data->paths[data->path_index] = path;
	data->path_index += 1;
}

void	find_routes(t_room *room_lst, t_path *head, t_path *list, t_data *data)
{
	int		i;
	t_path	*next;

	i = 0;
	list->next = (t_path *)ft_memalloc(sizeof(t_path));
	room_lst->visited = 1;
	list->data = room_lst->name;
	next = list->next;
	if (room_lst->end == 1)
	{
		free(next);
		list->next = NULL;
		save_route(head, data);
	}
	while (room_lst->rooms[i] && room_lst->end == 0)
	{
		if (room_lst->rooms[i]->visited == 0)
			find_routes(room_lst->rooms[i], head, next, data);
		i++;
	}
	room_lst->visited = 0;
}

void	possible_routes(t_data *data)
{
	t_path	*path;

	path = (t_path *)ft_memalloc(sizeof(t_path));
	data->paths = (char ***)ft_memalloc(sizeof(char **) * 10000);
	find_routes(data->rooms[data->start], path, path, data);
	sort(data->paths);
	free(path);
}

void	sort(char ***arr)
{
	char	**ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_arrlen(arr[i]) > ft_arrlen(arr[j]))
			{
				ptr = arr[i];
				arr[i] = arr[j];
				arr[j] = ptr;
			}
			j++;
		}
		i++;
	}
}
