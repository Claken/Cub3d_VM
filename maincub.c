/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maincub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 11:34:38 by sachouam          #+#    #+#             */
/*   Updated: 2020/08/20 03:53:47 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/cub3d.h"

void		init_struct(t_all *all)
{
	ft_bzero(all, sizeof(t_all));
}

int		parsing_r(char *line, t_data *data)
{
	char		**tab;
	unsigned int	i;

	if (!(tab = ft_split(line, " ")))
		return (0);
	i = 0;
	while (tab[i])
		i++;
	if (i == 3)
	{
		data->reswid = ft_atoi(tab[1]);
		data->reshei = ft_atoi(tab[2]);
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (1);
}

int		parsing_fc(char *line, t_data *data, int rc)
{
	char		**tab;
	unsigned int	i;

	if (!(tab = ft_split(line, ", ")))
		return (0);
	if (rc == 1)
	{	
		data->floor1 = ft_atoi(tab[1]);
		data->floor2 = ft_atoi(tab[2]);
		data->floor3 = ft_atoi(tab[3]);
	}
	else if (rc == 2)
	{
		data->ceil1 = ft_atoi(tab[1]);
		data->ceil2 = ft_atoi(tab[2]);
		data->ceil3 = ft_atoi(tab[3]);
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (1);
}

int	parsing_rfc(char *line, t_data *data)
{
	if (line[0] == 'R')
	{
		if (!parsing_r(line, data))
			return (0);
	}
	else if (line[0] == 'F')
	{
		if (!parsing_fc(line, data, 1))
			return (0);
	}
	else if (line[0] == 'C')
	{
		if (!parsing_fc(line, data, 2))
			return (0);
	}
	return (1);
}

int		count_lines_map(int fd, char *line, char *av)
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

char	*one_line_map(char *line)
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

//void    *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);

int		parsing_text(char *line, t_all *all)
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
	return (1);
}

char		**parsing_file_cub(t_all *all, char *file)
{
	char*line;
	int j;
	int count;
	char**map;

	j = 0;
	count = count_lines_map(all->data.fd, line, file);
	printf("count = %d\n", count);
	if (!(map = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while ((get_next_line(all->data.fd, &line)) > 0)
	{
		if (line[0] == 'R' || line[0] == 'F'
		|| line[0] == 'C')
		{
			if (!parsing_rfc(line, &all->data))
				return (NULL);
		}
		else if (line[0] == ' ' || line[0] == '0'
		|| line[0] == '1' || line[0] == '2')
		{
			if (!(map[j] = one_line_map(line)))
				return (NULL);
			j++;
		}
		else if (line[0] == 'N' || line[0] == 'S'
		|| line[0] == 'E' || line[0] == 'W')
		{
			if (!parsing_text(line, all))
				return (NULL);
		}
		free(line);
	}
	map[j] = 0;
	return (map);
}

int			parse_tab_pos_play(t_all *all)
{
	int i;
	int j;

	j = -1;
	while (all->data.map[++j])
	{
		i = -1;
		while (all->data.map[j][++i])
		{
			if (all->data.map[j][i] == 'N' || all->data.map[j][i] == 'S'
			|| all->data.map[j][i] == 'E' || all->data.map[j][i] == 'W')
			{
				all->data.posplay = all->data.map[j][i];
				return (1);
			}
		}
	}
	return (0);
}


static int	check_spaces_in_map(char **map, int j, int i)
{
	int end;

	end = ft_strlen(map[j]) - 1;
	while (map[j][end] == ' ')
		end--;
	while (i <= end)
	{
		if (map[j][i] == ' ')
		{
			if (map[j][i + 1] == '0' ||
				map[j][i - 1] == '0')
				return (0);
			if (map[j - 1])
			{
				if (map[j - 1][i] == '0' ||
				map[j - 1][i + 1] == '0' ||
				map[j - 1][i - 1] == '0')
					return (0);
			}
			if (map[j + 1])
			{
				if (map[j + 1][i] == '0' ||
				map[j + 1][i - 1] == '0' ||
				map[j + 1][i + 1] == '0')
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int			check_walls(char **map)
{
	int i;
	int j;

	j = -1;
	while (map[++j])
	{
		i = 0;
		while (map[j][i] == ' ')
			i++;
		if (!check_spaces_in_map(map, j, i))
			return (0);
		if ((j == 0 || map[j + 1] == 0)
		&& (!ft_strchr(map[j], '1') && !ft_strchr(map[j], ' ')))
			return (0);
		if (map[j][i] != '1' && map[j][i] != ' ')
			return (0);
		i = ft_strlen(map[j]) - 1;
		while (map[j][i] == ' ')
			i--;
		if (map[j][i] != '1')
			return (0);
	}
	return (1);
}

/*
int	ft_check_elements(t_data *data)
{
	if (data->reso1 == 0 || data->reso2 == 0)
		return (0);
	return (1);
}
*/

void	set_direction(t_all *all)
{
	if (all->data.posplay == 'N')
		all->vect.dirx = 1;
	else if (all->data.posplay == 'S')
		all->vect.diry = -1;
	else if (all->data.posplay == 'E')
		all->vect.dirx = 1;
	else if (all->data.posplay == 'W')
		all->vect.dirx = -1;
}

int	main(int ac, char **av)
{
	t_all			all;

	unsigned int	j;
	unsigned int	i;
	init_struct(&all);
	if (!(all.disp.mlx_ptr = mlx_init()))
		return (EXIT_FAILURE);
	all.data.fd = open(av[1], O_RDONLY);
	j = 0;
	if (!(all.data.map = parsing_file_cub(&all, av[1])))
		return (0);
	printf("reso1 = %d\nreso2 = %d\nfloor1 = %d\nfloor2 = %d\nfloor3 = %d\nceil1 = %d\nceil2 = %d\nceil3 = %d\n", all.data.reswid, all.data.reshei, all.data.floor1, all.data.floor2, all.data.floor3, all.data.ceil1, all.data.ceil2, all.data.ceil3);
	printf("n = %d\n", all.text.north.width);
	printf("s = %d\n", all.text.south.width);
	printf("e = %d\n", all.text.east.width);
	printf("w = %d\n", all.text.west.width);
	printf("sp = %d\n", all.text.sprite.width);
	printf("n = %p\n", all.text.north.pict);
	printf("s = %p\n", all.text.south.pict);
	printf("e = %p\n", all.text.east.pict);
	printf("w = %p\n", all.text.west.pict);
	printf("sp = %p\n", all.text.sprite.pict);
	j = 0;
	while (all.data.map[j])
		printf("%s\n", all.data.map[j++]);
	if (parse_tab_pos_play(&all))
		printf("posplay : %c\n", all.data.posplay);
	set_direction(&all);
	printf("dirX : %f\ndirY : %f\n", all.vect.dirx, all.vect.diry);
	if (!check_walls(all.data.map))
		printf("error\n");
	close(all.data.fd);
	j = 0;
	while (all.data.map[j])
		free(all.data.map[j++]);
	free(all.data.map);
	return (0);
}
