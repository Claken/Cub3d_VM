/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:48:43 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/28 01:08:07 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

// parcourir la longueur et la largeur de la texture ?
// if size = n, appeler fonction avec texture n ?
// utiliser pixend ? pixbeg ? colhei ?

static void
	ft_test_text_map(t_all *all, int x, t_images *texture)
{
	int y;
	double i;
	double j;
	double test;

	y = all->disp.pixbeg - 1;
	i = 0;
	if (all->vect.side == 2 || all->vect.side == 4)
		j = texture->width * fmod(all->vect.fvy, CASE);
	else if (all->vect.side == 1 || all->vect.side == 3)
		j = texture->width * fmod(all->vect.fhx, CASE);
	test = 1 / ((double)all->disp.colhei / (double)texture->height);
	while (++y <= all->disp.pixend)
	{
		all->disp.addr[y * all->data.reswid + x]
		= texture->addr[(int)i * texture->width + (int)j];
		i += test;
	}
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
