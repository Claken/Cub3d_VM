/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 01:59:52 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/26 02:01:25 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_includes/cub3d.h"

int
	ft_check_arguments(char *arg1, char *arg2, t_all *all)
{
	int i;
	char**tab;

	i = 0;
	if (!(tab = ft_split(arg1, ".")))
		return (0);
	while (tab[i])
		i++;
	if (ft_strncmp(tab[i - 1], "cub", 4))
	{
		ft_error_message("wrong path or cub file extension\n");
		ft_free_tab(tab);
		return (0);
	}
	ft_free_tab(tab);
	if (arg2)
	{
		if (ft_strncmp(arg2, "--save", 7))
		{
			ft_error_message("wrong second argument\n");
			return (0);
		}
		all->bmp.save = 1;
	}
	return (1);
}
