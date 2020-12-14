/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling_02_keys.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:56:33 by sachouam          #+#    #+#             */
/*   Updated: 2020/12/14 18:54:44 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int
	ft_key_pressed(int key, t_all *all)
{
	if (key == ESC)
		ft_abort_mission(all);
	else if (key == UP)
		all->key.up = 1;
	else if (key == LEFT)
		all->key.left = 1;
	else if (key == DOWN)
		all->key.down = 1;
	else if (key == RIGHT)
		all->key.right = 1;
	else if (key == RARROW)
		all->key.r_arr = 1;
	else if (key == LARROW)
		all->key.l_arr = 1;
	return (0);
}

int
	ft_key_released(int key, t_all *all)
{
	if (key == UP)
		all->key.up = 0;
	else if (key == LEFT)
		all->key.left = 0;
	else if (key == DOWN)
		all->key.down = 0;
	else if (key == RIGHT)
		all->key.right = 0;
	else if (key == RARROW)
		all->key.r_arr = 0;
	else if (key == LARROW)
		all->key.l_arr = 0;
	return (0);
}

void
	ft_key_management(t_all *all)
{
	if (all->key.up)
		ft_move_forward(all);
	else if (all->key.left)
		ft_move_to_the_left(all);
	else if (all->key.down)
		ft_move_backwards(all);
	else if (all->key.right)
		ft_move_to_the_right(all);
	else if (all->key.r_arr)
		ft_move_camera_right(all);
	else if (all->key.l_arr)
		ft_move_camera_left(all);
}
