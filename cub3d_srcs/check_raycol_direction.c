/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_raycol_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 02:12:53 by sachouam          #+#    #+#             */
/*   Updated: 2021/02/25 04:07:51 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

int
	ft_check_raycol_direction(t_all *all)
{
	if (all->vect.raycol < PI / 2 && all->vect.raycol > 0.0)
		return (1);
	else if (all->vect.raycol > PI / 2 && all->vect.raycol < PI)
		return (2);
	else if (all->vect.raycol > PI && all->vect.raycol < PI + (PI / 2))
		return (3);
	else if (all->vect.raycol > PI + (PI / 2) && all->vect.raycol < 2 * PI)
		return (4);
	else if (all->vect.raycol == PI * 2)
		return (5);
	else if (all->vect.raycol == PI / 2)
		return (6);
	else if (all->vect.raycol == PI)
		return (7);
	else if (all->vect.raycol == PI + (PI / 2))
		return (8);
	return (0);
}
