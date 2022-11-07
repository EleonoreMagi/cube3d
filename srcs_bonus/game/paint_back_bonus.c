/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_back_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:54:05 by esylva            #+#    #+#             */
/*   Updated: 2022/05/20 21:32:21 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->window->addr + (y * data->window->line_length
			+ x * (data->window->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_back(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < W_PANEL)
	{
		while (j < H_PANEL / 2)
		{
			my_mlx_pixel_put(data, i, j, data->cloud->trgb);
			j++;
		}
		while (j < H_PANEL)
		{
			my_mlx_pixel_put(data, i, j, data->ground->trgb);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_back_bonus(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < W_PANEL)
	{
		while (j < H_PANEL / 2)
		{
			my_mlx_pixel_put(data, i, j, 0x0000FF);
			j++;
		}
		while (j < H_PANEL)
		{
			my_mlx_pixel_put(data, i, j, 0x777700);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_draw_2d_obj(t_data *data, int x, int y, int color)
{
	int	a;
	int	b;
	int	size;

	size = SCALE;
	a = 0;
	while (a < size)
	{
		b = 0;
		while (b < size)
		{
			my_mlx_pixel_put(data, x + a, y + b, color);
			b++;
		}
		a++;
	}
}

void	ft_put_minimap(t_data *data, int x, int y)
{
	int	beg_x;
	int	beg_y;

	beg_x = W_MAP / 2 - (data->map->size_x / 2) * SCALE;
	beg_y = W_MAP / 2 - (data->map->size_y / 2) * SCALE;
	while (y < data->map->size_y)
	{
		x = 0;
		while (x < data->map->size_x)
		{
			if (data->map->coord[y][x] == '1')
				ft_draw_2d_obj(data, beg_x + x * SCALE, beg_y + y
					* SCALE, 65535);
			else if (x == (int)data->player->pos_x && y
				== (int)data->player->pos_y)
				ft_draw_2d_obj(data, beg_x + (data->player->pos_x) * SCALE,
					beg_y + (data->player->pos_y) * SCALE, 0xff0000);
			else if (data->map->coord[y][x] == 'D'
			|| data->map->coord[y][x] == 'd')
				ft_draw_2d_obj(data, beg_x + x * SCALE, beg_y
					+ y * SCALE, 0xf6ff00);
			x++;
		}
		y++;
	}
}
