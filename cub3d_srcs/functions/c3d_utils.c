/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_utils_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:32:31 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/14 18:01:06 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

double
	ft_degree_to_radian(int degree)
{
	double radian;

	radian = (degree * PI) / 180.0f;
	return (radian);
}

int
	ft_radian_to_degree(double radian)
{
	int degree;

	degree = (radian * 180.0f) / PI;
	return (degree);
}

int
	ft_get_color(unsigned int r,
	unsigned int g, unsigned int b)
{
	int color;

	color = r << 16;
	color += g << 8;
	color += b;
	return (color);
}

void
	ft_draw_pixel(t_all *all, int y, int x)
{
	all->disp.addr[y * all->data.reswid + x] = all->disp.color;
}

void
	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
