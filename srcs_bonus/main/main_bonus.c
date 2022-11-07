/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:45:05 by esylva            #+#    #+#             */
/*   Updated: 2022/05/20 21:58:00 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	main(int argc, char **argv)
{
	int		i;
	int		ret;
	t_data	*data;

	data = NULL;
	if (argc == 1)
	{
		printf("%s\n",
			"Please, use cub3D with arguments 'map' in format *.cub");
		return (1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			ret = ft_cube(argv[i], data);
			if (ret)
				return (ret);
			i++;
		}
	}
	return (0);
}

int	ft_cube(char *carta, t_data *data)
{
	int	fd;

	fd = ft_name_check(carta);
	if (!fd)
		return (ARGUMENT_OPEN_ERROR);
	data = ft_data_init(data);
	if (!data)
		return (INIT_ERROR);
	if (ft_parce_data(data, fd))
		ft_exit (data, MAP_ERROR);
	ft_win_init(data);
	ft_game(data);
	ft_free_all(data);
	close (fd);
	return (0);
}

void	ft_game(t_data *data)
{
	mlx_mouse_hide(data->window->mlx_ptr, data->window->win_ptr);
	ft_paint(data);
	mlx_hook(data->window->win_ptr, 2, 1L << 0, key_kb_hook, data);
	if (BONUS)
		mlx_hook(data->window->win_ptr, 6, 1L << 6, mouse_move, data);
	mlx_hook(data->window->win_ptr, 17, 1L << 17, ft_exit, data);
	mlx_loop(data->window->mlx_ptr);
}

void	ft_free_all(t_data *data)
{
	if (data->wal)
		data->wal = ft_free_wall(data->wal);
	if (data->window)
		data->window = ft_free_window(data->window);
	if (data->map)
		data->map = ft_free_map(data->map);
	if (data->player)
		data->player = ft_free_player(data->player);
	if (data->ground)
		data->ground = ft_free_image(data->ground);
	if (data->cloud)
		data->cloud = ft_free_image(data->cloud);
	if (data->north)
		data->north = ft_free_image(data->north);
	if (data->east)
		data->east = ft_free_image(data->east);
	if (data->south)
		data->south = ft_free_image(data->south);
	if (data->west)
		data->west = ft_free_image(data->west);
	if (data->door)
		data->door = ft_free_image(data->door);
	free (data);
	data = NULL;
}

int	ft_exit(t_data *data, int keycode)
{
	ft_free_all(data);
	if (keycode == ARGUMENT_OPEN_ERROR)
		printf("Can't open the map file\n");
	if (keycode == INIT_ERROR)
		printf("Initialisation error. Not enough memory\n");
	if (keycode == MAP_ERROR)
	{
		printf("Map is invalid\n");
		keycode = 3;
	}
	exit(keycode);
}
