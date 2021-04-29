/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:41:03 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/29 03:33:37 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_includes/cub3d.h"

static int
	ft_check_first_or_last(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0'
		|| line[i] == '2')
			return (0);
		i++;
	}
	return (1);
}

static int
	ft_check_beginning_and_end(char *line)
{
	int i;

	i = 0;
	if (line[0] == '0'
	|| line[0] == '2')
		return (0);
	while (line[i])
		i++;
	--i;
	if (line[i] == '0'
	|| line[i] == '2')
		return (0);
	return (1);
}

static void
	ft_check_spaces_between_char(t_all *all, int y, int x)
{
	if ((y > 0 && ft_strlen(all->data.map[y - 1]) - 1 < x)
	|| (all->data.map[y + 1] != 0
	&& ft_strlen(all->data.map[y + 1]) - 1 < x))
		ft_error_so_exit("the map is not closed (special case)\n", all);
	if ((all->data.map[y][x + 1]
	&& all->data.map[y][x + 1] == ' ')
	|| (x > 0 && all->data.map[y][x - 1] == ' ')
	|| (y > 0 && all->data.map[y - 1][x] == ' ')
	|| (all->data.map[y + 1] != 0
	&& all->data.map[y + 1][x] == ' '))
		ft_error_so_exit("the map is not closed : space near floor\n", all);
}

void
	ft_check_walls(t_all *all)
{
	int j;
	int i;

	j = -1;
	if (!(ft_check_first_or_last(all->data.map[0])))
		ft_error_so_exit("the map is not closed (first line)\n", all);
	while (all->data.map[++j])
	{
		if (!(ft_check_beginning_and_end(all->data.map[j])))
			ft_error_so_exit("the map is not closed (side.s)\n", all);
		i = -1;
		while (all->data.map[j][++i])
			if (all->data.map[j][i] == '0'
			|| all->data.map[j][i] == '2')
				ft_check_spaces_between_char(all, j, i);
	}
	if (!ft_check_first_or_last(all->data.map[--j]))
		ft_error_so_exit("the map is not closed (last line)\n", all);
}
