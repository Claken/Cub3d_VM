/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:19:26 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/21 18:52:02 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

void
	ft_distance_calculation(t_all *all)
{
	if (all->vect.side == 1 || all->vect.side == 3)
	{
		//if ((float)all->vect.raycol == (float)(PI / 2))
		//	all->vect.distwall = fabs(((all->vect.posy -
		//	all->vect.fhy) / sin(all->vect.raycol)));
		//else
		all->vect.distwall = fabs(((all->vect.posx -
		all->vect.fhx) / cos(all->vect.raycol)));
	}
	else if (all->vect.side == 2 || all->vect.side == 4)
	{
		//if ((float)all->vect.raycol == (float)(PI * 2))
		//	all->vect.distwall = fabs(((all->vect.posx -
		//	all->vect.fvx) / cos(all->vect.raycol)));
		//else
		all->vect.distwall = fabs(((all->vect.posy -
		all->vect.fvy) / sin(all->vect.raycol)));
	}
}

void
	ft_distance_with_no_fisheye(t_all *all)
{
	double beta;

	beta = fabs(all->vect.dir - all->vect.raycol);
	all->vect.nofisheye = all->vect.distwall * cos(beta);
}
