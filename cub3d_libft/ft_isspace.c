/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:41:27 by sachouam          #+#    #+#             */
/*   Updated: 2019/10/15 17:56:02 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	if ((unsigned char)c == '\t' || (unsigned char)c == '\n'
	|| (unsigned char)c == '\v' || (unsigned char)c == '\f'
	|| (unsigned char)c == '\r' || (unsigned char)c == ' ')
		return (1);
	return (0);
}
