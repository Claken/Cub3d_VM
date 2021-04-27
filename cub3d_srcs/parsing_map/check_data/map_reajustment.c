/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reajustment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:32:56 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/27 18:34:00 by sachouam         ###   ########.fr       */
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

void
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
