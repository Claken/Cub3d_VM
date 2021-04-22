/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:05:40 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/22 13:53:36 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

void
	ft_sprites_management(t_all *all)
{
	t_sprite *svg;

	ft_check_sprites_on_the_map(all);
	svg = all->sprites;
	ft_sort_sprites(&all->sprites);
	while (all->sprites)
	{
		ft_sprite_calculations(all, &all->sprites);
		ft_sprite_mapping(all, all->sprites);
		all->sprites = all->sprites->next;
	}
	all->sprites = svg;
	ft_sprclear(&all->sprites);
}
