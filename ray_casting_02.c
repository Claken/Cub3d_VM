/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:29:15 by sachouam          #+#    #+#             */
/*   Updated: 2020/12/20 19:30:25 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void
	ft_check_raycol_value(t_all *all)
{
	double full;

	full = ft_degree_to_radian(360);
	//printf("raycol bf reconversion = %lf\n", all->vect.raycol);
	if (all->vect.raycol > full)
	{
		all->vect.raycol = fmod(all->vect.raycol, full);
	}
	else if (all->vect.raycol < 0)
	{
		all->vect.raycol += full;
	}
}

void
	ft_re_set_variables(t_all *all)
{
	all->vect.fhx = 0;
	all->vect.fhy = 0;
	all->vect.fvx = 0;
	all->vect.fvy = 0;
	all->vect.hx = 0;
	all->vect.hy = 0;
	all->vect.vx = 0;
	all->vect.vy = 0;
	all->vect.hit = 0;
	all->vect.side = 0;
	all->disp.colhei = 0;
	all->vect.distwall = 0;
	all->disp.pixbeg = 0;
	all->disp.pixend = 0;
	all->vect.teta = all->vect.raycol;
}

void
	ft_check_raycol_dir(t_all *all)
{
	if (all->vect.raycol < PI / 2 && all->vect.raycol >= 0.0)
	{
		//printf("NE\n");
		ft_raycol_north_east(all);
	}
	else if (all->vect.raycol > PI / 2 && all->vect.raycol < PI)
	{
		//printf("NW\n");
		ft_raycol_north_west(all);
	}
	else if (all->vect.raycol > PI && all->vect.raycol < PI + PI / 2)
	{
		//printf("SW\n");
		ft_raycol_south_west(all);
	}
	else if (all->vect.raycol > PI + PI / 2 && all->vect.raycol < 2 * PI)
	{
		//printf("SE\n");
		ft_raycol_south_east(all);
	}
	else
	{
		printf("raycol dans crd = %lf\n", all->vect.raycol);
		printf("dir = %lf\n", all->vect.dir);
		ft_raycol_special_cases(all);
	}
}

void
	ft_if_hyph_is_inferior(t_all *all, double *hyph)
{
	if (all->vect.raycol == PI / 2)
		printf("HYP H IS INFERIOR\n");
	if (all->data.map[(int)all->vect.fhy]
	[(int)all->vect.fhx] == '1')
	{
		if (all->vect.raycol == PI / 2)
			printf("HOR TOUCHED\n");
		all->vect.side = 0;
		all->vect.hit = 1;
	}
	else
	{
		if (all->vect.raycol == PI / 2)
			printf("HOR NOT TOUCHED\n");
		all->vect.fhx += all->vect.hx;
		all->vect.fhy += all->vect.hy;
		*hyph += CASE / sin(all->vect.teta);
		if (all->vect.raycol == PI / 2)
		{
			printf("sin = %lf\n", sin(all->vect.teta));
			printf("\nhyph + %lf\n", CASE / sin(all->vect.teta));
		}
	}
}

void
	ft_if_hypv_is_inferior(t_all *all, double *hypv)
{
	if (all->vect.raycol == PI / 2)
		printf("HYP V IS INFERIOR\n");
	if (all->data.map[(int)all->vect.fvy]
	[(int)all->vect.fvx] == '1')
	{
		if (all->vect.raycol == PI / 2)
			printf("VER TOUCHED\n");
		all->vect.side = 1;
		all->vect.hit = 1;
	}
	else
	{
		if (all->vect.raycol == PI / 2)
			printf("VER NOT TOUCHED\n");
		all->vect.fvx += all->vect.vx;
		all->vect.fvy += all->vect.vy;
		*hypv += CASE / cos(all->vect.teta);
		if (all->vect.raycol == PI / 2)
		{
			printf("cos = %lf\n", cos(all->vect.teta));
			printf("\nhypv + %lf\n", CASE / cos(all->vect.teta));
		}
	}
}
