/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:39:13 by sachouam          #+#    #+#             */
/*   Updated: 2019/10/18 13:38:36 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *alloced;

	if (!(alloced = malloc(sizeof(char) * (size * count))))
		return (NULL);
	ft_bzero(alloced, (size * count));
	return ((void *)alloced);
}
