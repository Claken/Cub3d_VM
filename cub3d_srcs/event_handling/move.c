/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 00:45:36 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/05 20:41:17 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"
#define SLOWING 5

void
	ft_move_forward(t_all *all)
{
	double csn;
	double sn;
	double ncx;
	double ncy;

	csn = cos(all->vect.dir) / SLOWING;
	sn = -sin(all->vect.dir) / SLOWING;
	ncx = all->vect.posx + csn;
	ncy = all->vect.posy + sn;
	if (all->data.map[(int)ncy][(int)ncx] != '1'
	&& all->data.map[(int)ncy][(int)ncx] != '2')
	{
		all->vect.posx = ncx;
		all->vect.posy = ncy;
	}
	ft_create_image(all);
}

void
	ft_move_to_the_left(t_all *all)
{
	double csn;
	double sn;
	double ncx;
	double ncy;

	all->vect.dir += (PI + (PI / 2));
	csn = -cos(all->vect.dir) / SLOWING;
	sn = sin(all->vect.dir) / SLOWING;
	all->vect.dir -= (PI + (PI / 2));
	ncx = all->vect.posx + csn;
	ncy = all->vect.posy + sn;
	if (all->data.map[(int)ncy][(int)ncx] != '1'
	&& all->data.map[(int)ncy][(int)ncx] != '2')
	{
		all->vect.posx = ncx;
		all->vect.posy = ncy;
	}
	ft_create_image(all);
}

void
	ft_move_backwards(t_all *all)
{
	double csn;
	double sn;
	double ncx;
	double ncy;

	all->vect.dir += PI;
	csn = cos(all->vect.dir) / SLOWING;
	sn = -sin(all->vect.dir) / SLOWING;
	all->vect.dir -= PI;
	ncx = all->vect.posx + csn;
	ncy = all->vect.posy + sn;
	if (all->data.map[(int)ncy][(int)ncx] != '1'
	&& all->data.map[(int)ncy][(int)ncx] != '2')
	{
		all->vect.posx = ncx;
		all->vect.posy = ncy;
	}
	ft_create_image(all);
}

void
	ft_move_to_the_right(t_all *all)
{
	double csn;
	double sn;
	double ncx;
	double ncy;

	all->vect.dir += (PI / 2);
	csn = -cos(all->vect.dir) / SLOWING;
	sn = sin(all->vect.dir) / SLOWING;
	all->vect.dir -= (PI / 2);
	ncx = all->vect.posx + csn;
	ncy = all->vect.posy + sn;
	if (all->data.map[(int)ncy][(int)ncx] != '1'
	&& all->data.map[(int)ncy][(int)ncx] != '2')
	{
		all->vect.posx = ncx;
		all->vect.posy = ncy;
	}
	ft_create_image(all);
}
