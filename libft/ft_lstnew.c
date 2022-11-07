/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:05:27 by esylva            #+#    #+#             */
/*   Updated: 2021/05/12 23:09:31 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*aa;

	aa = (t_list *)malloc(sizeof (*aa));
	if (!aa)
		return (NULL);
	aa->content = content;
	aa->next = NULL;
	return (aa);
}
