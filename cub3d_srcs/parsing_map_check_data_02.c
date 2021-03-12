/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_check_data_02.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:41:03 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/07 19:56:06 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

void
	ft_check_walls(t_all *all)
{
	int j;
	int len;

	j = -1;
	while (all->data.map[++j])
	{
		if (j == 0)
		{
			len = ft_strlen(all->data.map[j]);
			if (!(ft_check_first_or_last(all->data.map[j])))
				ft_error_so_exit("the map is not closed (first line)\n", all);
		}
		if (ft_strlen(all->data.map[j]) > len)
			ft_error_so_exit("line too long\nparsing cannot be done properly\n"
			, all);
		if (j > 0)
			if (!(ft_check_beginning_and_end(all->data.map[j])))
				ft_error_so_exit("the map is not closed (side.s)\n", all);
	}
	if (!ft_check_first_or_last(all->data.map[--j]))
		ft_error_so_exit("the map is not closed (last line)\n", all);
}
