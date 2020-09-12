/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:48:54 by sachouam          #+#    #+#             */
/*   Updated: 2019/10/22 15:10:59 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *svg;

	svg = NULL;
	if (*lst && del)
	{
		while (*lst)
		{
			svg = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = svg;
		}
	}
}
