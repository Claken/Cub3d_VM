/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:41:25 by sachouam          #+#    #+#             */
/*   Updated: 2019/10/24 15:25:07 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = ft_strlen(src);
	while (src[i] && dstsize && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = '\0';
	return (len);
}
