/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:41:53 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/22 18:40:06 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

int
	ft_loop_hook(t_all *all)
{
	ft_key_management(all);
	ft_create_image(all);
	return (0);
}

int
	ft_window_and_image(t_all *all)
{
	if (!all->bmp.save)
		if (!(all->disp.windo = mlx_new_window(all->disp.mlx_ptr,
		all->data.reswid, all->data.reshei, "Cub3D")))
			return (0);
	if (!(all->disp.img = mlx_new_image(all->disp.mlx_ptr,
	all->data.reswid, all->data.reshei)))
		return (0);
	if (!(all->disp.addr = (int *)mlx_get_data_addr(all->disp.img,
	&all->disp.bpp, &all->disp.linelen, &all->disp.endian)))
		return (0);
	return (1);
}

void
	ft_hooks_and_loops(t_all *all)
{
	mlx_hook(all->disp.windo, KP, (1L << 0), &ft_key_pressed, all);
	mlx_hook(all->disp.windo, KR, (1L << 1), &ft_key_released, all);
	mlx_hook(all->disp.windo, DN, (1L << 17), &ft_good_bye, all);
	mlx_loop_hook(all->disp.mlx_ptr, &ft_loop_hook, all);
	mlx_loop(all->disp.mlx_ptr);
}

void
	ft_create_image(t_all *all)
{
	ft_draw_ceil_and_floor(all);
	ft_raycasting(all);
	ft_sprites_management(all);
	if (!all->bmp.save)
		mlx_put_image_to_window(all->disp.mlx_ptr,
		all->disp.windo, all->disp.img, 0, 0);
}
