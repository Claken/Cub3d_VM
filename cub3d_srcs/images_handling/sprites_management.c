/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:05:40 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/06 14:22:58 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// faire une liste chainée de sprite (?)
// stocker dans chaque elem de la liste les coordonnées x/y du sprite
// stocker le "side", les différents raycols pour tracer
// trier sprite selon distance (du plus loin au plus près)

#include "../../cub3d_includes/cub3d.h"

void
	ft_get_sprite_data(t_all *all, int i, int side)
{
	if (all->spr.j == 0)
	{
		all->spr.side = side;
		if (side == 0)
		{
			all->spr.x = all->vect.fhx;
			all->spr.y = all->vect.fhy;
		}
		else if (side == 1)
		{
			all->spr.x = all->vect.fvx;
			all->spr.y = all->vect.fvy;
		}
		all->spr.rayx = i;
	}
	all->spr.j++;
	all->spr.rayx++;
}

void
	ft_sprite_calculations(t_all *all)
{
	double xx;
	double yy;

	xx = all->vect.posx - (all->spr.x - fmod(all->spr.x, 1) + 0.5);
	yy = all->vect.posy - (all->spr.y - fmod(all->spr.y, 1) + 0.5);
	all->spr.distwall = (sqrt(pow(xx, 2) + pow(yy, 2)));
	all->disp.colhei = (CASE / all->spr.distwall) * all->vect.distscreen;
	all->disp.pixbeg = -all->disp.colhei / 2 + all->data.reshei / 2;
	if (all->disp.pixbeg < 0)
		all->disp.pixbeg = 0;
	all->disp.pixend = all->disp.colhei / 2 + all->data.reshei / 2;
	if (all->disp.pixend >= (int)all->data.reshei)
		all->disp.pixend = all->data.reshei - 1;
	all->spr.begx = (all->spr.rayx - (all->spr.j / 2)) - all->disp.colhei / 2;
	if (all->spr.begx < 0)
		all->spr.begx = 0;
	all->spr.endx = (all->spr.rayx - (all->spr.j / 2)) + all->disp.colhei / 2;
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
	sprx = (x - (all->spr.rayx - (all->spr.j / 2) - all->disp.colhei / 2)) * ii;
	i = (double)all->image.sprite.height / (double)all->disp.colhei;
	while (x < all->spr.endx)
	{
		y = all->disp.pixbeg;
		spry = (y - (all->data.reshei / 2 - all->disp.colhei / 2)) * i;
		while (y <= all->disp.pixend)
		{
			all->disp.color = all->image.sprite.addr[(int)spry
			* all->image.sprite.width + (int)sprx];
			if (all->disp.color != 0x00000000)
				all->disp.addr[y * all->data.reswid + x] = all->disp.color;
			spry += i;
			y++;
		}
		sprx += ii;
		x++;
	}
}

/*
void
	ft_sprites_management(t_all *all)
{
	
}
*/
