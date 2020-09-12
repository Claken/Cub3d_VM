/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 01:00:57 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/05 15:56:42 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/cub3d.h"

static void		ft_set_variables_raycasting(int x, t_all *all)
{
	all->vect.camx = 2 * x / (double)all->data.reso1 - 1;
	all->vect.raydirx = all->vect.dirx + all->vect.planex * all->vect.camx;
	all->vect.raydiry = all->vect.diry + all->vect.planey * all->vect.camx;
	all->vect.mapx = (int)all->vect.posx;
	all->vect.mapy = (int)all->vect.posy;
	all->vect.deltadistx = fabs(1 / all->vect.raydirx);
	all->vect.deltadisty = fabs(1 / all->vect.raydiry);
	all->vect.sidedistx = 0;
	all->vect.sidedisty = 0;
	all->vect.walldist = 0;
	all->vect.stepx = 0;
	all->vect.stepy = 0;
	all->vect.hit = 0;
	all->vect.side = 0;
	all->disp.lh = 0;
	all->disp.pixbeg = 0;
	all->disp.pixend = 0;
}

static void		ft_set_steps_and_sideDist(t_all *all)
{
	if (all->vect.raydiry < 0)
	{
		all->vect.stepx = -1;
		all->vect.sidedistx = (all->vect.posx
		- all->vect.mapx) * all->vect.deltadistx;
	}
	else
	{
		all->vect.stepx = 1;
		all->vect.sidedistx = (all->vect.mapx + 1.0
		- all->vect.posx) * all->vect.deltadistx;
	}
	if (all->vect.raydiry < 0)
	{
		all->vect.stepy = -1;
		all->vect.sidedisty = (all->vect.posy
		- all->vect.mapy) * all->vect.deltadisty;
	}
	else
	{
		all->vect.stepy = 1;
		all->vect.sidedisty = (all->vect.mapy + 1.0
		- all->vect.posy) * all->vect.deltadisty;
	}
}

static void		ft_dda_and_ray_calculation(t_all *all)
{
	while (all->vect.hit == 0)
	{
		if (all->vect.sidedistx < all->vect.sidedisty)
		{
			all->vect.sidedistx += all->vect.deltadistx;
			all->vect.mapx += all->vect.stepx;
			all->vect.side = 0;
		}
		else
		{
			all->vect.sidedisty += all->vect.deltadisty;
			all->vect.mapy += all->vect.stepy;
			all->vect.side = 1;
		}
		if (all->cub.map[all->vect.mapx][all->vect.mapy] > '0')
			all->vect.hit = 1;
	}
	if (all->vect.side == 0)
		all->vect.walldist = (all->vect.mapx - all->vect.posx
		+ (1 - all->vect.stepx) / 2) / all->vect.raydirx;
	else
		all->vect.walldist = (all->vect.mapy - all->vect.posy
		+ (1 - all->vect.stepy) / 2) / all->vect.raydiry;
}

static void		ft_drawing(int x, t_all *all)
{
	int		i;
	char	*dst;

	all->disp.lh = (int)(all->data.reso2 / all->vect.walldist);
	all->disp.pixbeg = (-all->disp.lh / 2) + (all->data.reso2 / 2);
	if (all->disp.pixbeg < 0)
		all->disp.pixbeg = 0;
	all->disp.pixend = (all->disp.lh / 2) + (all->data.reso2 / 2);
	if (all->disp.pixend >= (int)all->data.reso2)
		all->disp.pixend = all->data.reso2 - 1;
	all->disp.color = 0x0000FF00;
	if (all->vect.side == 1)
		all->disp.color /= 2;
	i = all->disp.pixbeg;
	while (i < all->disp.pixend)
	{
		dst = all->disp.addr + (i * all->disp.ll + x * (all->disp.bpp / 8));
		*(unsigned int*)dst = all->disp.color;
		i++;
	}
}

void			ft_raycasting(t_all *all)
{
	int x;

	all->vect.time = 0;
	all->vect.prevtime = 0;
	x = 0;
	while (x < (int)all->data.reso1)
	{
		ft_set_variables_raycasting(x, all);
		ft_set_steps_and_sideDist(all);
		ft_dda_and_ray_calculation(all);
		ft_drawing(x, all);
		x++;
	}
}
:wq
