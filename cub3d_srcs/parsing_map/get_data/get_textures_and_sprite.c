/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_and_sprite.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:49:49 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/22 13:41:28 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_includes/cub3d.h"

static void
	ft_get_images_addr(t_all *all)
{
	int	i;
	t_images*tmp;

	i = -1;
	tmp = NULL;
	while (++i < NTXT)
	{
		tmp = &((t_images *)(&all->image))[i];
		if (tmp->pict)
			tmp->addr = (int *)mlx_get_data_addr(tmp->pict,
			&tmp->bpp, &tmp->linelen, &tmp->endian);
	}
}

static void
	ft_get_images_path(char *line, t_all *all)
{
	char **tab;

	if (!(tab = ft_split(line, " ")))
		return ;
	if (tab[1])
	{
		if (ft_strncmp(line, "NO", 2) == 0)
			all->image.north.path = ft_strdup(tab[1]);
		else if (ft_strncmp(line, "SO", 2) == 0)
			all->image.south.path = ft_strdup(tab[1]);
		else if (ft_strncmp(line, "WE", 2) == 0)
			all->image.west.path = ft_strdup(tab[1]);
		else if (ft_strncmp(line, "EA", 2) == 0)
			all->image.east.path = ft_strdup(tab[1]);
		else if (*line == 'S')
			all->image.sprite.path = ft_strdup(tab[1]);
	}
	ft_free_tab(tab);
}

static void
	ft_get_images(char *line, t_all *all)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		all->image.north.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
		all->image.north.path, &all->image.north.width,
		&all->image.north.height);
	else if (ft_strncmp(line, "SO", 2) == 0)
		all->image.south.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
		all->image.south.path, &all->image.south.width,
		&all->image.south.height);
	else if (ft_strncmp(line, "WE", 2) == 0)
		all->image.west.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
		all->image.west.path, &all->image.west.width, &all->image.west.height);
	else if (ft_strncmp(line, "EA", 2) == 0)
		all->image.east.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
		all->image.east.path, &all->image.east.width, &all->image.east.height);
	else if (*line == 'S')
		all->image.sprite.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
		all->image.sprite.path, &all->image.sprite.width,
		&all->image.sprite.height);
}

void
	ft_parsing_image(char *line, t_all *all)
{
	ft_get_images_path(line, all);
	ft_get_images(line, all);
	ft_get_images_addr(all);
}
