/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:07:12 by sachouam          #+#    #+#             */
/*   Updated: 2019/10/28 17:37:43 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		if (!(substr = ft_calloc(1, 1)))
			return (NULL);
		return (substr);
	}
	if (!(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(substr, s + start, (len + 1));
	return (substr);
}
