/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:24:41 by esylva            #+#    #+#             */
/*   Updated: 2021/05/07 16:50:10 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*des;
	unsigned int	i;

	des = ft_strdup(s);
	if (!des)
		return (NULL);
	i = 0;
	while (des[i])
	{
		des[i] = (*f)(i, des[i]);
		i++;
	}
	return (des);
}
