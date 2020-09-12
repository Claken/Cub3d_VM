/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 00:50:40 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/01 18:30:52 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

/*
static int	ft_test(t_all *all)
{
	mlx_put_image_to_window(all->disp.mlx_ptr,
	all->disp.windo, all->disp.img, 0, 0);
	return (0);
}
*/

int		ft_window_and_image(t_all *all)
{
	if (!(all->disp.windo = mlx_new_window(all->disp.mlx_ptr,
			all->data.reswid, all->data.reshei, "Cub3D")))
		return (0);
	if (!(all->disp.img = mlx_new_image(all->disp.mlx_ptr,
			all->data.reswid, all->data.reshei)))
		return (0);
	if (!(all->disp.addr = (int *)mlx_get_data_addr(all->disp.img,
			&all->disp.bpp, &all->disp.ll, &all->disp.endian)))
		return (0);
	return (1);
}
/*
void		ft_hooks_and_loops(t_all *all)
{
	mlx_hook(all->disp.windo, KP, (1L << 0),
	&ft_key_management, all);
	mlx_hook(all->disp.windo, DN, (1L << 17),
	&ft_abort_mission, all);
	//mlx_loop_hook(all->disp.mlx_ptr, &ft_test, all);
	mlx_loop(all->disp.mlx_ptr);
}
*/
void		ft_recreate_image(t_all *all)
{
	ft_draw_ceil_and_floor(all);
	ft_raycasting(all);
	mlx_put_image_to_window(all->disp.mlx_ptr,
	all->disp.windo, all->disp.img, 0, 0);
}
