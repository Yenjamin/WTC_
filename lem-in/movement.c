#include "lemin.h"

void	confirm_room(t_data *data)
{
	int		loop;

	loop = 0;
	while (data->rooms[data->k])
	{
		if ((ft_strcmp(data->paths[data->i][data->ants[data->j]->index],
						data->rooms[data->k]->name) == 0) &&
				(ft_strcmp(data->paths[data->i][data->ants[data->j]->index - 1],
						data->ants[data->j]->room) == 0))
		{
			movement(data, &loop);
			if (loop == 1)
				break ;
		}
		data->k++;
	}
}

void	confirm_routes(t_data *data)
{
	while (data->paths[data->i])
	{
		data->k = 0;
		if (data->ants[data->j]->index < ft_arrlen(data->paths[data->i]))
		{
			confirm_room(data);
		}
		if (data->move == 1)
		{
			data->move = 0;
			break ;
		}
		data->i++;
	}
}

void	move_ants(t_data *data)
{
	while (data->ants[data->j])
	{
		data->i = 0;
		if (data->ants[data->j]->end != 1)
		{
			confirm_routes(data);
		}
		data->j++;
	}
}
