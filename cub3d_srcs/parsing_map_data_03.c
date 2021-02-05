/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_data_03.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:04:45 by sachouam          #+#    #+#             */
/*   Updated: 2021/02/05 03:30:19 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

int
	ft_parse_tab_pos_play(t_all *all)
{
	int i;
	int j;

	i = -1;
	while (all->data.map[++i])
	{
		j = -1;
		while (all->data.map[i][++j])
		{
			if (all->data.map[i][j] == 'N'
			|| all->data.map[i][j] == 'S'
			|| all->data.map[i][j] == 'E'
			|| all->data.map[i][j] == 'W')
			{
				all->data.posplay = all->data.map[i][j];
				all->vect.posx = j + 0.5;
				all->vect.posy = i + 0.5;
				return (1);
			}
		}
	}
	return (0);
}

void
	ft_set_dir_and_angle(t_all *all)
{
	if (all->data.posplay == 'N')
		all->vect.dir = PI / 2;
	else if (all->data.posplay == 'S')
		all->vect.dir = PI + (PI / 2);
	else if (all->data.posplay == 'E')
		all->vect.dir = 0.0;
	else if (all->data.posplay == 'W')
		all->vect.dir = PI;
}

int
	ft_check_arguments(char *arg1, char *arg2)
{
	int i;

	i = 0;
	while (arg1[i] && arg1[i] != '.')
		i++;
	if (ft_strncmp(arg1 + (i + 1), "cub", 4))
	{
		ft_error_message("wrong file extension\n");
		return (0);
	}
	if (arg2)
		if (ft_strncmp(arg2, "--save", 7))
		{
			ft_error_message("wrong second argument\n");
			return (0);
		}
	return (1);
}
