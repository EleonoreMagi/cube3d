/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:28:32 by esylva            #+#    #+#             */
/*   Updated: 2022/05/20 21:28:33 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	ft_cycle_paint_walls(t_data *data, int i)
{
	if (data->wal->f_dor == 1 && (data->wal->dy < 0.02 || data->wal->dy > 0.98))
		my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wal->wall),
			((int*)data->door->addr)[data->wal->kx]);
	else if (data->wal->f_dor == 1)
		my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wal->wall),
			((int*)data->door->addr)[data->wal->ky]);
	else if ((data->wal->dy < 0.02 || data->wal->dy > 0.98)
		&& (data->wal->dx > 0.98 || data->wal->dx < 0.02))
	{
		return (0);
		my_mlx_pixel_put(data, i, H_PANEL / 2 - data->wal->wall, 0);
	}
	else if (data->wal->dy > 0.98)
		my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wal->wall),
			((int*)data->north->addr)[data->wal->kx]);
	else if (data->wal->dx > 0.98)
		my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wal->wall),
			((int*)data->south->addr)[data->wal->ky]);
	else if (data->wal->dy < 0.02)
		my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wal->wall),
			((int*)data->west->addr)[data->wal->kx]);
	else if (data->wal->dx < 0.02)
		my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wal->wall),
			((int*)data->east->addr)[data->wal->ky]);
	return (1);
}

int	ft_walls_paint(t_data *data, int i, double start)
{
	data->wal->wall = H_PANEL / 3 / (sqrt(powf(data->player->ray_x
					- data->player->pos_x, 2) + powf(data->player->ray_y
					- data->player->pos_y, 2)));
	data->wal->wall /= sin(data->player->look - start);
	data->wal->dx = modf(data->player->ray_x, &data->wal->tmp);
	data->wal->dy = modf(data->player->ray_y, &data->wal->tmp);
	data->wal->tmp = data->wal->wall;
	if (data->wal->wall > H_PANEL / 2)
		data->wal->wall = H_PANEL / 2;
	while (data->wal->wall > -data->wal->tmp
		&& data->wal->wall > -H_PANEL / 2)
	{
		data->wal->ky = ((int)((data->wal->tmp - data->wal->wall)
					/ data->wal->tmp * ONE_SIZE) / 2 + 0) * ONE_SIZE
			+ (int)(data->wal->dy * ONE_SIZE);
		data->wal->kx = ((int)((data->wal->tmp - data->wal->wall)
					/ data->wal->tmp * ONE_SIZE) / 2 + 0) * ONE_SIZE
			+ (int)(data->wal->dx * ONE_SIZE);
		if (!ft_cycle_paint_walls(data, i))
			return (0);
		data->wal->wall--;
	}
	data->wal->f_dor = 0;
	return (1);
}

void	ft_rais(t_data *data, double start)
{
	data->player->ray_x = data->player->pos_x;
	data->player->ray_y = data->player->pos_y;
	while (data->map->coord[(int)(data->player->ray_y)][(int)
		(data->player->ray_x)] != '1')
	{
		if (data->map->coord[(int)(data->player->ray_y)][(int)
			(data->player->ray_x)] == 'D')
		{
			data->wal->f_dor = 1;
			break ;
		}
		data->player->ray_x += cos(start) / ONE_SIZE / 4;
		data->player->ray_y += sin(start) / ONE_SIZE / 4;
	}
}

void	ft_cast_rays2(t_data *data, int i, double start, double end)
{
	i = W_PANEL / 2;
	start = data->player->look - (double)(PI / 2);
	end = data->player->look - (double)(PI / 2) - UGOL / 2;
	while (start >= end)
	{
		ft_rais(data, start);
		if (!ft_walls_paint(data, i, start))
		{
			i++;
			end -= UGOL / (W_PANEL);
		}
		i--;
		start -= UGOL / (W_PANEL);
	}
}

void	ft_cast_rays(t_data *data)
{
	int		i;
	double	start;
	double	end;

	data->wal->f_dor = 0;
	i = W_PANEL / 2;
	start = data->player->look - (double)(PI / 2);
	end = data->player->look - (double)(PI / 2) + UGOL / 2;
	while (start <= end)
	{
		ft_rais(data, start);
		if (!ft_walls_paint(data, i, start))
		{
			i--;
			end += UGOL / (W_PANEL);
		}
		i++;
		start += UGOL / (W_PANEL);
	}
	ft_cast_rays2(data, i, start, end);
}
