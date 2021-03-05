/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:23:45 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/02 19:04:26 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*current;
	t_list	*current2;

	if (!lst || !(newlist = ft_lstnew((*f)(lst->content))) || !f || !del)
		return (NULL);
	current = lst->next;
	while (current)
	{
		if (!(current2 = ft_lstnew((*f)(current->content))))
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, current2);
		current = current->next;
	}
	return (newlist);
}
