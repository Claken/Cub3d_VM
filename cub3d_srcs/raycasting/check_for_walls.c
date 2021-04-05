/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:15:27 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/04 18:35:48 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

static void
	ft_if_hyph_is_inferior(t_all *all,
	double *hyph, int *hit, int i)
{
	if (all->data.map[(int)all->vect.fhy][(int)all->vect.fhx] == '2')
	{
		ft_get_sprite_data(all, i, 0);
	}
	if (all->data.map[(int)all->vect.fhy][(int)all->vect.fhx] == '1')
	{
		if (all->vect.hy == -1)
			all->vect.side = 1;
		else if (all->vect.hy == 1)
			all->vect.side = 3;
		*hit = 1;
	}
	else
	{
		all->vect.fhx += all->vect.hx;
		all->vect.fhy += all->vect.hy;
		*hyph += CASE / sin(all->vect.teta);
	}
}

static void
	ft_if_hypv_is_inferior(t_all *all,
	double *hypv, int *hit, int i)
{
	if (all->data.map[(int)all->vect.fvy][(int)all->vect.fvx] == '2')
	{
		ft_get_sprite_data(all, i, 1);
	}
	if (all->data.map[(int)all->vect.fvy][(int)all->vect.fvx] == '1')
	{
		if (all->vect.vx == -1)
			all->vect.side = 4;
		else if (all->vect.vx == 1)
			all->vect.side = 2;
		*hit = 1;
	}
	else
	{
		all->vect.fvx += all->vect.vx;
		all->vect.fvy += all->vect.vy;
		*hypv += CASE / cos(all->vect.teta);
	}
}

void
	ft_check_for_walls_and_sprites(t_all *all, int i)
{
	double hyph;
	double hypv;
	int hit;

	hyph = ft_set_hyph(all);
	hypv = ft_set_hypv(all);
	hit = 0;
	while (!hit)
	{
		if (hyph < hypv)
		{
			ft_if_hyph_is_inferior(all, &hyph, &hit, i);
		}
		else
		{
			ft_if_hypv_is_inferior(all, &hypv, &hit, i);
		}
	}
}