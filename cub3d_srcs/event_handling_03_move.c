/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling_03_move.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 00:45:36 by sachouam          #+#    #+#             */
/*   Updated: 2021/02/05 04:59:40 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"
#define SLOWING 3

void
	ft_move_forward(t_all *all)
{
	double ncx;
	double ncy;

	ncx = all->vect.posx + (cos(all->vect.dir) / SLOWING);
	ncy = all->vect.posy + (-sin(all->vect.dir) / SLOWING);
	if (all->data.map[(int)ncy][(int)ncx] != '1'
	&& all->data.map[(int)ncy][(int)ncx] != '2')
	{
		all->vect.posx = ncx;
		all->vect.posy = ncy;
	}
}

void
	ft_move_to_the_left(t_all *all)
{
	double ncx;
	double ncy;

	all->vect.dir += (PI + (PI / 2));
	ncx = all->vect.posx + (-cos(all->vect.dir) / SLOWING);
	ncy = all->vect.posy + (sin(all->vect.dir) / SLOWING);
	all->vect.dir -= (PI + (PI / 2));
	if (all->data.map[(int)ncy][(int)ncx] != '1'
	&& all->data.map[(int)ncy][(int)ncx] != '2')
	{
		all->vect.posx = ncx;
		all->vect.posy = ncy;
	}
}

void
	ft_move_backwards(t_all *all)
{
	double ncx;
	double ncy;

	all->vect.dir += PI;
	ncx = all->vect.posx + (cos(all->vect.dir) / SLOWING);
	ncy = all->vect.posy + (-sin(all->vect.dir) / SLOWING);
	all->vect.dir -= PI;
	if (all->data.map[(int)ncy][(int)ncx] != '1'
	&& all->data.map[(int)ncy][(int)ncx] != '2')
	{
		all->vect.posx = ncx;
		all->vect.posy = ncy;
	}
}

void
	ft_move_to_the_right(t_all *all)
{
	double ncx;
	double ncy;

	all->vect.dir += (PI / 2);
	ncx = all->vect.posx + (-cos(all->vect.dir) / SLOWING);
	ncy = all->vect.posy + (sin(all->vect.dir) / SLOWING);
	all->vect.dir -= (PI / 2);
	if (all->data.map[(int)ncy][(int)ncx] != '1'
	&& all->data.map[(int)ncy][(int)ncx] != '2')
	{
		all->vect.posx = ncx;
		all->vect.posy = ncy;
	}
}
