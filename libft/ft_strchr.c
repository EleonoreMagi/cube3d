/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:22:35 by esylva            #+#    #+#             */
/*   Updated: 2021/05/14 21:33:04 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*t;

	t = (char *)s;
	if (!t)
		return ("");
	while (*t)
	{
		if (*t == (char)c)
			return (t);
		t++;
	}
	if (*t == (char)c)
		return (t);
	return (NULL);
}
