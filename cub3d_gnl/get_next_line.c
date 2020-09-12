/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:43:58 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/04 18:40:19 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int		ft_buffer_to_str(char **str, char *buffer)
{
	char *tmp;

	tmp = NULL;
	if (!*str)
	{
		if (!(*str = ft_substr2(buffer, 0, ft_strlen2(buffer))))
			return (0);
	}
	else if (*str)
	{
		tmp = *str;
		if (!(*str = ft_strjoin2(*str, buffer)))
			return (0);
		free(tmp);
		tmp = NULL;
	}
	return (1);
}

static char		*ft_one_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str && str[i] != '\n' && str[i])
		i++;
	if (!str || !(line = (malloc(sizeof(char) * (i + 1)))))
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char		*ft_next_line(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i])
		i++;
	tmp = str;
	if (!(str = ft_substr2(str, i, ft_strlen2(str))))
		return (NULL);
	free(tmp);
	tmp = NULL;
	return (str);
}

static int		ft_end_of_file(char **str, int byte)
{
	if (byte == 0 && !ft_strchr2(*str, '\n'))
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int			byte;
	char			buffer[BUFFER_SIZE + 1];
	static char		*str = NULL;

	if (fd < 0 || !line || BUFFER_SIZE == 0)
		return (-1);
	byte = 1;
	while (!ft_strchr2(str, '\n') && byte > 0)
	{
		if ((byte = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[byte] = '\0';
		if (!ft_buffer_to_str(&str, buffer))
			return (-1);
	}
	if (!(*line = ft_one_line(str)))
		return (-1);
	if (!(str = ft_next_line(str)))
		return (-1);
	if (ft_end_of_file(&str, byte))
		return (0);
	return (1);
}
