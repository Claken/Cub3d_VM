/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:05:40 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/03 20:42:29 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// faire une liste chainée de sprite (?)
// stocker dans chaque elem de la liste les coordonnées x/y du sprite
// stocker le "side", les différents raycols pour tracer
// trier sprite selon distance (du plus loin au plus près)

#include "../../cub3d_includes/cub3d.h"

static void
	ft_sprite_calculations(t_all *all)
{
	
}

static void
	ft_sprite_mapping(t_all *all)
{
	int x;
	int y;
	int i;
	double sprx;
	double spry;

	x = all->spr.rayx - all->spr.j;
	i = (double)all->image.sprite.height
	/ (double)all->disp.colhei;
	spry = (all->disp.pixbeg
	- (all->data.reshei / 2 - all->disp.colhei / 2)) * i;
	sprx = all->image.sprite.width / x;
	while (x < all->spr.rayx)
	{
		y = all->disp.pixbeg;
		while (y < all->disp.pixend)
		{
			all->disp.color = all->image.sprite.addr[(int)spry
			* all->image.sprite.width + (int)sprx];
			if (all->disp.color != 0x00000000)
				all->disp.addr[y *
				all->data.reswid + x] = all->disp.color;
			spry += i;
			y++;
		}
		x++;
	}
}


/*
void
	ft_sprites_management(t_all *all)
{
	
}
*/
