/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res_flo_and_ceil.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:50:03 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/01 18:03:57 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_includes/cub3d.h"

static int
	ft_check_tab(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (!ft_isdigit(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

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
	if (i == 3 && ft_check_tab(tab[1])
	&& ft_check_tab(tab[2]))
	{
		all->data.reswid = ft_atoi(tab[1]);
		all->data.reshei = ft_atoi(tab[2]);
		if (all->data.reswid > all->data.sizex
		|| all->data.reshei > all->data.sizey)
		{
			all->data.reswid = all->data.sizex;
			all->data.reshei = all->data.sizey;
		}
	}
	ft_free_tab(tab);
	return (1);
}

static int
	ft_parsing_f(char *line, t_all *all)
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
		if (ft_check_tab(tab[1]))
			all->data.floor1 = ft_atoi(tab[1]);
		if (ft_check_tab(tab[2]))
			all->data.floor2 = ft_atoi(tab[2]);
		if (ft_check_tab((tab[3])))
			all->data.floor3 = ft_atoi(tab[3]);
	}
	ft_free_tab(tab);
	return (1);
}

static int
	ft_parsing_c(char *line, t_all *all)
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
		if (ft_check_tab(tab[1]))
			all->data.ceil1 = ft_atoi(tab[1]);
		if (ft_check_tab(tab[2]))
			all->data.ceil2 = ft_atoi(tab[2]);
		if (ft_check_tab(tab[3]))
			all->data.ceil3 = ft_atoi(tab[3]);
	}
	ft_free_tab(tab);
	return (1);
}

int
	ft_parsing_rfc(char *line, t_all *all)
{
	if (ft_strncmp(line, "R", 2) == 32)
	{
		if (!ft_parsing_r(line, all))
			return (0);
		all->data.rescount++;
	}
	if (ft_strncmp(line, "F", 2) == 32)
	{
		if (!ft_parsing_f(line, all))
			return (0);
		all->data.flocount++;
	}
	if (ft_strncmp(line, "C", 2) == 32)
	{
		if (!ft_parsing_c(line, all))
			return (0);
		all->data.ceicount++;
	}
	return (1);
}
