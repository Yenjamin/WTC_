#include "lemin.h"

void	startend(t_data *data)
{
	if (ft_strcmp(data->file, "##start") == 0)
	{
		data->start = 1;
	}
	else if (ft_strcmp(data->file, "##end") == 0)
	{
		data->end = 1;
	}
}

void	make_room(t_data *data)
{
	if (ft_arrlen(data->split) > 3)
		ft_error();
	data->rooms[data->room_index] = (t_room *)ft_memalloc(sizeof(t_room));
	data->rooms[data->room_index]->name = ft_strdup(data->split[0]);
	if (data->start == 1)
	{
		data->rooms[data->room_index]->start = 1;
		data->start = 0;
	}
	else if (data->end == 1)
	{
		data->rooms[data->room_index]->end = 1;
		data->end = 0;
	}
	data->room_index++;
}

void	make_link(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->links = ft_strsplit(data->split[0], '-');
	data->link1 = 0;
	data->link2 = 0;
	if (ft_arrlen(data->links) > 2 || data->rooms[data->link1] == NULL)
		ft_error();
	while (ft_strcmp(data->rooms[data->link1]->name, data->links[0]) != 0)
		if (data->rooms[++data->link1] == NULL)
			ft_error();
	while (ft_strcmp(data->rooms[data->link2]->name, data->links[1]) != 0)
		if (data->rooms[++data->link2] == NULL)
			ft_error();
	while (data->rooms[data->link1]->rooms[i])
		i++;
	while (data->rooms[data->link2]->rooms[j])
		j++;
	data->rooms[data->link1]->rooms[i] = data->rooms[data->link2];
	data->rooms[data->link2]->rooms[j] = data->rooms[data->link1];
}

void	get_info(t_data *data)
{
	while (get_next_line(0, &data->file) != 0)
	{
		ft_putendl(data->file);
		if (data->count < 1 && ft_isdigit(data->file[0]))
		{
			data->antnum = ft_atoi(data->file);
			data->count++;
		}
		else
		{
			if (data->file[0] == '#')
				startend(data);
			else
			{
				data->split = ft_strsplit(data->file, ' ');
				if (data->split[0] == '\0')
					ft_error();
				else if (data->split[1] == NULL)
					make_link(data);
				else
					make_room(data);
			}
		}
		ft_frees(data);
	}
}
