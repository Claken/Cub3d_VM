/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:53:05 by sachouam          #+#    #+#             */
/*   Updated: 2021/02/06 17:35:01 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

void
	ft_init_structs(t_all *all)
{
	ft_bzero(all, sizeof(t_all));
}

static void
	ft_set_variables(t_all *all)
{
	all->vect.fov = ft_degree_to_radian(FOV);
	ft_set_dir_and_angle(all);
	all->vect.distscreen = (all->data.reswid / 2)
	/ tan(all->vect.fov / 2);
	all->vect.raycol = all->vect.dir + (all->vect.fov / 2);
	all->vect.apr = all->vect.fov / all->data.reswid;
}

int
	main(int ac, char **av)
{
	t_all all;

	if (!ft_check_arguments(ac, av[1], av[2]))
		return (0);
	ft_init_structs(&all);
	all.data.fd = open(av[1], O_RDONLY);
	if (!(all.disp.mlx_ptr = mlx_init()))
		return (EXIT_FAILURE);
	if (!(all.data.map = ft_parsing_file_cub(&all, av[1])))
		return (0);
	ft_check_cub_data(&all);
	if (!ft_window_and_image(&all))
		return (EXIT_FAILURE);
	if (!ft_parse_tab_pos_play(&all))
		return (ft_error_so_exit("no player on the map\n", &all));
	ft_set_variables(&all);
	ft_create_image(&all);
	ft_hooks_and_loops(&all);
	return (0);
}
