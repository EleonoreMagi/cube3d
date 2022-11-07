/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:14:53 by esylva            #+#    #+#             */
/*   Updated: 2021/05/06 21:22:57 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s;

	s = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (s + 1));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, s + 1);
	return (s2);
}
