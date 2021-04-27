/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 02:27:06 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/27 18:40:54 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_includes/cub3d.h"

static void
	ft_check_ids_in_file_cub(t_all *all)
{
	if (all->data.rescount > 1)
		ft_error_so_exit("'R' ID appears more than once\n", all);
	if (all->data.flocount > 1)
		ft_error_so_exit("'F' ID appears more than once\n", all);
	if (all->data.ceicount > 1)
		ft_error_so_exit("'C' ID appears more than once\n", all);
	if (all->image.north.imgcount > 1)
		ft_error_so_exit("'NO' ID appears more than once\n", all);
	if (all->image.south.imgcount > 1)
		ft_error_so_exit("'SO' ID appears more than once\n", all);
	if (all->image.east.imgcount > 1)
		ft_error_so_exit("'EA' ID appears more than once\n", all);
	if (all->image.west.imgcount > 1)
		ft_error_so_exit("'WE' ID appears more than once\n", all);
	if (all->image.sprite.imgcount > 1)
		ft_error_so_exit("'S' ID appears more than once\n", all);
}

static void
	ft_check_images(t_all *all)
{
	int		i;
	int		j;
	char	**tab;
	t_images*tmp;

	i = 0;
	while (i < NTXT)
	{
		j = 0;
		tmp = &((t_images *)(&all->image))[i++];
		if (tmp->path == NULL)
			ft_error_so_exit("image(s) missing\n", all);
		if (!(tab = ft_split(tmp->path, ".")))
			return ;
		while (tab[j])
			j++;
		if (ft_strncmp(tab[j - 1], "xpm", 4))
		{
			ft_free_tab(tab);
			ft_error_so_exit("wrong path or xpm file extension\n", all);
		}
		ft_free_tab(tab);
	}
}

static int
	ft_check_fc_colors(int r, int g, int b)
{
	if ((r < 0 || 255 < r)
	|| (g < 0 || 255 < g)
	|| (b < 0 || 255 < b))
		return (0);
	return (1);
}

static void
	ft_check_map_characters(t_all *all)
{
	int i;
	int j;

	i = -1;
	while (all->data.map[++i])
	{
		j = -1;
		while (all->data.map[i][++j])
		{
			if (all->data.map[i][j] != '0' && all->data.map[i][j] != '1'
			&& all->data.map[i][j] != '2' && all->data.map[i][j] != 'N'
			&& all->data.map[i][j] != 'S' && all->data.map[i][j] != 'E'
			&& all->data.map[i][j] != 'W' && all->data.map[i][j] != ' '
			&& all->data.map[i][j] != '\n')
				ft_error_so_exit("wrong character(s) in the map\n", all);
		}
	}
}

void
	ft_check_cub_data(t_all *all)
{
	if (all->data.uncorrectid)
		ft_error_so_exit("incorrect ID in the file\n", all);
	ft_check_ids_in_file_cub(all);
	if (all->data.reswid <= 0 || all->data.reshei <= 0)
		ft_error_so_exit("resolution(s) missing\n", all);
	ft_check_images(all);
	if (!ft_check_fc_colors(all->data.floor1,
	all->data.floor2, all->data.floor3)
	|| !ft_check_fc_colors(all->data.ceil1,
	all->data.ceil2, all->data.ceil3))
		ft_error_so_exit("wrong data for the color(s)\n", all);
	ft_check_map_characters(all);
	ft_reajust_map_lines(all);
	ft_check_walls(all);
}
