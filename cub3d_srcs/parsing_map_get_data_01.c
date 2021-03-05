/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_get_data_01.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:48:30 by sachouam          #+#    #+#             */
/*   Updated: 2021/03/05 15:48:32 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_includes/cub3d.h"

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
	*ft_one_line_map(char *line, int size)
{
	char*oneline;
	int i;
	int len;

	len = ft_strlen(line);
	if (!(oneline = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (line[++i])
		oneline[i] = line[i];
	oneline[i] = '\0';
	oneline = ft_replace_in_str(oneline, ' ', '1');
	if (len < size)
		oneline = ft_reset_line_size(oneline, size, i);
	return (oneline);
}

static int
	ft_ifs_for_parsing(char *line, t_all *all, char **map, int *j)
{
	static int size;

	if (*j == 0)
		size = ft_strlen(line);
	if (line[0] == 'R' || line[0] == 'F' || line[0] == 'C')
	{
		if (!ft_parsing_rfc(line, all))
			return (0);
	}
	else if (line[0] == ' ' || line[0] == '0'
	|| line[0] == '1' || line[0] == '2')
	{
		if (!(map[*j] = ft_one_line_map(line, size)))
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
