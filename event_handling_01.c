/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:09:30 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/19 17:18:00 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		ft_abort_mission(t_all *all)
{
	int		i;
	t_texture	*tmp;

	i = 0;
	ft_free_all(all);
	while (i < NTXT)
	{
		tmp = &((t_texture *)(&all->text))[i++];
		mlx_destroy_image(all->disp.mlx_ptr, tmp->pict);
	}
	mlx_destroy_image(all->disp.mlx_ptr, all->disp.img);
	mlx_destroy_window(all->disp.mlx_ptr, all->disp.windo);
	exit(0);
	return (0);
}

static void	ft_move_camera_right(t_all *all)
{
	double i;
	double dirmod;
	double full;

	i = ft_degree_to_radian(1);
	full = ft_degree_to_radian(360);
	all->vect.dir -= i;
	dirmod = fmod(all->vect.dir, full);
	if (all->vect.dir < 0)
		all->vect.dir = full + dirmod;
	ft_recreate_image(all);
}

static void	ft_move_camera_left(t_all *all)
{
	double i;
	double dirmod;
	double full;

	i = ft_degree_to_radian(1);
	full = ft_degree_to_radian(360);
	all->vect.dir += i;
	dirmod = fmod(all->vect.dir, full);
	if (all->vect.dir >= full)
		all->vect.dir = dirmod;
	ft_recreate_image(all);
}

int			ft_key_management(int key, t_all *all)
{
	if (key == ESC)
		ft_abort_mission(all);
	else if (key == UP)
		ft_move_forward(all);
	else if (key == LEFT)
		ft_move_to_the_left(all);
	else if (key == DOWN)
		ft_move_backwards(all);
	else if (key == RIGHT)
		ft_move_to_the_right(all);
	else if (key == RARROW)
		ft_move_camera_right(all);
	else if (key == LARROW)
		ft_move_camera_left(all);
	return (0);
}
