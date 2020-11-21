/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hypothenus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:01:14 by sachouam          #+#    #+#             */
/*   Updated: 2020/11/21 17:03:38 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void		ft_set_teta(t_all *all)
{
	if (all->vect.raycol < PI / 2 && all->vect.raycol > 0)
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

static double		ft_set_hyph_suite(t_all *all, double hh)
{
	double hyph;

	hyph = hh;
	if (all->vect.raycol == PI / 2)
	{
		//printf("pi / 2 \n");
		hyph = all->vect.modyu;
	}
	else if (all->vect.raycol == PI + PI / 2)
	{
		hyph = (all->vect.posy - all->vect.modyu + CASE)
		- all->vect.posy;
	}
	return (hyph);
}

static double		ft_set_hypv_suite(t_all *all, double hv)
{
	double hypv;

	hypv = hv;
	if (all->vect.raycol == PI)
	{
		hypv = all->vect.modxl;
	}
	else if ((int)all->vect.raycol == 0)
	{
		hypv = (all->vect.posx - all->vect.modxl + CASE)
		- all->vect.posx;
	}
	return (hypv);
}

double			ft_set_hyph(t_all *all)
{
	double hyph;

	hyph = 0;
	ft_set_teta(all);
	if ((all->vect.raycol < PI / 2 && all->vect.raycol > 0)
	|| (all->vect.raycol > PI / 2 && all->vect.raycol < PI))
	{
		//printf("okh\n");
		hyph = all->vect.modyu / sin(all->vect.teta);
	}
	else if ((all->vect.raycol > PI && all->vect.raycol < PI + PI / 2)
	|| (all->vect.raycol > PI + PI / 2 && all->vect.raycol < 2 * PI))
	{
		//printf("koh\n");
		hyph = ((all->vect.posy - all->vect.modyu + CASE)
		- all->vect.posy) / sin(all->vect.teta);
	}
	return (ft_set_hyph_suite(all, hyph));
}

double			ft_set_hypv(t_all *all)
{
	double hypv;

	hypv = 0;
	ft_set_teta(all);
	if ((all->vect.raycol < PI / 2 && all->vect.raycol > 0)
	|| (all->vect.raycol > PI + PI / 2 && all->vect.raycol < 2 * PI))
	{
		//printf("okv\n");
		hypv = ((all->vect.posx - all->vect.modxl + CASE)
		- all->vect.posx) / cos(all->vect.teta);
	}
	else if ((all->vect.raycol > PI / 2 && all->vect.raycol < PI)
	|| (all->vect.raycol > PI && all->vect.raycol < PI + PI / 2))
	{
		//printf("kov\n");
		hypv = all->vect.modxl / cos(all->vect.teta);
	}
	return (ft_set_hypv_suite(all, hypv));
}
