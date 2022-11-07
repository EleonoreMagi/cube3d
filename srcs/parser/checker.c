/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:42:12 by  esylva           #+#    #+#             */
/*   Updated: 2022/03/29 10:38:52 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_name_check(char *carta)
{
	char	*point;
	int		fd;
	int		error;

	error = 0;
	point = ft_strrchr(carta, '.');
	fd = open(carta, O_RDONLY);
	if (fd == -1)
		error = errno;
	else if (!point || ft_strcmp(point, ".cub"))
		error = EINVAL;
	else if (read(fd, NULL, 0) == -1)
		error = errno;
	if (error)
	{
		printf("%s\n", strerror(error));
		fd = 0;
	}
	return (fd);
}

int	ft_check_map(t_data *data, t_list *map, int weght, int hight)
{
	if (ft_init_map(data, weght, hight))
		return (MAP_ERROR);
	if (ft_init_coord(data, map, weght, hight))
		return (MAP_ERROR);
	if (!ft_check_rect_str(data->map->coord[0]))
		return (MAP_ERROR);
	if (!ft_check_rect_str(data->map->coord[hight - 1]))
		return (MAP_ERROR);
	if (!ft_check_rect_col(data->map->coord, weght - 1, hight - 1))
		return (MAP_ERROR);
	if (!data->bonus)
	{
		if (ft_check_inside(data, weght, hight, NO_BONUS_STR))
			return (MAP_ERROR);
	}
	else
	{		
		if (ft_check_inside(data, weght, hight, BONUS_STR))
			return (MAP_ERROR);
	}
	if (data->player->look == -1)
		return (MAP_ERROR);
	return (0);
}

int	ft_check_inside(t_data *data, int weght, int hight, char *str)
{
	int		i;
	int		j;

	i = 1;
	while (i < hight)
	{
		j = 1;
		while (j < weght)
		{
			if (data->map->coord[i][j] != ' ' && data->map->coord[i][j] != '1')
			{
				if (!ft_strchr(str, data->map->coord[i][j]))
					return (MAP_ERROR);
				if (!ft_check_sym(i, j, data))
					return (MAP_ERROR);
			}
			if (data->map->coord[i][j] != 'L')
				data->map->loot++;
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_sym(int i, int j, t_data *data)
{
	if (data->map->coord[i - 1][j - 1] == ' '
		|| data->map->coord[i - 1][j] == ' '
		|| data->map->coord[i - 1][j + 1] == ' '
		|| data->map->coord[i][j - 1] == ' '
		|| data->map->coord[i][j + 1] == ' '
		|| data->map->coord[i + 1][j - 1] == ' '
		|| data->map->coord[i + 1][j] == ' '
		|| data->map->coord[i + 1][j + 1] == ' ')
		return (0);
	if ((data->map->coord[i][j] == 'N' || data->map->coord[i][j] == 'E'
		|| data->map->coord[i][j] == 'W' || data->map->coord[i][j] == 'S'))
	{
		if (data->player->look != -1)
			return (0);
		else
			ft_set_look(data, i, j);
	}
	if (data->map->coord[i][j] == 'D'
		&& ((data->map->coord[i - 1][j] != '1'
			&& data->map->coord[i + 1][j] != '1')
			&& (data->map->coord[i][j - 1] != '1'
				&& data->map->coord[i][j + 1] != '1')))
		return (0);
	return (1);
}

void	ft_set_look(t_data *data, int i, int j)
{
	data->player->pos_x = j + 0.5;
	data->player->pos_y = i + 0.5;
	if (data->map->coord[i][j] == 'N')
		data->player->look = 0;
	else if (data->map->coord[i][j] == 'W')
		data->player->look = 3 * PI / 2;
	else if (data->map->coord[i][j] == 'S')
		data->player->look = PI;
	else if (data->map->coord[i][j] == 'E')
		data->player->look = PI / 2;
	data->map->x = j;
	data->map->y = i;
	data->map->coord[i][j] = '0';
	return ;
}
