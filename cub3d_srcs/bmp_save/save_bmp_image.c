/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:26:35 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/24 16:13:18 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

static void
	ft_shift_int(t_bmp *bmp, unsigned int value)
{
	bmp->buffer[bmp->i++] = value >> 0;
	bmp->buffer[bmp->i++] = value >> 8;
	bmp->buffer[bmp->i++] = value >> 16;
	bmp->buffer[bmp->i++] = value >> 24;
}

static void
	ft_fill_bmp_header(t_bmp *bmp)
{
	bmp->buffer[bmp->i++] = 'B';
	bmp->buffer[bmp->i++] = 'M';
	ft_shift_int(bmp, bmp->size);
	ft_shift_int(bmp, 0x00000000);
	bmp->buffer[bmp->i++] = 54;
	bmp->buffer[bmp->i++] = 0;
	bmp->buffer[bmp->i++] = 0;
	bmp->buffer[bmp->i++] = 0;
}

static void
	ft_fill_bmp_info(t_all *all, t_bmp *bmp)
{
	int i;

	bmp->buffer[bmp->i++] = 40;
	bmp->buffer[bmp->i++] = 0;
	bmp->buffer[bmp->i++] = 0;
	bmp->buffer[bmp->i++] = 0;
	ft_shift_int(bmp, all->data.reswid);
	ft_shift_int(bmp, all->data.reshei);
	bmp->buffer[bmp->i++] = 1;
	bmp->buffer[bmp->i++] = 0;
	bmp->buffer[bmp->i++] = 24;
	bmp->buffer[bmp->i++] = 0;
	i = -1;
	while (++i < 24)
		bmp->buffer[bmp->i++] = 0;
}

static void
	ft_fill_bmp_with_pixels(t_all *all, t_bmp *bmp)
{
	int x;
	int y;

	y = all->data.reshei;
	while (--y >= 0)
	{
		x = -1;
		while (++x < (int)all->data.reswid)
		{
			bmp->buffer[bmp->i++] =
			all->disp.addr[y * all->data.reswid + x] >> 0;
			bmp->buffer[bmp->i++] =
			all->disp.addr[y * all->data.reswid + x] >> 8;
			bmp->buffer[bmp->i++] =
			all->disp.addr[y * all->data.reswid + x] >> 16;
		}
	}
}

int
	ft_save_bmp_image(t_all *all, char *filename)
{
	t_bmp	bmp;
	int		fd;

	ft_bzero(&bmp, sizeof(t_bmp));
	bmp.size = 54 + (3 * all->data.reswid * all->data.reshei);
	if (!(bmp.buffer = malloc(sizeof(char) * bmp.size)))
		return (0);
	if ((fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 00700)) == -1)
		return (0);
	ft_fill_bmp_header(&bmp);
	ft_fill_bmp_info(all, &bmp);
	ft_fill_bmp_with_pixels(all, &bmp);
	if (write(fd, bmp.buffer, bmp.size) == -1)
		return (0);
	free(bmp.buffer);
	close(fd);
	return (1);
}
