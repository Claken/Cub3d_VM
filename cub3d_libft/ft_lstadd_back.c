/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:39:07 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/02 19:20:42 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	tmp = *alst;
	if (new)
	{
		if (!(*alst))
			*alst = ft_lstnew(new);
		else
		{
			while ((*alst)->next != NULL)
				*alst = (*alst)->next;
			(*alst)->next = ft_lstnew(new);
			*alst = tmp;
		}
	}
}
