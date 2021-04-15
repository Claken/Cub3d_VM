/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:05:40 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/16 00:01:38 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// faire une liste chainée de sprite (?)
// stocker dans chaque elem de la liste les coordonnées x/y du sprite
// stocker le "side", les différents raycols pour tracer
// trier sprite selon distance (du plus loin au plus près)

#include "../../cub3d_includes/cub3d.h"

void
	ft_get_sprite_data(t_all *all, int side)
{
	if (all->spr.j == 0)
	{
		if (side == 0)
		{
			all->spr.x = all->vect.fhx - fmod(all->vect.fhx, 1) + 0.5;
			all->spr.y = all->vect.fhy - fmod(all->vect.fhy, 1) + 0.5;
		}
		else if (side == 1)
		{
			all->spr.x = all->vect.fvx - fmod(all->vect.fvx, 1) + 0.5;
			all->spr.y = all->vect.fvy - fmod(all->vect.fvy, 1) + 0.5;
		}
	}
	all->spr.j++;
}

static void
	ft_find_centerx_of_sprite(t_all *all)
{
	double xs;
	double ys;
	double teta;
	double tmpy;

	xs = all->spr.x - all->vect.posx;
	ys = all->vect.posy - all->spr.y;
	teta = atan2(ys, xs);
	if (teta < 0)
		teta += PI * 2;
	tmpy = all->vect.dir + all->vect.fov / 2 - teta;
	if (teta > PI + (PI / 2) && all->vect.dir < PI / 2)
		tmpy += PI * 2;
	else if (all->vect.dir > PI + (PI / 2) && teta < PI / 2)
		tmpy -= PI * 2;
	all->spr.centerx = tmpy * all->data.reswid / all->vect.fov;
}

void
	ft_sprite_calculations(t_all *all)
{
	double xx;
	double yy;

	xx = all->vect.posx - all->spr.x;
	yy = all->vect.posy - all->spr.y;
	all->spr.distance = (sqrt(pow(xx, 2) + pow(yy, 2)));
	all->disp.colhei = (CASE / all->spr.distance) * all->vect.distscreen;
	all->disp.pixbeg = -all->disp.colhei / 2 + all->data.reshei / 2;
	if (all->disp.pixbeg < 0)
		all->disp.pixbeg = 0;
	all->disp.pixend = all->disp.colhei / 2 + all->data.reshei / 2;
	if (all->disp.pixend >= (int)all->data.reshei)
		all->disp.pixend = all->data.reshei - 1;
	ft_find_centerx_of_sprite(all);
	all->spr.begx = all->spr.centerx - (all->disp.colhei / 2);
	if (all->spr.begx < 0)
		all->spr.begx = 0;
	all->spr.endx = all->spr.centerx + (all->disp.colhei / 2);
	if (all->spr.endx >= (int)all->data.reswid)
		all->spr.endx = all->data.reswid - 1;
}

void
	ft_sprite_mapping(t_all *all)
{
	int x;
	int y;
	double ii;
	double i;
	double sprx;
	double spry;

	x = all->spr.begx;
	ii = (double)all->image.sprite.width / (double)all->disp.colhei;
	sprx = (x - (all->spr.centerx - (all->disp.colhei / 2))) * ii;
	i = (double)all->image.sprite.height / (double)all->disp.colhei;
	while (x < all->spr.endx)
	{
		y = all->disp.pixbeg;
		spry = (y - (all->data.reshei / 2 - all->disp.colhei / 2)) * i;
		if (all->spr.distwalls[x] + 0.5 > all->spr.distance)
			while (y <= all->disp.pixend)
			{
				all->disp.color = all->image.sprite.addr[(int)spry
				* all->image.sprite.width + (int)sprx];
				if (all->disp.color && all->disp.color != (int)0xff000000)
					all->disp.addr[y *
					all->data.reswid + x] = all->disp.color;
				y++;
				spry += i;
			}
		x++;
		sprx += ii;
	}
}

/*
void
	ft_sprites_management(t_all *all)
{
	
}
*/
