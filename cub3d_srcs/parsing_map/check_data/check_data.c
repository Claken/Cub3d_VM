/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 02:27:06 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/22 17:48:13 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_includes/cub3d.h"

int
	ft_check_arguments(char *arg1, char *arg2, t_all *all)
{
	int i;
	char**tab;

	i = 0;
	if (!(tab = ft_split(arg1, ".")))
		return (0);
	while (tab[i])
		i++;
	if (ft_strncmp(tab[i - 1], "cub", 4))
	{
		ft_error_message("wrong path or cub file extension\n");
		ft_free_tab(tab);
		return (0);
	}
	ft_free_tab(tab);
	if (arg2)
	{
		if (ft_strncmp(arg2, "--save", 7))
		{
			ft_error_message("wrong second argument\n");
			return (0);
		}
		all->bmp.save = 1;
	}
	return (1);
}

static void
	ft_check_images(t_all *all)
{
	int		i;
	int		j;
	char		**tab;
	t_images	*tmp;

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
	if (all->data.reswid <= 0 || all->data.reshei <= 0)
		ft_error_so_exit("resolution(s) missing\n", all);
	ft_check_images(all);
	if (!ft_check_fc_colors(all->data.floor1,
	all->data.floor2, all->data.floor3)
	|| !ft_check_fc_colors(all->data.ceil1,
	all->data.ceil2, all->data.ceil3))
		ft_error_so_exit("wrong data for the color(s)\n", all);
	ft_check_map_characters(all);
	ft_check_walls(all);
}
