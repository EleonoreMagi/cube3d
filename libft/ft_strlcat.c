/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:45:01 by esylva            #+#    #+#             */
/*   Updated: 2021/05/14 22:48:43 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(dst + i) && i < size)
		i++;
	while (j + i < size - 1 && *(src + j) && size > 0)
	{
		*(dst + j + i) = *(src + j);
		j++;
	}
	if (i < size)
		*(dst + j + i) = 0;
	return (i + ft_strlen(src));
}
