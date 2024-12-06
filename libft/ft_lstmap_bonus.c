/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:39:00 by zchagar           #+#    #+#             */
/*   Updated: 2024/06/11 09:10:35 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstmap;
	t_list	*new;
	void	*lstcont;

	if (!f || !del || !lst)
		return (NULL);
	lstmap = NULL;
	while (lst)
	{
		lstcont = f(lst->content);
		new = ft_lstnew(lstcont);
		if (!new)
		{
			del(lstcont);
			ft_lstclear(&lstmap, del);
			return (NULL);
		}
		ft_lstadd_back(&lstmap, new);
		lst = lst -> next;
	}
	return (lstmap);
}
