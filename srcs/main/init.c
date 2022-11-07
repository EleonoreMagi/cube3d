/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:45:19 by esylva            #+#    #+#             */
/*   Updated: 2022/05/15 17:10:52 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_data	*ft_data_init(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->window = NULL;
	data->map = NULL;
	data->player = NULL;
	data->ground = NULL;
	data->cloud = NULL;
	data->north = NULL;
	data->east = NULL;
	data->south = NULL;
	data->west = NULL;
	data->door = NULL;
	data->mmap = NULL;
	data->wal = NULL;
	data->bonus = BONUS;
	if (ft_init_main_struct(data))
		return (NULL);
	return (data);
}

int	ft_init_main_struct(t_data *data)
{
	data->window = ft_init_window(data->window);
	if (!data->window)
		return (INIT_ERROR);
	data->player = ft_init_player(data->player);
	if (!data->player)
		return (INIT_ERROR);
	data->wal = ft_init_wall(data->wal);
	if (!data->wal)
		return (INIT_ERROR);
	return (0);
}

t_image	*ft_init_image(t_image *wall)
{
	wall = (t_image *)malloc(sizeof(t_image));
	if (!wall)
		return (NULL);
	wall->loc = NULL;
	wall->image = NULL;
	wall->addr = NULL;
	wall->line = 0;
	wall->bitpp = 0;
	wall->endian = 0;
	wall->trgb = 0;
	wall->size_x = 0;
	wall->size_y = 0;
	return (wall);
}

int	ft_init_map(t_data *data, int weght, int hight)
{
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
		return (MAP_ERROR);
	data->map->coord = NULL;
	data->map->exit = 0;
	data->map->loot = 0;
	data->map->x = 0;
	data->map->y = 0;
	data->map->size_x = weght;
	data->map->size_y = hight;
	data->map->coord = (char **)malloc(sizeof(char *) * (hight + 1));
	if (!data->map->coord)
	{
		free(data->map);
		data->map = NULL;
		return (MAP_ERROR);
	}
	data->map->coord[hight] = NULL;
	return (0);
}

t_window	*ft_init_window(t_window *window)
{
	window = (t_window *)malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	window->img = NULL;
	window->coord = NULL;
	window->bits_per_pixel = 32;
	window->line_length = 0;
	window->endian = 0;
	return (window);
}
