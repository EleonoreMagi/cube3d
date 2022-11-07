/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:54:33 by esylva            #+#    #+#             */
/*   Updated: 2021/05/06 12:59:56 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*des;
	int		n;
	int		m;
	int		i;

	n = ft_strlen(s1);
	m = ft_strlen(s2);
	i = -1;
	des = (char *)malloc(sizeof(char) * (m + n + 1));
	if (!des)
		return (NULL);
	while (i++ < n - 1)
		*(des + i) = *(s1 + i);
	i = -1;
	while (i++ < m - 1)
		*(des + n + i) = *(s2 + i);
	*(des + n + i) = 0;
	return (des);
}
