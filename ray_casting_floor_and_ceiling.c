/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_floor_and_ceiling.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:19:53 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/10 18:19:58 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

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

void	ft_draw_ceil_and_floor(t_all *all)
{
	int l;
	int t;

	t = -1;
	while (++t < (int)all->data.reshei)
	{
		l = -1;
		while (++l < (int)all->data.reswid)
		{
			if (t < (int)all->data.reshei / 2)
			{
				all->disp.color = ft_get_color(all->data.ceil1,
				all->data.ceil2, all->data.ceil3);
				ft_draw_pixel(all, t, l);
			}
			else
			{
				all->disp.color = ft_get_color(all->data.floor1,
				all->data.floor2, all->data.floor3);
				ft_draw_pixel(all, t, l);
			}
		}
	}
}
