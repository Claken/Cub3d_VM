/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:28:24 by sachouam          #+#    #+#             */
/*   Updated: 2020/12/29 19:16:50 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

void
	ft_error_message(char *sentence)
{
	ft_putstr_fd("Error : ", STDERR_FILENO);
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
