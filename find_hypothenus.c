/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hypothenus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 23:57:01 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/01 19:39:01 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static double	ft_set_hyph_suite(t_all *all, double mody)
{
	if (all->vect.raycol == PI / 2)
	{
		return (mody);
	}
	else if (all->vect.raycol == PI + PI / 2)
	{
		return ((all->vect.posy - mody + CASE) - all->vect.posy);
	}
	//printf("PAR LA\n");
	return (0);
}

double			ft_set_hyph(t_all *all, double mody)
{
	//printf("PAR LA\n");
	if (all->vect.raycol < PI / 2 && all->vect.raycol > 0)
	{
		//printf("1 PAR LA\n");
		all->vect.teta = all->vect.raycol;
		return (((all->vect.posy - mody + CASE)
		- all->vect.posy) / sin(all->vect.teta));
	}
	else if (all->vect.raycol > PI / 2 && all->vect.raycol < PI)
	{
		//printf("2 PAR LA\n");
		all->vect.teta = PI - all->vect.raycol;
		return (((all->vect.posy - mody + CASE)
		- all->vect.posy) / sin(all->vect.teta));
	}
	else if (all->vect.raycol > PI && all->vect.raycol < PI + PI / 2)
	{
		//printf("3 PAR LA\n");
		all->vect.teta = all->vect.raycol - PI;
		return (mody / sin(all->vect.teta));
	}
	else if (all->vect.raycol > PI + PI / 2)
	{
		//printf("4 PAR LA\n");
		all->vect.teta = (2 * PI) - all->vect.raycol;
		return (mody / sin(all->vect.teta));
	}
	return (ft_set_hyph_suite(all, mody));
}

static double	ft_set_hypv_suite(t_all *all, double modx)
{
	if (all->vect.raycol == PI)
	{
		return (modx);
	}
	else if ((int)all->vect.raycol == 0)
	{
		return ((all->vect.posx - modx + CASE) - all->vect.posx);
	}
	return (0);
}

double			ft_set_hypv(t_all *all, double modx)
{
	if (all->vect.raycol < PI / 2 && all->vect.raycol > 0)
	{
		all->vect.teta = all->vect.raycol;
		return (((all->vect.posx - modx + CASE)
		- all->vect.posx) / cos(all->vect.teta));
	}
	else if (all->vect.raycol > PI / 2 && all->vect.raycol < PI)
	{
		all->vect.teta = PI - all->vect.raycol;
		return (modx / cos(all->vect.teta));
	}
	else if (all->vect.raycol > PI && all->vect.raycol < PI + PI / 2)
	{
		all->vect.teta = all->vect.raycol - PI;
		return (modx / cos(all->vect.teta));
	}
	else if (all->vect.raycol > PI + PI / 2)
	{
		all->vect.teta = (2 * PI) - all->vect.raycol;
		return (((all->vect.posx - modx + CASE)
		- all->vect.posx) / cos(all->vect.teta));
	}
	return (ft_set_hypv_suite(all, modx));
}
