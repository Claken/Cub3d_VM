/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:39:07 by sachouam          #+#    #+#             */
/*   Updated: 2019/10/24 17:32:40 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	if (new)
	{
		if (!(*alst))
			*alst = new;
		else
		{
			while ((*alst)->next != NULL)
				*alst = (*alst)->next;
			(*alst)->next = new;
			*alst = temp;
		}
	}
}
