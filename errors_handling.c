/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:28:24 by sachouam          #+#    #+#             */
/*   Updated: 2020/12/14 22:53:22 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int
	ft_error_so_exit(char *sentence, t_all *all)
{
	ft_abort_mission(all);
	ft_putstr_fd("Error : ", STDERR_FILENO);
	ft_putstr_fd(sentence, STDERR_FILENO);
	exit(EXIT_FAILURE);
	return (0);
}
