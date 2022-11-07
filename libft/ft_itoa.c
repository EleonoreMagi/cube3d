/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:57:30 by esylva            #+#    #+#             */
/*   Updated: 2021/05/15 11:53:27 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_razr(int n)
{
	int				len_razr;

	if (n <= 0)
		len_razr = 1;
	else
		len_razr = 0;
	while (n)
	{
		n /= 10;
		len_razr++;
	}
	return (len_razr);
}

static char	*ft_putint(unsigned int n, char *a, int l)
{
	if (!n)
		a[0] = '0';
	a[l--] = 0;
	while (n)
	{
		a[l] = (n % 10) + '0';
		n /= 10;
		l--;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	char			*a;
	unsigned int	m;
	int				l;

	l = ft_razr(n);
	a = (char *)malloc(sizeof(char) * (l + 1));
	if (!a)
		return (NULL);
	if (n < 0)
	{
		a[0] = '-';
		m = -n;
	}
	else
		m = n;
	a = ft_putint (m, a, l);
	return (a);
}
