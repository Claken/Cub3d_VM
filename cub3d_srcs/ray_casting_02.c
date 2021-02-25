/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:29:15 by sachouam          #+#    #+#             */
/*   Updated: 2021/02/25 04:02:44 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

void
	ft_check_raycol_value(t_all *all)
{
	double full;

	full = ft_degree_to_radian(360);
	if (all->vect.raycol > full)
		all->vect.raycol = fmod(all->vect.raycol, full);
	else if (all->vect.raycol < 0)
		all->vect.raycol += full;
}

void
	ft_re_set_variables(t_all *all)
{
	all->vect.fhx = 0;
	all->vect.fhy = 0;
	all->vect.fvx = 0;
	all->vect.fvy = 0;
	all->vect.hx = 0;
	all->vect.hy = 0;
	all->vect.vx = 0;
	all->vect.vy = 0;
	all->vect.side = 0;
	all->disp.colhei = 0;
	all->vect.distwall = 0;
	all->disp.pixbeg = 0;
	all->disp.pixend = 0;
	all->vect.teta = all->vect.raycol;
}

void
	ft_raycol_dir(t_all *all)
{
	int direction;

	direction = ft_check_raycol_direction(all);
	if (direction == 1)
		ft_raycol_north_east(all);
	else if (direction == 2)
		ft_raycol_north_west(all);
	else if (direction == 3)
		ft_raycol_south_west(all);
	else if (direction == 4)
		ft_raycol_south_east(all);
	else
		ft_raycol_special_cases(all, direction);
}

void
	ft_if_hyph_is_inferior(t_all *all, double *hyph, int *hit)
{
	if (all->data.map[(int)all->vect.fhy][(int)all->vect.fhx] == '1')
	{
		if (all->vect.hy == -1)
			all->vect.side = 1;
		else if (all->vect.hy == 1)
			all->vect.side = 3;
		*hit = 1;
	}
	else
	{
		all->vect.fhx += all->vect.hx;
		all->vect.fhy += all->vect.hy;
		*hyph += CASE / sin(all->vect.teta);
	}
}

void
	ft_if_hypv_is_inferior(t_all *all, double *hypv, int *hit)
{
	if (all->data.map[(int)all->vect.fvy][(int)all->vect.fvx] == '1')
	{
		if (all->vect.vx == -1)
			all->vect.side = 4;
		else if (all->vect.vx == 1)
			all->vect.side = 2;
		*hit = 1;
	}
	else
	{
		all->vect.fvx += all->vect.vx;
		all->vect.fvy += all->vect.vy;
		*hypv += CASE / cos(all->vect.teta);
	}
}
