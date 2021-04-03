/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:34:34 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/02 00:27:34 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"
#define ROTATE 3

int
	ft_good_bye(t_all *all)
{
	ft_abort_mission(all);
	exit(0);
	return (0);
}

void
	ft_move_camera_right(t_all *all)
{
	double i;
	double dirmod;
	double full;

	i = ft_degree_to_radian(ROTATE);
	full = ft_degree_to_radian(360);
	all->vect.dir -= i;
	dirmod = fmod(all->vect.dir, full);
	if (all->vect.dir < 0)
		all->vect.dir = full + dirmod;
}

void
	ft_move_camera_left(t_all *all)
{
	double i;
	double dirmod;
	double full;

	i = ft_degree_to_radian(ROTATE);
	full = ft_degree_to_radian(360);
	all->vect.dir += i;
	dirmod = fmod(all->vect.dir, full);
	if (all->vect.dir >= full)
		all->vect.dir = dirmod;
}
