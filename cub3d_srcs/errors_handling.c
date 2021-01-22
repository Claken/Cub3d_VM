/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:28:24 by sachouam          #+#    #+#             */
/*   Updated: 2021/01/22 22:52:32 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

void
	ft_error_message(char *sentence)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(sentence, STDERR_FILENO);
}

int
	ft_error_so_exit(char *sentence, t_all *all)
{
	ft_abort_mission(all);
	ft_error_message(sentence);
	exit(EXIT_FAILURE);
	return (0);
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
