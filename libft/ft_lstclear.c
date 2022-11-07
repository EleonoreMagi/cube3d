/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:57:48 by esylva            #+#    #+#             */
/*   Updated: 2021/05/12 22:58:00 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new_adr;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		new_adr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = new_adr;
	}
}
