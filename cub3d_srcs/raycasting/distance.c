/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:19:26 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/16 19:37:22 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

static void
	ft_dist_for_north_and_south(t_all *all, int dir)
{
	if (dir == 6 || dir == 8)
	{
		all->calcul.distwall = fabs(((all->vect.posy -
		all->vect.fhy) / sin(all->angle.raycol)));
		if (dir == 6)
			all->calcul.distwall -= 1;
	}
	else
	{
		all->calcul.distwall = fabs(((all->vect.posx -
		all->vect.fhx) / cos(all->angle.raycol)));
	}
}

static void
	ft_dist_for_east_and_west(t_all *all, int dir)
{
	if (dir == 5 || dir == 7
	|| (dir == 1 && all->angle.raycol < all->angle.apr))
	{
		all->calcul.distwall = fabs(((all->vect.posx -
		all->vect.fvx) / cos(all->angle.raycol)));
		if (dir == 7)
			all->calcul.distwall -= 1;
	}
	else
	{
		all->calcul.distwall = fabs(((all->vect.posy -
		all->vect.fvy) / sin(all->angle.raycol)));
	}
}

void
	ft_distance_calculation(t_all *all)
{
	int dir;

	dir = ft_check_raycol_direction(all);
	if (all->vect.side == 1 || all->vect.side == 3)
	{
		ft_dist_for_north_and_south(all, dir);
	}
	else if (all->vect.side == 2 || all->vect.side == 4)
	{
		ft_dist_for_east_and_west(all, dir);
	}
}

void
	ft_distance_with_no_fisheye(t_all *all)
{
	double beta;

	beta = fabs(all->angle.dir - all->angle.raycol);
	all->calcul.nofisheye = all->calcul.distwall * cos(beta);
}
