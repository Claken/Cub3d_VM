/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:53:05 by sachouam          #+#    #+#             */
/*   Updated: 2020/09/01 18:32:08 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

// DOIT ETRE COMPATIBLE AVEC LA VM ET MAC EN MEME TEMPS : ADAPTER AUX DEUX
// REFRESH QUAND TU MINIMISES LA FENETRE : PAS DE BLACK SCREEN QUAND TU DEMINIMISES

void		ft_init_structs(t_all *all)
{
	ft_bzero(all, sizeof(t_all));
}

void		ft_free_all(t_all *all)
{
	int j;

	j = 0;
	while (all->data.map[j])
		free(all->data.map[j++]);
	free(all->data.map);
	close(all->data.fd);
}

static void	ft_set_variables(t_all *all)
{
	all->vect.fov = ft_degree_to_radian(FOV);
	ft_set_dir_and_angle(all);
	all->vect.distscreen = (all->data.reswid / 2)
	/ tan(all->vect.fov / 2);
	all->vect.raycol = all->vect.dir + (all->vect.fov / 2);
	all->vect.apr = all->vect.fov / all->data.reswid;
}

/*
static int	ft_test(t_all *all)
{
	mlx_put_image_to_window(all->disp.mlx_ptr,
	all->disp.windo, all->disp.img, 0, 0);
	return (0);
}
*/

int		main(int ac, char **av)
{
	t_all	all;

	if (ac < 2)
		return (0);
	ft_init_structs(&all);
	all.data.fd = open(av[1], O_RDONLY);
	if (!(all.disp.mlx_ptr = mlx_init()))
		return (EXIT_FAILURE);
	if (!(all.data.map = ft_parsing_file_cub(&all, av[1])))
		return (0);
	if (!ft_window_and_image(&all))
		return (EXIT_FAILURE);
	if (!ft_parse_tab_pos_play(&all))
		return (0);
	ft_set_variables(&all);
	ft_draw_ceil_and_floor(&all);
	ft_raycasting(&all);
	mlx_put_image_to_window(all.disp.mlx_ptr,
	all.disp.windo, all.disp.img, 0, 0);
	mlx_hook(all.disp.windo, KP, (1L << 0),
	&ft_key_management, &all);
	mlx_hook(all.disp.windo, DN, (1L << 17),
	&ft_abort_mission, &all);
	mlx_loop(all.disp.mlx_ptr);
	return (0);
}
