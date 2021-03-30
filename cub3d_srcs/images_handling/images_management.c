/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:48:43 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/30 23:30:48 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

static void
	ft_texture_mapping(t_all *all, int x, t_images *texture)
{
	int	y;
	double	i;
	double	texty;
	double	textx;

	if (all->disp.pixbeg < 0)
		y = 0;
	else
		y = all->disp.pixbeg;
	i = (double)texture->height / (double)all->disp.colhei;
	texty = (y - (all->data.reshei / 2 - all->disp.colhei / 2)) * i;
	if (all->vect.side == 2 || all->vect.side == 4)
		textx = texture->width * fmod(all->vect.fvy, CASE);
	else if (all->vect.side == 1 || all->vect.side == 3)
		textx = texture->width * fmod(all->vect.fhx, CASE);
	while (y <= all->disp.pixend)
	{
		all->disp.color = texture->addr[(int)texty
		* texture->width + (int)textx];
		all->disp.addr[y * all->data.reswid + x] = all->disp.color;
		texty += i;
		y++;
	}
}

static void
	ft_text_according_to_side(t_all *all, int index)
{
	if (all->vect.side == 1)
		ft_texture_mapping(all, index, &all->image.north);
	else if (all->vect.side == 2)
		ft_texture_mapping(all, index, &all->image.east);
	else if (all->vect.side == 3)
		ft_texture_mapping(all, index, &all->image.south);
	else if (all->vect.side == 4)
		ft_texture_mapping(all, index, &all->image.west);
}

void
	ft_textures_management(t_all *all, int index)
{
	ft_text_according_to_side(all, index);
}
