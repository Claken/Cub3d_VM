/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_utils_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:32:31 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/06 12:06:38 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

double	ft_degree_to_radian(int degree)
{
	double radian;

	radian = (degree * PI) / 180.0f;
	return (radian);
}

int	ft_radian_to_degree(double radian)
{
	int degree;

	degree = (radian * 180.0f) / PI;
	return (degree);
}

double	ft_pow(double nb, int power)
{
	double result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	while (power != 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}
