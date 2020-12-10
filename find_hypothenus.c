/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hypothenus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:01:14 by sachouam          #+#    #+#             */
/*   Updated: 2020/12/10 14:49:42 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void		ft_set_teta(t_all *all)
{
	if (all->vect.raycol < PI / 2 && all->vect.raycol > 0.0)
	{
		all->vect.teta = all->vect.raycol;
	}
	else if (all->vect.raycol > PI / 2 && all->vect.raycol < PI)
	{
		all->vect.teta = PI - all->vect.raycol;
	}
	else if (all->vect.raycol > PI && all->vect.raycol < PI + PI / 2)
	{
		all->vect.teta = all->vect.raycol - PI;
	}
	else if (all->vect.raycol > PI + PI / 2 && all->vect.raycol < 2 * PI)
	{
		all->vect.teta = (2 * PI) - all->vect.raycol;
	}
}

double			ft_set_hyph(t_all *all)
{
	double hyph;

	hyph = 0;
	ft_set_teta(all);
	if ((all->vect.raycol < PI / 2 && all->vect.raycol > 0.0)
	|| (all->vect.raycol > PI / 2 && all->vect.raycol < PI))
	{
		hyph = all->vect.modyu / sin(all->vect.teta);
	}
	else if ((all->vect.raycol > PI && all->vect.raycol < PI + PI / 2)
	|| (all->vect.raycol > PI + PI / 2 && all->vect.raycol < 2 * PI))
	{
		hyph = ((all->vect.posy - all->vect.modyu + CASE)
		- all->vect.posy) / sin(all->vect.teta);
	}
	return (hyph);
}

double			ft_set_hypv(t_all *all)
{
	double hypv;

	hypv = 0;
	ft_set_teta(all);
	if ((all->vect.raycol < PI / 2 && all->vect.raycol > 0.0)
	|| (all->vect.raycol > PI + PI / 2 && all->vect.raycol < 2 * PI))
	{
		hypv = ((all->vect.posx - all->vect.modxl + CASE)
		- all->vect.posx) / cos(all->vect.teta);
	}
	else if ((all->vect.raycol > PI / 2 && all->vect.raycol < PI)
	|| (all->vect.raycol > PI && all->vect.raycol < PI + PI / 2))
	{
		hypv = all->vect.modxl / cos(all->vect.teta);
	}
	return (hypv);
}
