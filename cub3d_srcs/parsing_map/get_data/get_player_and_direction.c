/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_and_direction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:50:42 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/16 19:21:55 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_includes/cub3d.h"

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
		all->angle.dir = PI / 2;
	else if (all->data.posplay == 'S')
		all->angle.dir = PI + (PI / 2);
	else if (all->data.posplay == 'E')
		all->angle.dir = 0.0;
	else if (all->data.posplay == 'W')
		all->angle.dir = PI;
}
