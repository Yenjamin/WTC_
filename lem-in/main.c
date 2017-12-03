#include "lemin.h"

void	ft_error(void)
{
	ft_putendl("ERROR");
	exit(0);
}

size_t	ft_arrlen(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	save_room_info(t_data *data)
{
	data->start = 0;
	data->end = 0;
	while (data->rooms[data->start]->start == 0)
		if (data->rooms[++data->start] == NULL)
			ft_error();
	while (data->rooms[data->end]->end == 0)
		if (data->rooms[++data->end] == NULL)
			ft_error();
	data->rooms[data->start]->full = data->antnum;
}

void	save_ant_info(t_data *data)
{
	int		i;

	i = 0;
	data->ants = (t_ant **)malloc(sizeof(t_ant *) * data->antnum + 1);
	while (i < data->antnum)
	{
		data->ants[i] = (t_ant *)ft_memalloc(sizeof(t_ant));
		data->ants[i]->name = ft_itoa(i + 1);
		data->ants[i]->index = 1;
		data->ants[i]->room = data->rooms[data->start]->name;
		data->ants[i]->end = 0;
		i++;
	}
	i = 0;
	while (data->rooms[i])
	{
		data->rooms[i]->visited = 0;
		i++;
	}
}

int		main(void)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	get_info(&data);
	if (data.count == 0)
		ft_error();
	save_room_info(&data);
	save_ant_info(&data);
	possible_routes(&data);
	if (!data.paths[0])
		ft_error();
	ft_putchar('\n');
	while (data.rooms[data.end]->full < data.antnum)
	{
        data.j = 0;
        move_ants(&data);
        ft_putchar('\n');
	}
	free_rooms(&data);
	free_paths(&data);
	free_ants(&data);
	return (0);
}
