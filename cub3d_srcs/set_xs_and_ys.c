/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_xs_and_ys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:58:32 by sachouam          #+#    #+#             */
/*   Updated: 2021/02/25 04:04:49 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

void
	ft_raycol_north_east(t_all *all)
{
	all->vect.fhy = all->vect.posy - all->vect.modyu - 1;
	all->vect.fhx = all->vect.posx +
	((all->vect.posy - (all->vect.fhy + 1)) / tan(all->vect.teta));
/*	
	if (all->vect.index <= (int)all->data.reswid / 2)
	{
		printf("\nlà\n");
		printf("posx = %lf\n", all->vect.posx);
		printf("posy = %lf\n", all->vect.posy);
		printf("fhy + 1 = %lf\n", all->vect.fhy + 1);
		printf("tan = %lf\n", tan(all->vect.teta));
	}
*/
	all->vect.hy = -1;
	all->vect.hx = 1 / tan(all->vect.teta);
	all->vect.fvx = all->vect.posx - all->vect.modxl + CASE;
	all->vect.fvy = all->vect.posy -
	((all->vect.fvx - all->vect.posx) * tan(all->vect.teta));
	all->vect.vx = 1;
	all->vect.vy = -(1 * tan(all->vect.teta));
}

void
	ft_raycol_north_west(t_all *all)
{
	all->vect.teta = PI - all->vect.raycol;
	all->vect.fhy = all->vect.posy - all->vect.modyu - 1;
	all->vect.fhx = all->vect.posx -
	((all->vect.posy - (all->vect.fhy + 1)) / tan(all->vect.teta));
	all->vect.hy = -1;
	all->vect.hx = -(1 / tan(all->vect.teta));
	all->vect.fvx = all->vect.posx - all->vect.modxl - 1;
	all->vect.fvy = all->vect.posy -
	((all->vect.posx - (all->vect.fvx + 1))
	* tan(all->vect.teta));
	all->vect.vx = -1;
	all->vect.vy = -(1 * tan(all->vect.teta));
}

void
	ft_raycol_south_west(t_all *all)
{
	all->vect.teta = all->vect.raycol - PI;
	all->vect.fhy = all->vect.posy - all->vect.modyu + CASE;
	all->vect.fhx = all->vect.posx - ((all->vect.fhy - all->vect.posy)
	/ tan(all->vect.teta));
	all->vect.hy = 1;
	all->vect.hx = -(1 / tan(all->vect.teta));
	all->vect.fvx = all->vect.posx - all->vect.modxl - 1;
	all->vect.fvy = all->vect.posy +
	((all->vect.posx - (all->vect.fvx + 1))
	* tan(all->vect.teta));
	all->vect.vx = -1;
	all->vect.vy = 1 * tan(all->vect.teta);
}

void
	ft_raycol_south_east(t_all *all)
{
	all->vect.teta = (2 * PI) - all->vect.raycol;
	all->vect.fhy = all->vect.posy - all->vect.modyu + CASE;
	all->vect.fhx = all->vect.posx + ((all->vect.fhy - all->vect.posy)
	/ tan(all->vect.teta));
	all->vect.hy = 1;
	all->vect.hx = 1 / tan(all->vect.teta);
	all->vect.fvx = all->vect.posx - all->vect.modxl + CASE;
	all->vect.fvy = all->vect.posy +
	((all->vect.fvx - all->vect.posx)
	* tan(all->vect.teta));
	all->vect.vx = 1;
	all->vect.vy = 1 * tan(all->vect.teta);
}

void
	ft_raycol_special_cases(t_all *all, int direction)
{
	if (direction == 5)
	{
		all->vect.fvx = all->vect.posx - all->vect.modxl + CASE;
		all->vect.fvy = all->vect.posy;
		all->vect.vx = 1;
	}
	else if (direction == 6)
	{
		all->vect.fhy = all->vect.posy - all->vect.modyu - 1;
		all->vect.fhx = all->vect.posx;
		all->vect.hy = -1;
	}
	else if (direction == 7)
	{
		all->vect.fvx = all->vect.posx - all->vect.modxl - 1;
		all->vect.fvy = all->vect.posy;
		all->vect.vx = -1;
	}
	else if (direction == 8)
	{
		all->vect.fhy = all->vect.posy - all->vect.modyu + CASE;
		all->vect.fhx = all->vect.posx;
		all->vect.hy = 1;
	}
}
