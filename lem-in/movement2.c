#include "lemin.h"

void	move_to(t_data *data, int *loop)
{
	data->rooms[data->k]->full += 1;
	data->ants[data->j]->room = data->rooms[data->k]->name;
	ft_putstr("L");
	ft_putstr(data->ants[data->j]->name);
	ft_putstr("-");
	ft_putstr(data->rooms[data->k]->name);
	ft_putstr(" ");
	data->move = 1;
	data->l = 0;
	*loop = 1;
}

int		move_from(t_data *data)
{
	if (ft_strcmp(data->paths[data->i][data->ants[data->j]->index - 1],
				data->rooms[data->l]->name) == 0)
	{
		data->rooms[data->l]->full -= 1;
		return (1);
	}
	return (0);
}

void	movement(t_data *data, int *loop)
{
	if (data->rooms[data->k]->full == 0 && data->rooms[data->k]->end == 0)
	{
		move_to(data, loop);
		while (data->rooms[data->l])
		{
			if (move_from(data) == 1)
				break ;
			data->l++;
		}
		data->ants[data->j]->index += 1;
	}
	else if (data->rooms[data->k]->end == 1)
	{
		data->ants[data->j]->end = 1;
		move_to(data, loop);
		while (data->rooms[data->l])
		{
			if (move_from(data) == 1)
				break ;
			data->l++;
		}
		data->ants[data->j]->index += 1;
	}
}
