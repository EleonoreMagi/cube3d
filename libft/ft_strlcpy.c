/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:55:10 by esylva            #+#    #+#             */
/*   Updated: 2021/05/14 22:29:53 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	if (size)
	{
		i = 0;
		while (i < size - 1 && *(src + i))
		{		
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = 0;
	}
	return (ft_strlen(src));
}
