/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_check_data_01.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 02:27:06 by sachouam          #+#    #+#             */
/*   Updated: 2021/02/06 23:43:46 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

int
	ft_check_arguments(int ac, char *arg1, char *arg2)
{
	int i;
	char**tab;

	if (ac < 2 || ac > 3)
	{
		ft_error_message("wrong number of arguments\n");
		return (0);
	}
	i = 0;
	if (!(tab = ft_split(arg1, ".")))
		return (0);
	while (tab[i])
		i++;
	if (ft_strncmp(tab[i - 1], "cub", 4))
	{
		ft_error_message("wrong cub file extension\n");
		ft_free_tab(tab);
		return (0);
	}
	ft_free_tab(tab);
	if (arg2 && ft_strncmp(arg2, "--save", 7))
	{
		ft_error_message("wrong second argument\n");
		return (0);
	}
	return (1);
}

static void
	ft_check_images(t_all *all)
{
	int		i;
	int		j;
	t_texture	*tmp;
	char		**tab;

	i = 0;
	while (i < NTXT)
	{
		j = 0;
		tmp = &((t_texture *)(&all->text))[i++];
		if (tmp->path == NULL)
			ft_error_so_exit("texture(s) missing\n", all);
		if (!(tab = ft_split(tmp->path, ".")))
			return ;
		while (tab[j])
			j++;
		if (ft_strncmp(tab[j - 1], "xpm", 4))
		{
			ft_free_tab(tab);
			ft_error_so_exit("wrong xpm file extension\n", all);
		}
		ft_free_tab(tab);
	}
}

void
	ft_check_cub_data(t_all *all)
{
	if (all->data.reswid == 0 || all->data.reshei == 0)
		ft_error_so_exit("resolution(s) missing\n", all);
	ft_check_images(all);
}
