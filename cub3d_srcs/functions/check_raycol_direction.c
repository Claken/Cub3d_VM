/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_raycol_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 02:12:53 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/01 11:04:20 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

int
	ft_check_raycol_direction(t_all *all)
{
	if ((float)all->vect.raycol < (float)(PI / 2)
	&& (float)all->vect.raycol > 0.0)
		return (1);
	else if ((float)all->vect.raycol > (float)(PI / 2)
	&& (float)all->vect.raycol < (float)(PI))
		return (2);
	else if ((float)all->vect.raycol > (float)(PI)
	&& (float)all->vect.raycol < (float)(PI + (PI / 2)))
		return (3);
	else if ((float)all->vect.raycol > (float)(PI + (PI / 2))
	&& (float)all->vect.raycol < (float)(2 * PI))
		return (4);
	else if ((float)all->vect.raycol == (float)(PI * 2))
		return (5);
	else if ((float)all->vect.raycol == (float)(PI / 2))
		return (6);
	else if ((float)all->vect.raycol == (float)(PI))
		return (7);
	else if ((float)all->vect.raycol == (float)(PI + (PI / 2)))
		return (8);
	return (0);
}
