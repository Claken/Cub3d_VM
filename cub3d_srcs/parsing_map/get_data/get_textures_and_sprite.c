/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_and_sprite.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:49:49 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/26 01:13:19 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_includes/cub3d.h"

static void
	ft_get_one_image_datas(t_all *all, char *tab, t_images *img)
{
	int fd;

	if (!img->imgcount)
	{
		if ((fd = open(tab, O_RDONLY)) == -1)
			img->path = NULL;
		else
			img->path = ft_strdup(tab);
		close(fd);
		img->pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
		img->path, &img->width, &img->height);
		if (img->pict)
			img->addr = (int *)mlx_get_data_addr(img->pict,
			&img->bpp, &img->linelen, &img->endian);
	}
	img->imgcount++;
}

void
	ft_parsing_image(char *line, t_all *all)
{
	char **tab;

	if (!(tab = ft_split(line, " ")))
		return ;
	if (tab[1])
	{
		if (ft_strncmp(line, "NO", 3) == 32)
			ft_get_one_image_datas(all, tab[1], &all->image.north);
		else if (ft_strncmp(line, "SO", 3) == 32)
			ft_get_one_image_datas(all, tab[1], &all->image.south);
		else if (ft_strncmp(line, "WE", 3) == 32)
			ft_get_one_image_datas(all, tab[1], &all->image.west);
		else if (ft_strncmp(line, "EA", 3) == 32)
			ft_get_one_image_datas(all, tab[1], &all->image.east);
		else if (ft_strncmp(line, "S", 2) == 32)
			ft_get_one_image_datas(all, tab[1], &all->image.sprite);
	}
	ft_free_tab(tab);
}
