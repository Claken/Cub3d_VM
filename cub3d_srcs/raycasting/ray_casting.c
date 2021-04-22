/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:28:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/22 13:11:17 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

static void
	ft_check_raycol_value(t_all *all)
{
	double full;

	full = ft_degree_to_radian(360);
	if (all->angle.raycol > full)
		all->angle.raycol = fmod(all->angle.raycol, full);
	else if (all->angle.raycol < 0)
		all->angle.raycol += full;
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
	all->angle.teta = 0;
	all->disp.pixbeg = 0;
	all->disp.pixend = 0;
	all->angle.teta = all->angle.raycol;
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

	all->disp.colhei = (CASE / all->calcul.nofisheye) * all->calcul.distscreen;
	all->disp.pixbeg = -all->disp.colhei / 2 + all->data.reshei / 2;
	if (all->disp.pixbeg < 0)
		all->disp.pixbeg = 0;
	all->disp.pixend = all->disp.colhei / 2 + all->data.reshei / 2;
	if (all->disp.pixend >= (int)all->data.reshei)
		all->disp.pixend = all->data.reshei - 1;
	all->disp.color = ft_get_color(220, 220, 220);
	if (all->vect.side == 2 || all->vect.side == 4)
		all->disp.color /= 2;
	j = all->disp.pixbeg;
	while (j < all->disp.pixend)
	{
		ft_draw_pixel(all, j, i);
		j++;
	}
}

void
	ft_raycasting(t_all *all)
{
	int i;

	i = -1;
	all->calcul.modxl = fmod(all->vect.posx, 1);
	all->calcul.modyu = fmod(all->vect.posy, 1);
	all->angle.raycol = all->angle.dir + (all->angle.fov / 2);
	if (!(all->distwalls = malloc(sizeof(double) * all->data.reswid)))
		return ;
	all->sprites = NULL;
	while (++i < (int)all->data.reswid)
	{
		ft_check_raycol_value(all);
		ft_re_set_variables(all);
		ft_raycol_dir(all);
		ft_check_for_walls(all);
		ft_distance_calculation(all);
		ft_distance_with_no_fisheye(all);
		all->distwalls[i] = all->calcul.nofisheye;
		ft_drawing_column(all, i);
		ft_textures_management(all, i);
		all->angle.raycol -= all->angle.apr;
	}
}
