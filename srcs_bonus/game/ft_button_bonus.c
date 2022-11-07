/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:53:53 by esylva            #+#    #+#             */
/*   Updated: 2022/05/20 21:31:40 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_open_door(t_data *data)
{
	if (data->map->coord[(int)(floor)(data->player->pos_y
		- cos(data->player->look))][(int)(floor)
		(data->player->pos_x + sin(data->player->look))] == 'D')
			data->map->coord[(int)(floor)(data->player->pos_y
				- cos(data->player->look))][(int)(floor)
			(data->player->pos_x + sin(data->player->look))] = 'd';
	else if (data->map->coord[(int)(floor)(data->player->pos_y
		- cos(data->player->look))][(int)(floor)
			(data->player->pos_x + sin(data->player->look))] == 'd'
		|| ((int)(floor)(data->player->pos_y
		- cos(data->player->look)) == data->player->pos_y && (int)(floor)
			(data->player->pos_x + sin(data->player->look))
			== data->player->pos_x))
			data->map->coord[(int)(floor)(data->player->pos_y
				- cos(data->player->look))][(int)(floor)
			(data->player->pos_x + sin(data->player->look))] = 'D';
	ft_paint(data);
}
