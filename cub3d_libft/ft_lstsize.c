/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:33:28 by sachouam          #+#    #+#             */
/*   Updated: 2019/10/23 13:14:28 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 0;
	if (!(current = lst))
		return (0);
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
