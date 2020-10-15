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

void	ft_raycol_north_east(t_all *all, double modx, double mody)
{
	printf("par là ! ! !\n");
	all->vect.fhy = all->vect.posy - mody - 1;
	all->vect.fhx = all->vect.posx +
	((all->vect.posy - all->vect.fhy) / tan(all->vect.raycol));
	all->vect.hy = -1;
	all->vect.hx = 1 / tan(all->vect.raycol);
	all->vect.fvx = all->vect.posx - modx + CASE;
	all->vect.fvy = all->vect.posy -
	((all->vect.fvx - all->vect.posx) * tan(all->vect.raycol));
	all->vect.vx = 1;
	all->vect.vy = 1 * tan(all->vect.raycol);
}

void	ft_raycol_north_west(t_all *all, double modx, double mody)
{
	all->vect.teta = PI - all->vect.raycol;
	all->vect.fhy = all->vect.posy - mody - 1;
	all->vect.fhx = all->vect.posx -
	((all->vect.posy - (all->vect.fhy + 1))
	/ tan(all->vect.teta));
	all->vect.hy = -1;
	all->vect.hx = -(1 / tan(all->vect.teta));
	all->vect.fvx = all->vect.posx - modx - 1;
	all->vect.fvy = all->vect.posy -
	((all->vect.posx - (all->vect.fvx + 1))
	* tan(all->vect.teta));
	all->vect.vx = -1;
	all->vect.vy = -(1 * tan(all->vect.teta));
}

void	ft_raycol_south_west(t_all *all, double modx, double mody)
{
	all->vect.teta = all->vect.raycol - PI;
	all->vect.fhy = all->vect.posy - mody + CASE;
	all->vect.fhx = all->vect.posx -
	((all->vect.fhy - all->vect.posy)
	/ tan(all->vect.teta));
	all->vect.hy = 1;
	all->vect.hx = -(1 / tan(all->vect.teta));
	all->vect.fvx = all->vect.posx - modx - 1;
	all->vect.fvy = all->vect.posy +
	((all->vect.posx - (all->vect.fvx + 1))
	* tan(all->vect.teta));
	all->vect.vx = -1;
	all->vect.vy = 1 * tan(all->vect.teta);
}

void	ft_raycol_south_east(t_all *all, double modx, double mody)
{
	//printf("\nje suis là wesh\n");
	all->vect.teta = (2 * PI) - all->vect.raycol;
	//printf("2 * PI = %lf\n", (2 * PI));
	//printf("raycol = %lf\n", all->vect.raycol);
	//printf("teta = %lf\n", all->vect.teta);
	all->vect.fhy = all->vect.posy - mody + CASE;
	all->vect.fhx = all->vect.posx +
	((all->vect.fhy - all->vect.posy)
	/ tan(all->vect.teta));
	/*
	printf("%lf + ", all->vect.posx);
	printf("((%lf - ", all->vect.fhy);
	printf("%lf) / ", all->vect.posy);
	printf("%lf)\n", tan(all->vect.teta));
	*/
	all->vect.hy = 1;
	all->vect.hx = 1 / tan(all->vect.teta);
	all->vect.fvx = all->vect.posx - modx + CASE;
	all->vect.fvy = all->vect.posy +
	((all->vect.fvx - all->vect.posx)
	* tan(all->vect.teta));
	all->vect.vx = 1;
	all->vect.vy = 1 * tan(all->vect.teta);
}

void	ft_check_raycol_dir_part_two(t_all *all, double modx, double mody)
{
	if (all->vect.raycol == PI / 2)
	{
		all->vect.fhy = all->vect.posy - mody - 1;
		all->vect.fhx = all->vect.posx;
		all->vect.hy = -1;
	}
	else if (all->vect.raycol == PI + (PI / 2))
	{
		all->vect.fhy = all->vect.posy - mody + CASE;
		all->vect.fhx = all->vect.posx;
		all->vect.hy = 1;
	}
	else if ((int)all->vect.raycol == 0)
	{
		all->vect.fvx = all->vect.posx - modx + CASE;
		all->vect.fvy = all->vect.posy;
		all->vect.vx = 1;
	}
	else if (all->vect.raycol == PI)
	{
		all->vect.fvx = all->vect.posx - modx - 1;
		all->vect.fvy = all->vect.posy;
		all->vect.vx = -1;
	}
}
