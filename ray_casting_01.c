/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:28:55 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/11 23:53:48 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	ft_re_set_variables(t_all *all)
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

static void	ft_check_raycol_dir(t_all *all, double modx, double mody)
{
	if (all->vect.raycol < PI / 2 && all->vect.raycol > 0)
	{
		ft_raycol_north_east(all, modx, mody);
	}
	else if (all->vect.raycol > PI / 2 && all->vect.raycol < PI)
	{
		ft_raycol_north_west(all, modx, mody);
	}
	else if (all->vect.raycol > PI && all->vect.raycol < PI + PI / 2)
	{
		ft_raycol_south_west(all, modx, mody);
	}
	else if (all->vect.raycol > PI + PI / 2)
	{
		ft_raycol_south_east(all, modx, mody);
	}
	else
	{
		ft_check_raycol_dir_part_two(all, modx, mody);
	}
}

static void	ft_check_for_walls(t_all *all, double modx, double mody)
{
	double hyph;
	double hypv;

	hyph = ft_set_hyph(all, mody);
	hypv = ft_set_hypv(all, modx);
	//printf("hyph %lf, hypv %lf\n", hyph, hypv);
	while (!all->vect.hit) // RAJOUTER UNE CONDITION SI SEGFAULT ICI
	{
		//printf("fhy %lf, fhx %lf\n", all->vect.fhy, all->vect.fhx);
		//printf("fvy %lf, fvx %lf\n", all->vect.fvy, all->vect.fvx);
		if (hyph < hypv)
		{
			//printf("hyph %lf, hypv %lf\n", hyph, hypv);
			if (all->data.map[(int)all->vect.fhy][(int)all->vect.fhx] == '1')
			{
				all->vect.side = 0;
				all->vect.hit = 1;
				//printf("UN\n");
			}
			else
			{
				all->vect.fhx += all->vect.hx;
				all->vect.fhy += all->vect.hy;
				hyph += CASE / sin(all->vect.teta);
				//printf("DEUX\n");
			}
		}
		else
		{
			if (all->data.map[(int)all->vect.fvy][(int)all->vect.fvx] == '1')
			{
				all->vect.side = 1;
				all->vect.hit = 1;
				//printf("TROIS\n");
			}
			else
			{
				all->vect.fvx += all->vect.vx;
				all->vect.fvy += all->vect.vy;
				hypv += CASE / cos(all->vect.teta);
				//printf("QUATRE\n");
			}
		}
	}
}

static void	ft_distance_calculation(t_all *all)
{
	if (!all->vect.side)
	{
		all->vect.distwall = fabs(((all->vect.posx - all->vect.fhx)
		/ cos(all->vect.raycol)));
	}
	else
	{
		all->vect.distwall = fabs(((all->vect.posy - all->vect.fvy)
		/ sin(all->vect.raycol)));
	}
}

static void	ft_drawing_column(t_all *all, int i)
{
	int j;

	all->disp.colhei = (CASE / all->vect.distwall)
	* all->vect.distscreen;
	all->disp.pixbeg = -all->disp.colhei
	/ 2 + all->data.reshei / 2;
	if (all->disp.pixbeg < 0)
		all->disp.pixbeg = 0;
	all->disp.pixend = all->disp.colhei
	/ 2 + all->data.reshei / 2;
	if (all->disp.pixend >= (int)all->data.reshei)
		all->disp.pixend = all->data.reshei - 1;
	all->disp.color = ft_get_color(220, 220, 220);
	if (all->vect.side)
		all->disp.color /= 2;
	j = all->disp.pixbeg;
	while (j++ < all->disp.pixend)
		ft_draw_pixel(all, j, i);
}

void		ft_raycasting(t_all *all)
{
	int i;
	double modx;
	double mody;

	i = -1;
	modx = fmod(all->vect.posx, 1);
	mody = fmod(all->vect.posy, 1);
	all->vect.raycol = all->vect.dir + (all->vect.fov / 2);
	while (++i < (int)all->data.reswid)
	{
		ft_check_raycol_value(all);
		ft_re_set_variables(all);
		ft_check_raycol_dir(all, modx, mody);
		ft_check_for_walls(all, modx, mody);
		ft_distance_calculation(all);
		ft_drawing_column(all, i);
		all->vect.raycol -= all->vect.apr;
	}
}
