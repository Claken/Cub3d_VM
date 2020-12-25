/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:28:55 by sachouam          #+#    #+#             */
/*   Updated: 2020/12/25 15:07:32 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void
	ft_check_for_walls(t_all *all)
{
	double hyph;
	double hypv;

	hyph = ft_set_hyph(all);
	hypv = ft_set_hypv(all);
	while (!all->vect.hit)
	{
		if (hyph < hypv)
		{
			ft_if_hyph_is_inferior(all, &hyph);
		}
		else
		{
			ft_if_hypv_is_inferior(all, &hypv);
		}
	}
}

static void
	ft_distance_calculation(t_all *all)
{
	if (!all->vect.side)
	{
		if (all->vect.raycol == PI / 2)
		{
			all->vect.distwall = fabs(((all->vect.posy -
			all->vect.fhy) / sin(all->vect.raycol)));
		}
		else
		{
			all->vect.distwall = fabs(((all->vect.posx -
			all->vect.fhx) / cos(all->vect.raycol)));
		}
	}
	else
	{
		if (all->vect.raycol == PI * 2)
		{
			all->vect.distwall = fabs(((all->vect.posx -
			all->vect.fvx) / cos(all->vect.raycol)));
		}
		else
		{
			all->vect.distwall = fabs(((all->vect.posy -
			all->vect.fvy) / sin(all->vect.raycol)));
		}
	}
}

static void
	ft_distance_with_no_fisheye(t_all *all)
{
	double beta;

	beta = fabs(all->vect.dir - all->vect.raycol);
	all->vect.nofisheye = all->vect.distwall * cos(beta);
}

static void
	ft_drawing_column(t_all *all, int i)
{
	int j;

	all->disp.colhei = (CASE / all->vect.nofisheye)
	* all->vect.distscreen;
	all->disp.pixbeg = -all->disp.colhei / 2 + all->data.reshei / 2;
	if (all->disp.pixbeg < 0)
		all->disp.pixbeg = -1;
	all->disp.pixend = all->disp.colhei / 2 + all->data.reshei / 2;
	if (all->disp.pixend >= (int)all->data.reshei)
		all->disp.pixend = all->data.reshei - 1;
	all->disp.color = ft_get_color(220, 220, 220);
	if (all->vect.side > 0)
		all->disp.color /= 2;
	j = all->disp.pixbeg;
	while (j++ < all->disp.pixend)
		ft_draw_pixel(all, j, i);
}

void
	ft_raycasting(t_all *all)
{
	int i;

	i = -1;
	all->vect.modxl = fmod(all->vect.posx, 1);
	all->vect.modyu = fmod(all->vect.posy, 1);
	all->vect.raycol = all->vect.dir + (all->vect.fov / 2);
	while (++i < (int)all->data.reswid)
	{
		ft_check_raycol_value(all);
		ft_re_set_variables(all);
		ft_check_raycol_dir(all);
		ft_check_for_walls(all);
		ft_distance_calculation(all);
		ft_distance_with_no_fisheye(all);
		ft_drawing_column(all, i);
		all->vect.raycol -= all->vect.apr;
	}
}
