/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_utils_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:32:31 by sachouam          #+#    #+#             */
/*   Updated: 2020/12/02 20:06:22 by sachouam         ###   ########.fr       */
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

int	ft_get_color(unsigned int r,
	unsigned int g, unsigned int b)
{
	int color;

	color = r << 16;
	color += g << 8;
	color += b;
	return (color);
}

void	ft_draw_pixel(t_all *all, int y, int x)
{
	all->disp.addr[y * all->data.reswid + x]
	= all->disp.color;
}

/*
double	ft_almost_zero(double raycol)
{
	double zero;
	double precision;

	zero = 0.0;
	precision = 0.0000001;
	if (raycol <= precision)
		return (zero);
	return (raycol);
}
*/
