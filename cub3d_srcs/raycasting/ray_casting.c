/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:28:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/06 13:55:26 by sachouam         ###   ########.fr       */
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
	all->vect.modxl = fmod(all->vect.posx, 1);
	all->vect.modyu = fmod(all->vect.posy, 1);
	all->vect.raycol = all->vect.dir + (all->vect.fov / 2);
	all->spr.rayx = 0;
	all->spr.j = 0;
	all->spr.begx = 0;
	all->spr.endx = 0;
	while (++i < (int)all->data.reswid)
	{
		ft_check_raycol_value(all);
		ft_re_set_variables(all);
		ft_raycol_dir(all);
		ft_check_for_walls_and_sprites(all, i);
		ft_distance_calculation(all);
		ft_distance_with_no_fisheye(all);
		ft_drawing_column(all, i);
		ft_textures_management(all, i);
		all->vect.raycol -= all->vect.apr;
	}
	ft_sprite_calculations(all);
	ft_sprite_mapping(all);
	/*
	i = -1;
	while (++i < all->spr.j)
		printf("raycol %d = %lf\n", i, all->spr.raycols[i]);
	printf("rayx     %d\n", all->spr.rayx);
	printf("j        %d\n", all->spr.j);
	printf("x        %lf\n", all->spr.x);
	printf("y        %lf\n", all->spr.y);
	printf("posx     %lf\n", all->vect.posx);
	printf("posy     %lf\n", all->vect.posy);
	double xx;
	double yy;
	//double beta;

	xx = all->vect.posx - all->spr.x;
	yy = all->vect.posy - all->spr.y;
	//beta = fabs(all->vect.dir - all->spr.raycols[all->spr.j / 2]);
	//all->spr.distwall = sqrt(pow(xx, 2) + pow(yy, 2));
	printf("distwall %lf\n\n", all->spr.distwall);
	//all->spr.distwall *= cos(beta);
	//printf("distwall %lf\n\n", all->spr.distwall);
	*/
}
