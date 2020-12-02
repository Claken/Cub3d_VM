/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_xs_and_ys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:58:32 by sachouam          #+#    #+#             */
/*   Updated: 2020/12/02 16:50:48 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_raycol_north_east(t_all *all)
{
	//printf("NE\n");
	all->vect.fhy = all->vect.posy - all->vect.modyu - 1;
	all->vect.fhx = all->vect.posx +
	((all->vect.posy - all->vect.fhy) / tan(all->vect.teta));
	//printf("fhx = posx %lf + ((posy %lf - fhy %lf) / tan(teta) %lf)\n",
	//all->vect.posx, all->vect.posy, all->vect.fhy, tan(all->vect.teta));
	all->vect.hy = -1;
	all->vect.hx = 1 / tan(all->vect.teta);
	all->vect.fvx = all->vect.posx - all->vect.modxl + CASE;
	all->vect.fvy = all->vect.posy -
	((all->vect.fvx - all->vect.posx) * tan(all->vect.teta));
	all->vect.vx = 1;
	all->vect.vy = -(1 * tan(all->vect.teta));
}

void	ft_raycol_north_west(t_all *all)
{
	//printf("NW\n");
	all->vect.teta = PI - all->vect.raycol;
	all->vect.fhy = all->vect.posy - all->vect.modyu - 1;
	all->vect.fhx = all->vect.posx -
	((all->vect.posy - (all->vect.fhy + 1))
	/ tan(all->vect.teta));
	all->vect.hy = -1;
	all->vect.hx = -(1 / tan(all->vect.teta));
	all->vect.fvx = all->vect.posx - all->vect.modxl - 1;
	all->vect.fvy = all->vect.posy -
	((all->vect.posx - (all->vect.fvx + 1))
	* tan(all->vect.teta));
	all->vect.vx = -1;
	all->vect.vy = -(1 * tan(all->vect.teta));
}

void	ft_raycol_south_west(t_all *all)
{
	//printf("SW\n");
	all->vect.teta = all->vect.raycol - PI;
	all->vect.fhy = all->vect.posy - all->vect.modyu + CASE;
	all->vect.fhx = all->vect.posx -
	((all->vect.fhy - all->vect.posy)
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

void	ft_raycol_south_east(t_all *all)
{
	//printf("SE\n");
	all->vect.teta = (2 * PI) - all->vect.raycol;
	all->vect.fhy = all->vect.posy - all->vect.modyu + CASE;
	all->vect.fhx = all->vect.posx +
	((all->vect.fhy - all->vect.posy)
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
