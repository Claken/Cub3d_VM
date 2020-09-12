/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 17:56:15 by sachouam          #+#    #+#             */
/*   Updated: 2020/08/20 04:00:25 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int	ft_parsing_r(char *line, t_all *all)
{
	char		**tab;
	unsigned int	i;

	mlx_get_screen_size(all->disp.mlx_ptr,
	(int *)&all->data.sizex, (int *)&all->data.sizey);
	if (!(tab = ft_split(line, " ")))
		return (0);
	i = 0;
	while (tab[i])
		i++;
	if (i == 3)
	{
		all->data.reswid = ft_atoi(tab[1]);
		all->data.reshei = ft_atoi(tab[2]);
	}
	if (all->data.reswid > all->data.sizex
	|| all->data.reshei > all->data.sizey)
	{
		all->data.reswid = all->data.sizex;
		all->data.reshei = all->data.sizey;
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (1);
}

static int	ft_parsing_fc(char *line, t_all *all, int rc)
{
	char		**tab;
	unsigned int	i;

	if (!(tab = ft_split(line, ", ")))
		return (0);
	if (rc == 1)
	{
		all->data.floor1 = ft_atoi(tab[1]);
		all->data.floor2 = ft_atoi(tab[2]);
		all->data.floor3 = ft_atoi(tab[3]);
	}
	else if (rc == 2)
	{
		all->data.ceil1 = ft_atoi(tab[1]);
		all->data.ceil2 = ft_atoi(tab[2]);
		all->data.ceil3 = ft_atoi(tab[3]);
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (1);
}

static int	ft_parsing_rfc(char *line, t_all *all)
{
	if (line[0] == 'R')
	{
		if (!ft_parsing_r(line, all))
			return (0);
	}
	else if (line[0] == 'F')
	{
		if (!ft_parsing_fc(line, all, 1))
			return (0);
	}
	else if (line[0] == 'C')
	{
		if (!ft_parsing_fc(line, all, 2))
			return (0);
	}
	return (1);
}

static int	ft_count_lines_map(int fd, char *line, char *av)
{
	int i;

	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (line[0] == ' ' || line[0] == '0'
		|| line[0] == '1' || line[0] == '2')
			i++;
		free(line);
	}
	close(fd);
	free(line);
	fd = open(av, O_RDONLY);
	return (i);
}

static char	*ft_one_line_map(char *line)
{
	char*oneline;
	int i;

	if (!(oneline = malloc(sizeof(char) * (ft_strlen(line) + 1))))
		return (NULL);
	i = 0;
	while (line[i])
	{
		oneline[i] = line[i];
		i++;
	}
	oneline[i] = '\0';
	return (oneline);
}

static void	ft_parsing_text(char *line, t_all *all)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		all->text.north.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
			line + 3, &all->text.north.width, &all->text.north.height);
	else if (ft_strncmp(line, "SO", 2) == 0)
		all->text.south.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
			line + 3, &all->text.south.width, &all->text.south.height);
	else if (ft_strncmp(line, "WE", 2) == 0)
		all->text.west.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
			line + 3, &all->text.west.width, &all->text.west.height);
	else if (ft_strncmp(line, "EA", 2) == 0)
		all->text.east.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
			line + 3, &all->text.east.width, &all->text.east.height);
	else if (*line == 'S')
		all->text.sprite.pict = mlx_xpm_file_to_image(all->disp.mlx_ptr,
			line + 2, &all->text.sprite.width, &all->text.sprite.height);
}

char		**ft_parsing_file_cub(t_all *all, char *file)
{
	char*line;
	int j;
	int count;
	char**map;

	line = NULL;
	j = 0;
	count = ft_count_lines_map(all->data.fd, line, file);
	if (!(map = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while ((get_next_line(all->data.fd, &line)) > 0)
	{
		if (line[0] == 'R' || line[0] == 'F'
		|| line[0] == 'C')
		{
			if (!ft_parsing_rfc(line, all))
				return (NULL);
		}
		else if (line[0] == ' ' || line[0] == '0'
		|| line[0] == '1' || line[0] == '2')
		{
			if (!(map[j] = ft_one_line_map(line)))
				return (NULL);
			j++;
		}
		else if (line[0] == 'N' || line[0] == 'S'
		|| line[0] == 'E' || line[0] == 'W')
		{
			ft_parsing_text(line, all);
		}
		free(line);
	}
	map[j] = 0;
	return (map);
}
