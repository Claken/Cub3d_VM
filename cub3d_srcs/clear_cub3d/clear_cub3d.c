/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 05:27:32 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/19 17:17:56 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

void
	ft_free_all(t_all *all)
{
	int j;

	j = 0;
	while (all->data.map[j])
		free(all->data.map[j++]);
	free(all->data.map);
	close(all->data.fd);
}

void
	ft_destroy_images(t_all *all)
{
	int		i;
	t_texture	*tmp;

	i = 0;
	tmp = NULL;
	while (i < NTXT)
	{
		tmp = &((t_texture *)(&all->text))[i];
		if (tmp != NULL && tmp->pict != NULL)
			mlx_destroy_image(all->disp.mlx_ptr, tmp->pict);
		if (tmp->path)
			free(tmp->path);
		i++;
	}
}

void
	ft_abort_mission(t_all *all)
{
	if (all->data.map)
		ft_free_all(all);
	ft_destroy_images(all);
	if (all->disp.img)
		mlx_destroy_image(all->disp.mlx_ptr, all->disp.img);
	if (all->disp.windo)
		mlx_destroy_window(all->disp.mlx_ptr, all->disp.windo);
}
