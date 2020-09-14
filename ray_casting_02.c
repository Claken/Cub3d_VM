/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:29:15 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/14 20:45:24 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_check_raycol_value(t_all *all)
{
	double full;
	double save;

	full = PI * 2;
	save = all->vect.raycol;
	if (all->vect.raycol > full)
	{
		all->vect.raycol = fmod(all->vect.raycol, full);
	}
	else if (all->vect.raycol < 0)
	{
		all->vect.raycol = full - save;
	}
}
