/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:40:15 by esylva            #+#    #+#             */
/*   Updated: 2022/05/20 21:35:09 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	ft_empty_line(char *str)
{
	if (!str)
		return (0);
	str += ft_numspases(str);
	if (*str)
		return (1);
	return (0);
}

void	ft_copy_str(char *dest, char *src, int lim)
{
	int	i;
	int	len;

	len = ft_strlen(src);
	i = 0;
	while (i < len)
	{		
		*(dest + i) = *(src + i);
			i++;
	}
	while (i < lim)
	{
		*(dest + i) = ' ';
		i++;
	}
	*(dest + i) = 0;
}

int	ft_check_rect_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '1')
			i++;
		else
			return (0);
	}
	return (i);
}

int	ft_check_rect_col(char **str, int w, int h)
{
	int	i;

	i = 0;
	while (i <= h)
	{
		if ((str[i][0] == ' ' || str[i][0] == '1' )
			&& (str[i][w] == ' ' || str[i][w] == '1' ))
			i++;
		else
			return (0);
	}
	return (i);
}

int	ft_init_coord(t_data *data, t_list *map, int weght, int hight)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = map;
	while (i < hight)
	{
		data->map->coord[i] = (char *)malloc(sizeof(char) * (weght + 1));
		if (!data->map->coord[i])
		{
			data->map->coord = free_2d_arr(data->map->coord);
			return (MAP_ERROR);
		}
		i++;
	}
	i = -1;
	while (++i < hight)
	{
		ft_copy_str(data->map->coord[i], tmp->content, weght);
		tmp = tmp->next;
	}
	return (0);
}
