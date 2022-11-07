/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:13:14 by esylva            #+#    #+#             */
/*   Updated: 2022/05/15 17:21:40 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_window	*ft_free_window(t_window *window)
{
	free(window);
	return (NULL);
}

t_map	*ft_free_map(t_map *map)
{
	if (map->coord)
	{
		free_2d_arr(map->coord);
		map->coord = NULL;
	}
	free(map);
	return (NULL);
}

t_player	*ft_free_player(t_player *player)
{
	free(player);
	return (NULL);
}

t_image	*ft_free_image(t_image *image)
{
	if (image->loc)
	{
		free(image->loc);
		image->loc = NULL;
	}
	free(image);
	return (NULL);
}

t_wall	*ft_free_wall(t_wall *wall)
{
	free(wall);
	return (NULL);
}
