/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:26:35 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/12 13:46:24 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

static void
	ft_write_int(t_bmp *bmp, unsigned int value)
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
	ft_write_int(bmp, bmp->size);
	ft_write_int(bmp, 0x00000000);
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
	ft_write_int(bmp, all->data.reswid);
	ft_write_int(bmp, all->data.reshei);
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
			bmp->buffer[bmp->i++] = all->disp.addr[y * all->data.reswid + x] >> 0;
			bmp->buffer[bmp->i++] = all->disp.addr[y * all->data.reswid + x] >> 8;
			bmp->buffer[bmp->i++] = all->disp.addr[y * all->data.reswid + x] >> 16;
		}
		x = -1;
		while (++x < (int)((4 - (all->data.reswid * 3) % 4) % 4))
			bmp->buffer[bmp->i++] = 0;
	}
}

int
	ft_save_bmp_image(t_all *all, char *filename)
{
	int	fd;
	t_bmp	bmp;

	ft_bzero(&bmp, sizeof(t_bmp));
	bmp.size = 54 + (3 * all->data.reswid * all->data.reshei) +
	(((4 - (all->data.reswid * 3) % 4) % 4) * all->data.reshei);
	if (!(bmp.buffer = malloc(sizeof(char) * bmp.size)))
		return (0);
	if ((fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC)) < 0)
		return (0);
	ft_fill_bmp_header(&bmp);
	ft_fill_bmp_info(all, &bmp);
	ft_fill_bmp_with_pixels(all, &bmp);
	write(fd, bmp.buffer, bmp.size);
	free(bmp.buffer);
	close(fd);
	return (1);
}

