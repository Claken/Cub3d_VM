/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:48:43 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/24 19:51:56 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

// parcourir la longueur et la largeur de la texture ?
// if size = n, appeler fonction avec texture n ?
// utiliser pixend ? pixbeg ? colhei ?

static void
	ft_test_text_map(t_all *all, int index,
	t_images *texture)
{
	int x = 0;
	int y = 0;
	int i;
	static int j = -1;

	x = index;
	y = all->disp.pixbeg;
	i = 0;
	while (i < texture->height)
	{
		all->disp.addr[y * all->data.reswid + x]
		= texture->addr[i * texture->width + j];
		y++;
		i++;
	}
	if (++j > texture->width)
		j = 0;
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
