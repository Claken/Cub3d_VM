/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_data_03.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:04:45 by sachouam          #+#    #+#             */
/*   Updated: 2021/01/22 18:27:38 by sachouam         ###   ########.fr       */
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
/*
static int
	ft_check_spaces_in_map(char **map, int j, int i)
{
	int end;

	end = ft_strlen(map[j]) - 1;
	while (map[j][end] == ' ')
		end--;
	while (i <= end)
	{
		if (map[j][i] == ' ')
		{
			if (map[j][i + 1] == '0' ||
			map[j][i - 1] == '0')
				return (0);
			if (map[j - 1])
			{
				if (map[j - 1][i] == '0' ||
				map[j - 1][i + 1] == '0' ||
				map[j - 1][i - 1] == '0')
					return (0);
			}
			if (map[j + 1])
			{
				if (map[j + 1][i] == '0' ||
				map[j + 1][i - 1] == '0' ||
				map[j + 1][i + 1] == '0')
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int
	ft_check_walls(char **map)
{
	int i;
	int j;

	j = -1;
	while (map[++j])
	{
		i = 0;
		while (map[j][i] == ' ')
			i++;
		if (!ft_check_spaces_in_map(map, j, i))
			return (0);
		if ((j == 0 || map[j + 1] == 0)
		&& (!ft_strchr(map[j], '1') && !ft_strchr(map[j], ' ')))
			return (0);
		if (map[j][i] != '1' && map[j][i] != ' ')
			return (0);
		i = ft_strlen(map[j]) - 1;
		while (map[j][i] == ' ')
			i--;
		if (map[j][i] != '1')
			return (0);
	}
	return (1);
}
*/
