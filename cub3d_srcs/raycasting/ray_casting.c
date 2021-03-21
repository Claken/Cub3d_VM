/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:28:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/21 18:28:40 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

static void
	ft_check_raycol_value(t_all *all)
{
	double full;

	full = ft_degree_to_radian(360);
	if (all->vect.raycol > full)
		all->vect.raycol = fmod(all->vect.raycol, full);
	else if (all->vect.raycol < 0)
		all->vect.raycol += full;
}

static void
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
	all->vect.side = 0;
	all->disp.colhei = 0;
	all->vect.distwall = 0;
	all->disp.pixbeg = 0;
	all->disp.pixend = 0;
	all->vect.teta = all->vect.raycol;
}

static void
	ft_raycol_dir(t_all *all)
{
	int direction;

	direction = ft_check_raycol_direction(all);
	if (direction == 1)
		ft_raycol_north_east(all);
	else if (direction == 2)
		ft_raycol_north_west(all);
	else if (direction == 3)
		ft_raycol_south_west(all);
	else if (direction == 4)
		ft_raycol_south_east(all);
	else
		ft_raycol_special_cases(all, direction);
}

static void
	ft_drawing_column(t_all *all, int i)
{
	int j;

	all->disp.colhei = (CASE / all->vect.nofisheye) * all->vect.distscreen;
	all->disp.pixbeg = -all->disp.colhei / 2 + all->data.reshei / 2;
	if (all->disp.pixbeg < 0)
		all->disp.pixbeg = -1;
	all->disp.pixend = all->disp.colhei / 2 + all->data.reshei / 2;
	if (all->disp.pixend >= (int)all->data.reshei)
		all->disp.pixend = all->data.reshei - 1;
	all->disp.color = ft_get_color(220, 220, 220);
	if (all->vect.side == 2 || all->vect.side == 4)
		all->disp.color /= 2;
	j = all->disp.pixbeg;
	while (j++ < all->disp.pixend)
		ft_draw_pixel(all, j, i);
}

void
	ft_raycasting(t_all *all)
{
	int i;

	i = -1;
	all->vect.modxl = fmod(all->vect.posx, 1);
	all->vect.modyu = fmod(all->vect.posy, 1);
	all->vect.raycol = all->vect.dir + (all->vect.fov / 2);
	//all->vect.index = i;
	//while (++all->vect.index < (int)all->data.reswid)
	while (++i < (int)all->data.reswid)
	{
		ft_check_raycol_value(all);
		ft_re_set_variables(all);
		ft_raycol_dir(all);
		ft_check_for_walls(all);
		ft_distance_calculation(all);
		ft_distance_with_no_fisheye(all);
		//i = all->vect.index;
		ft_drawing_column(all, i);
//		printf_distances(i, all);
		all->vect.raycol -= all->vect.apr;
	}
}
