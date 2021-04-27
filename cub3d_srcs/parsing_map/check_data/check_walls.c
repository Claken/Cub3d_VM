/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:41:03 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/27 18:34:32 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_includes/cub3d.h"

void
	ft_check_walls(t_all *all)
{
	int j;

	j = -1;
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
