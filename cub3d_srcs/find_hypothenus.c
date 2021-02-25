/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hypothenus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:01:14 by sachouam          #+#    #+#             */
/*   Updated: 2021/02/25 03:48:20 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

static void
	ft_set_teta(t_all *all, int direction)
{
	if (direction == 1)
		all->vect.teta = all->vect.raycol;
	else if (direction == 2)
		all->vect.teta = PI - all->vect.raycol;
	else if (direction == 3)
		all->vect.teta = all->vect.raycol - PI;
	else if (direction == 4)
		all->vect.teta = (2 * PI) - all->vect.raycol;
}

static double
	ft_set_hyph_special_cases(t_all *all, int direction)
{
	if (direction == 6)
		return (all->vect.modyu);
	else if (direction == 8)
		return ((all->vect.posy - all->vect.modyu + CASE)
		- all->vect.posy);
	else
		return (10000);
	return (0);
}

double
	ft_set_hyph(t_all *all)
{
	double hyph;
	int direction;

	hyph = 0;
	direction = ft_check_raycol_direction(all);
	ft_set_teta(all, direction);
	if (direction == 1 || direction == 2)
		hyph = all->vect.modyu / sin(all->vect.teta);
	else if (direction == 3 || direction == 4)
		hyph = ((all->vect.posy - all->vect.modyu + CASE)
		- all->vect.posy) / sin(all->vect.teta);
	else
		hyph = ft_set_hyph_special_cases(all, direction);
	return (hyph);
}

static double
	ft_set_hypv_special_cases(t_all *all, int direction)
{
	if (direction == 5)
		return ((all->vect.posx - all->vect.modxl + CASE)
		- all->vect.posx);
	else if (direction == 7)
		return (all->vect.modxl);
	else
		return (10000);
	return (0);
}

double
	ft_set_hypv(t_all *all)
{
	double hypv;
	int direction;

	hypv = 0;
	direction = ft_check_raycol_direction(all);
	ft_set_teta(all, direction);
	if (direction == 1 || direction == 4)
		hypv = ((all->vect.posx - all->vect.modxl + CASE)
		- all->vect.posx) / cos(all->vect.teta);
	else if (direction == 2 || direction == 3)
		hypv = all->vect.modxl / cos(all->vect.teta);
	else
		hypv = ft_set_hypv_special_cases(all, direction);
	return (hypv);
}
