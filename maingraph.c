/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maingraph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:10:46 by sachouam          #+#    #+#             */
/*   Updated: 2020/08/13 18:52:02 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (b << 24 | g << 16 | r << 8 | t);
}

int		get_t(int trgb)
{
	return (trgb & 0xFF);
}

int		get_r(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int		get_g(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int		get_b(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

void			my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->disp.addr + (y * all->disp.ll + x * (all->disp.bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

void	init_structs(t_all *all)
{
	ft_bzero(all, sizeof(t_all));
}

void			draw_walls(t_all *all, int ds, int de, int color)
{
	int		i;
	int		x;
	char	*dst; 

	i = ds;
	x = all->vect.posX;
	while (i < de)
	{
		dst = all->disp.addr + (i * all->disp.ll + x * (all->disp.bpp / 8));
		*(unsigned int*)dst = color;
		i++;
	}
}

void			draw_player(t_all *all, int x1, int y1, int color)
{
	int x;
	int y;

	x = x1;
	y = y1;
	
	int i = 0;
	while (i < 5)
	{
		my_mlx_pixel_put(all, x, y++, color); // UTILISER PUT_IMAGE PAS PUT_PIXEL !!!
		i++;
	}
	i = 0;
	while (i < 5)
	{
		my_mlx_pixel_put(all, x++, y, color); // UTILISER PUT_IMAGE PAS PUT_PIXEL !!!
		i++;
	}
	i = 0;
	while (i < 5)
	{
		my_mlx_pixel_put(all, x, y--, color); // UTILISER PUT_IMAGE PAS PUT_PIXEL !!!
		i++;
	}
	i = 0;
	while (i < 5)
	{
		my_mlx_pixel_put(all, x--, y, color); // UTILISER PUT_IMAGE PAS PUT_PIXEL !!!
		i++;
	}
	int j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			my_mlx_pixel_put(all, x, y++, color); // UTILISER PUT_IMAGE PAS PUT_PIXEL !!!
			i++;
		}
		j++;
		x++;
		y -= i;
	}
}

void		ft_tkt_frere(t_all *all)
{
	if (all->disp.img)
		mlx_destroy_image(all->disp.mlx_ptr, all->disp.img);
	all->disp.img = mlx_new_image(all->disp.mlx_ptr, 1920, 1080);
	all->disp.addr = mlx_get_data_addr(all->disp.img, &all->disp.bpp, &all->disp.ll, &all->disp.endian);
	draw_walls(all, 100, 500, all->disp.color);
	mlx_put_image_to_window(all->disp.mlx_ptr, all->disp.windo, all->disp.img, 0, 0);
}

int			ft_close(int key, t_all *all)
{
	printf("%d\n", key);
	if (key == ESC)
	{
		mlx_destroy_window(all->disp.mlx_ptr, all->disp.windo);
		exit(0);
	}
	if (key == UP)
	{
		all->vect.posY -= 10;
		ft_tkt_frere(all);
	}
	if (key == LEFT)
	{
		all->vect.posX -= 10;
		ft_tkt_frere(all);
	}
	if (key == DOWN)
	{
		all->vect.posY += 10;
		ft_tkt_frere(all);
	}
	if (key == RIGHT)
	{
		all->vect.posX += 10;
		ft_tkt_frere(all);
	}
	return (0);
}

int		main(int ac, char **av)
{
	//t_mlx	disp;
	//t_don	image;
	t_all	all;

	init_structs(&all);
	all.disp.color = 0x00FF0000;
	all.vect.posX = 750;
	all.vect.posY = 250;

	if (!(all.disp.mlx_ptr = mlx_init()))
		return (EXIT_FAILURE);
	if (!(all.disp.windo = mlx_new_window(all.disp.mlx_ptr, 1920, 1080, "test")))
		return (EXIT_FAILURE);
	//all.disp.img = mlx_new_image(all.disp.mlx_ptr, 1920, 1080);
	//all.disp.addr = mlx_get_data_addr(all.disp.img, &all.disp.bpp, &all.disp.ll, &all.disp.endian);
	//int t;
	//int g;
	//int r;
	//int b;
	//int tgrb = create_trgb(t, r, g, b);
	//printf("%d\n", tgrb);
	ft_tkt_frere(&all);
	mlx_hook(all.disp.windo, KeyPress, KeyPressMask, &ft_close, &all);
	mlx_loop(all.disp.mlx_ptr);
	//printf("%d\n", image.line_length);
	//free(disp);
	return (0);
}
