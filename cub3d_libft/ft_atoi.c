/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:51:35 by sachouam          #+#    #+#             */
/*   Updated: 2019/10/24 14:56:05 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			i;
	long int	mn;
	long int	nb;

	i = 0;
	mn = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
	|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mn = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * mn);
}
