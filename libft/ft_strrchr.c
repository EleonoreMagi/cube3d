/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:27:01 by esylva            #+#    #+#             */
/*   Updated: 2021/05/14 21:39:45 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;
	int		i;
	char	cc;

	cc = (char)c;
	t = (char *)s;
	i = ft_strlen(s);
	if (!t)
		return (NULL);
	if (!cc)
		return (t + i);
	while (i >= 0)
	{
		if (*(t + i) == cc)
			return (t + i);
		i--;
	}
	return (NULL);
}
