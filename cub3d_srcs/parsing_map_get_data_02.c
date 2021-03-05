/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_get_data_02.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:49:49 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/05 15:49:51 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

static void
	ft_parsing_text_path(char *line, t_all *all)
{
	char **tab;

	if (!(tab = ft_split(line, " ")))
		return ;
	if (tab[1])
	{
		if (ft_strncmp(line, "NO", 2) == 0)
			all->text.north.path = ft_strdup(tab[1]);
		else if (ft_strncmp(line, "SO", 2) == 0)
			all->text.south.path = ft_strdup(tab[1]);
		else if (ft_strncmp(line, "WE", 2) == 0)
			all->text.west.path = ft_strdup(tab[1]);
		else if (ft_strncmp(line, "EA", 2) == 0)
			all->text.east.path = ft_strdup(tab[1]);
		else if (*line == 'S')
			all->text.sprite.path = ft_strdup(tab[1]);
	}
	ft_free_tab(tab);
}

void
	ft_parsing_text(char *line, t_all *all)
{
	ft_parsing_text_path(line, all);
	if (ft_strncmp(line, "NO", 2) == 0)
		all->text.north.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
		all->text.north.path, &all->text.north.width, &all->text.north.height);
	else if (ft_strncmp(line, "SO", 2) == 0)
		all->text.south.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
		all->text.south.path, &all->text.south.width, &all->text.south.height);
	else if (ft_strncmp(line, "WE", 2) == 0)
		all->text.west.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
		all->text.west.path, &all->text.west.width, &all->text.west.height);
	else if (ft_strncmp(line, "EA", 2) == 0)
		all->text.east.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
		all->text.east.path, &all->text.east.width, &all->text.east.height);
	else if (*line == 'S')
		all->text.sprite.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
		all->text.sprite.path, &all->text.sprite.width,
		&all->text.sprite.height);
}
