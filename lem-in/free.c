#include "lemin.h"

void	ft_free2d(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_frees(t_data *data)
{
	if (data->file != NULL)
	{
		free(data->file);
		data->file = NULL;
	}
	/*if (data->links != NULL)
	{
		ft_free2d(data->links);
		data->links = NULL;
	}*/
	if (data->split != NULL)
	{
		ft_free2d(data->split);
		data->split = NULL;
	}
}

void	free_ants(t_data *data)
{
	int		i;

	i = 0;
	while (data->ants[i])
	{
		free(data->ants[i]->name);
		free(data->ants[i]);
		i++;
	}
	free(data->ants);
}

void	free_paths(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->paths[i])
	{
		j = 0;
		while (data->paths[i][j])
		{
			free(data->paths[i][j]);
			j++;
		}
		free(data->paths[i]);
		i++;
	}
	free(data->paths);
}

void	free_rooms(t_data *data)
{
	int		i;

	i = 0;
	while (data->rooms[i])
	{
		free(data->rooms[i]->name);
		free(data->rooms[i]);
		i++;
    }
}
