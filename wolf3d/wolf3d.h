/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:12:06 by yechen            #+#    #+#             */
/*   Updated: 2018/01/15 13:17:54 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "miniLibX/mlx.h"
# include "libft/libft.h"
# include <math.h>

# define WS 64

typedef struct		s_thing
{
	int				x;
	int				y;
	int				x2;
	int				y2;
	struct s_thing	*next;
}					t_thing;

typedef struct		s_data
{
	int				x;
	int				y;
	t_thing			*thing;
}					t_data;

void	error(char *str);
void    reader(char *av, t_data *all);

#endif
