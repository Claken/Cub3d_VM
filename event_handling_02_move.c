/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling_02_move.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 00:45:36 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/05 12:53:03 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_move_forward(t_all *all)
{
	//(void)all;
	//all->vect.posx += ft_set_cos(all);
	//all->vect.posy += ft_set_sin(all);
	all->vect.posx += cos(all->vect.dir);
	all->vect.posy += sin(all->vect.dir);
	ft_recreate_image(all);
}

void	ft_move_to_the_left(t_all *all)
{
	//(void)all;
	all->vect.dir += (PI + (PI / 2));
	all->vect.posx += cos(all->vect.dir);
	all->vect.posy += sin(all->vect.dir);
	all->vect.dir -= (PI + (PI / 2));
	ft_recreate_image(all);
}

void	ft_move_backwards(t_all *all)
{
	//(void)all;
	all->vect.dir += PI;
	all->vect.posx += cos(all->vect.dir);
	all->vect.posy += sin(all->vect.dir);
	all->vect.dir -= PI;
	ft_recreate_image(all);
}

void	ft_move_to_the_right(t_all *all)
{
	//(void)all;
	all->vect.dir += (PI / 2);
	all->vect.posx += cos(all->vect.dir);
	all->vect.posy += sin(all->vect.dir);
	all->vect.dir -= (PI / 2);
	ft_recreate_image(all);
}
