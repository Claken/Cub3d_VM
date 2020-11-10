/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hypothenus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 23:57:01 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/14 20:43:40 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	ft_set_teta(t_all *all)
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

static double	ft_set_hyph_suite(t_all *all, double hh)
{
	double hyph;

	hyph = hh;
	if (all->vect.raycol == PI / 2)
	{
		hyph = mody;
	}
	else if (all->vect.raycol == PI + PI / 2)
	{
		hyph = (all->vect.posy - mody + CASE)
		- all->vect.posy;
	}
	return (hyph);
}

static double	ft_set_hypv_suite(t_all *all, double hv)
{
	double hypv;

	hypv = hv;
	if (all->vect.raycol == PI)
	{
		hypv = modx;
	}
	else if ((int)all->vect.raycol == 0)
	{
		hypv = (all->vect.posx - modx + CASE)
		- all->vect.posx;
	}
	return (hypv);
}

double		ft_set_hyph(t_all *all)
{
	double hyph;

	hyph = 0;
	ft_set_teta(all);
	if (all->vect.raycol < PI / 2 && all->vect.raycol > 0)
	{
		hyph = ((all->vect.posy - mody + CASE)
		- all->vect.posy) / sin(all->vect.teta);
	}
	else if (all->vect.raycol > PI / 2 && all->vect.raycol < PI)
	{
		hyph = ((all->vect.posy - mody + CASE)
		- all->vect.posy) / sin(all->vect.teta);
	}
	else if (all->vect.raycol > PI && all->vect.raycol < PI + PI / 2)
	{
		hyph = mody / sin(all->vect.teta);
	}
	else if (all->vect.raycol > PI + PI / 2 && all->vect.raycol < 2 * PI)
	{
		hyph = mody / sin(all->vect.teta);
	}
	return (ft_set_hyph_suite(all, hyph));
}

double		ft_set_hypv(t_all *all)
{
	double hypv;

	hypv = 0;
	ft_set_teta(all);
	if (all->vect.raycol < PI / 2 && all->vect.raycol > 0)
	{
		hypv = ((all->vect.posx - modx + CASE)
		- all->vect.posx) / cos(all->vect.teta);
	}
	else if (all->vect.raycol > PI / 2 && all->vect.raycol < PI)
	{
		hypv = modx / cos(all->vect.teta);
		printf("modx = %lf\n", modx);
		printf("cos(teta)  = %lf\n", cos(all->vect.teta));
	}
	else if (all->vect.raycol > PI && all->vect.raycol < PI + PI / 2)
	{
		hypv = modx / cos(all->vect.teta);
	}
	else if (all->vect.raycol > PI + PI / 2 && all->vect.raycol < 2 * PI)
	{
		hypv = ((all->vect.posx - modx + CASE)
		- all->vect.posx) / cos(all->vect.teta);
	}
	return (ft_set_hypv_suite(all, hypv));
}
