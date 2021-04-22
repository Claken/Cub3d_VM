/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_data_calcul_mapping.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:35:47 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/22 13:14:46 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

static void
	ft_get_sprite_data(t_all *all, double sx, double sy)
{
	double		xx;
	double		yy;
	t_sprite	*svg;

	if (!(ft_add_sprite_back(&all->sprites, sx, sy)))
		return ;
	svg = all->sprites;
	while (all->sprites->next)
		all->sprites = all->sprites->next;
	xx = all->vect.posx - all->sprites->x;
	yy = all->vect.posy - all->sprites->y;
	all->sprites->distance = (sqrt(pow(xx, 2) + pow(yy, 2)));
	all->sprites = svg;
}

void
	ft_check_sprites_on_the_map(t_all *all)
{
	int i;
	int j;

	i = -1;
	while (all->data.map[++i])
	{
		j = -1;
		while (all->data.map[i][++j])
		{
			if (all->data.map[i][j] == '2')
				ft_get_sprite_data(all,
				(double)j, (double)i);
		}
	}
}

static void
	ft_find_centerx_of_sprite(t_all *all, t_sprite **spr)
{
	double xs;
	double ys;
	double teta;
	double tmpy;

	xs = (*spr)->x - all->vect.posx;
	ys = all->vect.posy - (*spr)->y;
	teta = atan2(ys, xs);
	if (teta < 0)
		teta += PI * 2;
	tmpy = all->angle.dir + all->angle.fov / 2 - teta;
	if (teta > PI + (PI / 2) && all->angle.dir < PI / 2)
		tmpy += PI * 2;
	else if (all->angle.dir > PI + (PI / 2) && teta < PI / 2)
		tmpy -= PI * 2;
	(*spr)->centerx = tmpy * all->data.reswid / all->angle.fov;
}

void
	ft_sprite_calculations(t_all *all, t_sprite **spr)
{
	all->disp.colhei = (CASE / (*spr)->distance) * all->calcul.distscreen;
	all->disp.pixbeg = -all->disp.colhei / 2 + all->data.reshei / 2;
	all->disp.pixend = all->disp.colhei / 2 + all->data.reshei / 2;
	if (all->disp.pixbeg < 0)
		all->disp.pixbeg = 0;
	if (all->disp.pixend >= (int)all->data.reshei)
		all->disp.pixend = all->data.reshei - 1;
	ft_find_centerx_of_sprite(all, spr);
	(*spr)->begx = (*spr)->centerx - (all->disp.colhei / 2);
	(*spr)->endx = (*spr)->centerx + (all->disp.colhei / 2);
	if ((*spr)->begx < 0)
		(*spr)->begx = 0;
	if ((*spr)->endx >= (int)all->data.reswid)
		(*spr)->endx = all->data.reswid - 1;
	(*spr)->ix = (double)all->image.sprite.width / (double)all->disp.colhei;
	(*spr)->iy = (double)all->image.sprite.height / (double)all->disp.colhei;
}

void
	ft_sprite_mapping(t_all *all, t_sprite *spr)
{
	int	x;
	int	y;
	double	sprx;
	double	spry;

	x = spr->begx - 1;
	sprx = ((x + 1) - (spr->centerx - (all->disp.colhei / 2)))
	* spr->ix;
	while (++x < spr->endx)
	{
		y = all->disp.pixbeg - 1;
		spry = ((y + 1) - (all->data.reshei / 2 - all->disp.colhei / 2))
		* spr->iy;
		if (all->distwalls[x] + 0.5 > spr->distance)
			while (++y <= all->disp.pixend)
			{
				all->disp.color = all->image.sprite.addr[(int)spry
				* all->image.sprite.width + (int)sprx];
				if (all->disp.color && all->disp.color != (int)0xff000000)
					all->disp.addr[y *
					all->data.reswid + x] = all->disp.color;
				spry += spr->iy;
			}
		sprx += spr->ix;
	}
}
