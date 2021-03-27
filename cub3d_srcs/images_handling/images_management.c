/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:48:43 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/28 00:23:35 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

// parcourir la longueur et la largeur de la texture ?
// if size = n, appeler fonction avec texture n ?
// utiliser pixend ? pixbeg ? colhei ?

static void
	ft_test_text_map(t_all *all, int x,
	t_images *texture)
{
	int y;
	int k;
	double i;
	double test;

	y = all->disp.pixbeg;
	k = -1;
	i = 0;
	test = 1 / ((double)all->disp.colhei / (double)texture->height);
	//if (all->vect.side == 2
	//|| all->vect.side == 4)
	//{
		static double j = 0;
		//if (j == 0)
		//{
			//printf("colhei %d\n", all->disp.colhei);
			//printf("text height %d\n", texture->height);
			//printf("div %lf\n", (double)all->disp.colhei / (double)texture->height);
			//printf("test %lf\n", test);
		//}
			//printf("colhei %d\n", all->disp.colhei);
		while (++k <= all->disp.colhei)
		{
			all->disp.addr[y * all->data.reswid + x]
			= texture->addr[(int)i * texture->width + (int)j];
			y++;
			i += test;
		}
		j += test;
		if ((int)j > texture->width)
			j = 0;
	//}
}

static void
	ft_text_according_to_side(t_all *all, int index)
{
	if (all->vect.side == 1)
		ft_test_text_map(all, index, &all->image.north);
	else if (all->vect.side == 2)
		ft_test_text_map(all, index, &all->image.east);
	else if (all->vect.side == 3)
		ft_test_text_map(all, index, &all->image.south);
	else if (all->vect.side == 4)
		ft_test_text_map(all, index, &all->image.west);
}

void
	ft_textures_management(t_all *all, int index)
{
	ft_text_according_to_side(all, index);
}
