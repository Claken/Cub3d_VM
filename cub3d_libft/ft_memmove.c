/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:06:11 by sachouam          #+#    #+#             */
/*   Updated: 2019/10/24 16:20:54 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	tmp[len];

	if (!dst && !src)
		return (NULL);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	return (dst);
}
