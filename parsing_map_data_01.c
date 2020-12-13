/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_data_01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:27:43 by sachouam          #+#    #+#             */
/*   Updated: 2020/12/12 23:57:39 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int
	ft_count_lines_map(int fd, char *line, char *av)
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

static char
	*ft_one_line_map(char *line)
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

static void
	ft_parsing_text(char *line, t_all *all)
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

static int
	ft_ifs_for_parsing(char *line, t_all *all, char **map, int *j)
{
	if (line[0] == 'R' || line[0] == 'F' || line[0] == 'C')
	{
		if (!ft_parsing_rfc(line, all))
			return (0);
	}
	else if (line[0] == ' ' || line[0] == '0'
	|| line[0] == '1' || line[0] == '2')
	{
		if (!(map[*j] = ft_one_line_map(line)))
			return (0);
		*j += 1;
	}
	else if (line[0] == 'N' || line[0] == 'S'
	|| line[0] == 'E' || line[0] == 'W')
	{
		ft_parsing_text(line, all);
	}
	return (1);
}

char
	**ft_parsing_file_cub(t_all *all, char *file)
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
		if (!ft_ifs_for_parsing(line, all, map, &j))
			return (NULL);
		free(line);
	}
	map[j] = 0;
	return (map);
}
