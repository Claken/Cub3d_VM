/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:41:03 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/27 17:31:05 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_includes/cub3d.h"

static int
	ft_get_longest_line_length(t_all *all)
{
	int len;
	int j;

	len = ft_strlen(all->data.map[0]);
	j = -1;
	while (all->data.map[++j])
	{
		if (ft_strlen(all->data.map[j]) > len)
			len = ft_strlen(all->data.map[j]);
	}
	return (len);
}

static void
	ft_reajust_map_lines(t_all *all)
{
	int len;
	int j;
	int i;

	len = ft_get_longest_line_length(all);
	j = -1;
	while (all->data.map[++j])
	{
		if (ft_strlen(all->data.map[j]) < len)
		{
			i = 0;
			while (all->data.map[j][i])
				i++;
			all->data.map[j] = ft_reset_line_size(all->data.map[j],
			len, i);
		}
	}
}

void
	ft_check_walls(t_all *all)
{
	int j;

	j = -1;
	ft_reajust_map_lines(all);
	if (!(ft_check_first_or_last(all->data.map[0])))
		ft_error_so_exit("the map is not closed (first line)\n", all);
	while (all->data.map[++j])
	{
		if (!(ft_check_beginning_and_end(all->data.map[j])))
			ft_error_so_exit("the map is not closed (side.s)\n", all);
	}
	if (!ft_check_first_or_last(all->data.map[--j]))
		ft_error_so_exit("the map is not closed (last line)\n", all);
}
