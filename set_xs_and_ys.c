/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_xs_and_ys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 04:14:20 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/14 20:42:52 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_raycol_north_east(t_all *all)
{
	all->vect.fhy = all->vect.posy - all->vect.modyu - 1;
	printf("fhy = %lf\n", all->vect.fhy);
	all->vect.fhx = all->vect.posx +
	((all->vect.posy - all->vect.fhy) / tan(all->vect.teta));
	all->vect.hy = -1;
	all->vect.hx = 1 / tan(all->vect.teta);
	all->vect.fvx = all->vect.posx - all->vect.modxr + CASE;
	printf("fvx = %lf\n", all->vect.fvx);
	all->vect.fvy = all->vect.posy -
	((all->vect.fvx - all->vect.posx) * tan(all->vect.teta));
	all->vect.vx = 1;
	all->vect.vy = 1 * tan(all->vect.teta);
}

void	ft_raycol_north_west(t_all *all)
{
	all->vect.teta = PI - all->vect.raycol;
	all->vect.fhy = all->vect.posy - all->vect.modyu - 1;
	printf("fhy = %lf\n", all->vect.fhy);
	all->vect.fhx = all->vect.posx -
	((all->vect.posy - (all->vect.fhy + 1))
	/ tan(all->vect.teta));
	all->vect.hy = -1;
	all->vect.hx = -(1 / tan(all->vect.teta));
	all->vect.fvx = all->vect.posx - all->vect.modxl - 1;
	printf("fvx = %lf\n", all->vect.fvx);
	all->vect.fvy = all->vect.posy -
	((all->vect.posx - (all->vect.fvx + 1))
	* tan(all->vect.teta));
	all->vect.vx = -1;
	all->vect.vy = -(1 * tan(all->vect.teta));
}

void	ft_raycol_south_west(t_all *all)
{
	all->vect.teta = all->vect.raycol - PI;
	all->vect.fhy = all->vect.posy - all->vect.modyd + CASE;
	printf("fhy = %lf\n", all->vect.fhy);
	all->vect.fhx = all->vect.posx -
	((all->vect.fhy - all->vect.posy)
	/ tan(all->vect.teta));
	all->vect.hy = 1;
	all->vect.hx = -(1 / tan(all->vect.teta));
	all->vect.fvx = all->vect.posx - all->vect.modxl - 1;
	printf("fvx = %lf\n", all->vect.fvx);
	all->vect.fvy = all->vect.posy +
	((all->vect.posx - (all->vect.fvx + 1))
	* tan(all->vect.teta));
	all->vect.vx = -1;
	all->vect.vy = 1 * tan(all->vect.teta);
}

void	ft_raycol_south_east(t_all *all)
{
	all->vect.teta = (2 * PI) - all->vect.raycol;
	all->vect.fhy = all->vect.posy - all->vect.modyd + CASE;
	printf("fhy = %lf\n", all->vect.fhy);
	all->vect.fhx = all->vect.posx +
	((all->vect.fhy - all->vect.posy)
	/ tan(all->vect.teta));
	all->vect.hy = 1;
	all->vect.hx = 1 / tan(all->vect.teta);
	all->vect.fvx = all->vect.posx - all->vect.modxr + CASE;
	printf("fvx = %lf\n", all->vect.fvx);
	all->vect.fvy = all->vect.posy +
	((all->vect.fvx - all->vect.posx)
	* tan(all->vect.teta));
	all->vect.vx = 1;
	all->vect.vy = 1 * tan(all->vect.teta);
}

void	ft_check_raycol_dir_part_two(t_all *all)
{
	if (all->vect.raycol == PI / 2)
	{
		all->vect.fhy = all->vect.posy + all->vect.modyd - CASE - 1;
		printf("fhy = %lf\n", all->vect.fhy);
		all->vect.fhx = all->vect.posx;
		all->vect.hy = -1;
	}
	else if (all->vect.raycol == PI + (PI / 2))
	{
		all->vect.fhy = all->vect.posy - all->vect.modyu + CASE;
		printf("fhy = %lf\n", all->vect.fhy);
		all->vect.fhx = all->vect.posx;
		all->vect.hy = 1;
	}
	else if ((int)all->vect.raycol == 0)
	{
		all->vect.fvx = all->vect.posx - all->vect.modxl + CASE;
		printf("fvx = %lf\n", all->vect.fvx);
		all->vect.fvy = all->vect.posy;
		all->vect.vx = 1;
	}
	else if (all->vect.raycol == PI)
	{
		all->vect.fvx = all->vect.posx + all->vect.modxr - CASE - 1;
		printf("fvx = %lf\n", all->vect.fvx);
		all->vect.fvy = all->vect.posy;
		all->vect.vx = -1;
	}
}
