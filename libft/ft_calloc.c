/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:33:35 by esylva            #+#    #+#             */
/*   Updated: 2021/05/03 15:14:09 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*a;

	i = 0;
	a = (char *)malloc(count * size);
	if (!a)
		return (NULL);
	while (i < count * size)
	{			
		*(a + i) = 0;
		i++;
	}
	a = (void *)a;
	return (a);
}
