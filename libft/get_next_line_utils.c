/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:37:52 by esylva            #+#    #+#             */
/*   Updated: 2021/10/10 16:38:57 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_m(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	n;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * (i));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n] != '\0')
	{
		str[i + n] = s2[n];
		n++;
	}
	str[i + n] = '\0';
	return (str);
}

int	ft_new_strjoin(char **line, char **ost)
{
	char	*tmp;
	char	*new;

	new = *ost;
	tmp = *line;
	*line = ft_strjoin(*line, new);
	if (!(*line))
	{
		free(tmp);
		free(new);
		*ost = NULL;
		return (-1);
	}
	free(tmp);
	if (!(new))
		return (-1);
	free(new);
	*ost = NULL;
	return (0);
}
