/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:53:05 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/27 18:44:34 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

void
	ft_init_structs(t_all *all)
{
	ft_bzero(all, sizeof(t_all));
	all->data.floor1 = -1;
	all->data.floor2 = -1;
	all->data.floor3 = -1;
	all->data.ceil1 = -1;
	all->data.ceil2 = -1;
	all->data.ceil3 = -1;
}

static int
	ft_about_arguments(int ac, char **av, t_all *all)
{
	if (ac < 2 || ac > 3)
	{
		ft_error_message("wrong number of arguments\n");
		return (0);
	}
	if (!ft_check_arguments(av[1], av[2], all))
		return (0);
	return (1);
}

static void
	ft_set_variables(t_all *all)
{
	all->angle.fov = ft_degree_to_radian(FOV);
	ft_set_dir_and_angle(all);
	all->calcul.distscreen = (all->data.reswid / 2)
	/ tan(all->angle.fov / 2);
	all->angle.raycol = all->angle.dir + (all->angle.fov / 2);
	all->angle.apr = all->angle.fov / all->data.reswid;
}

int
	main(int ac, char **av)
{
	t_all all;

	ft_init_structs(&all);
	if (!ft_about_arguments(ac, av, &all))
		return (0);
	if ((all.data.fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	if (!(all.disp.mlx_ptr = mlx_init()))
		return (EXIT_FAILURE);
	if (!(all.data.map = ft_parsing_file_cub(&all, av[1])))
		return (0);
	ft_check_cub_data(&all);
	if (!ft_parse_tab_pos_play(&all))
		return (ft_error_so_exit("no player on the map\n", &all));
	if (all.data.playercount > 1)
		return (ft_error_so_exit("put just one player on the map\n", &all));
	if (!ft_window_and_image(&all))
		return (EXIT_FAILURE);
	ft_set_variables(&all);
	ft_create_image(&all);
	if (all.bmp.save)
		if (ft_save_bmp_image(&all, "first_image.bmp"))
			return (ft_good_bye(&all));
	ft_hooks_and_loops(&all);
	return (0);
}
