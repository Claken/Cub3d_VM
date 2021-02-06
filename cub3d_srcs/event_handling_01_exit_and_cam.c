/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling_01_exit_and_cam.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:09:30 by sachouam          #+#    #+#             */
/*   Updated: 2021/02/05 22:19:55 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"
#define ROTATE 2

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