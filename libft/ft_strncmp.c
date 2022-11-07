/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:26:14 by esylva            #+#    #+#             */
/*   Updated: 2021/05/15 10:32:34 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	a;

	a = 0;
	if (!n)
		return (0);
	while (((unsigned char)*(str1 + a) == (unsigned char)*(str2 + a))
		&& *(str1 + a) && *(str2 + a) && (a < n - 1))
		a++;
	return ((unsigned char)*(str1 + a) - (unsigned char)*(str2 + a));
}
