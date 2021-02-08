/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_get_data_02.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 02:26:00 by sachouam          #+#    #+#             */
/*   Updated: 2021/02/08 18:17:33 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

static int
	ft_parsing_r(char *line, t_all *all)
{
	char**tab;
	int i;

	mlx_get_screen_size(all->disp.mlx_ptr,
	(int *)&all->data.sizex, (int *)&all->data.sizey);
	if (!(tab = ft_split(line, " ")))
		return (0);
	i = 0;
	while (tab[i])
		i++;
	if (i == 3)
	{
		all->data.reswid = ft_atoi(tab[1]);
		all->data.reshei = ft_atoi(tab[2]);
	}
	if (all->data.reswid > all->data.sizex
	|| all->data.reshei > all->data.sizey)
	{
		all->data.reswid = all->data.sizex;
		all->data.reshei = all->data.sizey;
	}
	ft_free_tab(tab);
	return (1);
}

static int
	ft_parsing_fc(char *line, t_all *all, int rc)
{
	int i;
	char**tab;

	i = 0;
	if (!(tab = ft_split(line, ", ")))
		return (0);
	while (tab[i])
		i++;
	if (i == 4)
	{
		if (rc == 1)
		{
			all->data.floor1 = ft_atoi(tab[1]);
			all->data.floor2 = ft_atoi(tab[2]);
			all->data.floor3 = ft_atoi(tab[3]);
		}
		else if (rc == 2)
		{
			all->data.ceil1 = ft_atoi(tab[1]);
			all->data.ceil2 = ft_atoi(tab[2]);
			all->data.ceil3 = ft_atoi(tab[3]);
		}
	}
	ft_free_tab(tab);
	return (1);
}

int
	ft_parsing_rfc(char *line, t_all *all)
{
	if (line[0] == 'R')
	{
		if (!ft_parsing_r(line, all))
			return (0);
	}
	else if (line[0] == 'F')
	{
		if (!ft_parsing_fc(line, all, 1))
			return (0);
	}
	else if (line[0] == 'C')
	{
		if (!ft_parsing_fc(line, all, 2))
			return (0);
	}
	return (1);
}
