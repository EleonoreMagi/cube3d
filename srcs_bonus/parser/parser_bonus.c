/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:39:52 by esylva            #+#    #+#             */
/*   Updated: 2022/05/20 21:35:29 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

t_list	*ft_lstnew_m(char *content)
{
	t_list	*aa;

	aa = (t_list *)malloc(sizeof (*aa));
	if (!aa)
		return (NULL);
	aa->content = ft_strdup(content);
	aa->next = NULL;
	return (aa);
}

int	ft_parce_data(t_data *data, int fd)
{
	char	*line;
	int		not_the_end;
	t_list	*cub;

	line = NULL;
	cub = NULL;
	not_the_end = 1;
	while (not_the_end > 0)
	{
		not_the_end = get_next_line(fd, &line);
		ft_lstadd_back(&cub, ft_lstnew_m(line));
		free(line);
		line = NULL;
	}
	not_the_end = ft_config(&cub, data);
	ft_lstclear(&cub, free);
	if (not_the_end)
		return (MAP_ERROR);
	return (0);
}

int	ft_config(t_list **cub, t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *cub;
	while (i < 6 && tmp)
	{
		i += ft_separate_textures(tmp->content, data);
		if (i < 0)
			return (MAP_ERROR);
		tmp = tmp->next;
	}
	if (i != 6)
		return (MAP_ERROR);
	while (!ft_empty_line(tmp->content) && tmp)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (MAP_ERROR);
	}	
	if (ft_parse_map(tmp, data))
		return (MAP_ERROR);
	return (0);
}

int	ft_parse_map(t_list *map, t_data *data)
{
	t_list	*tmp;
	int		weght;
	int		hight;
	int		a;

	hight = 0;
	weght = 0;
	tmp = map;
	while (tmp)
	{
		a = ft_strlen(tmp->content);
		if (weght < a)
			weght = a;
		if (!a)
			break ;
		hight++;
		tmp = tmp->next;
	}
	if (ft_check_map(data, map, weght, hight))
		return (MAP_ERROR);
	return (0);
}
