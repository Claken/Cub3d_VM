/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_map_parsing.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:38:54 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/19 20:06:53 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_includes/cub3d.h"

char
	*ft_replace_in_str(char *str, char a, char b)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			str[i] = b;
		i++;
	}
	return (str);
}

void
	*ft_realloc(void *ptr, size_t size)
{
	char *new;

	new = NULL;
	if (ptr && !size)
	{
		if (!(new = malloc(sizeof(char) * 1)))
			return (NULL);
		free(ptr);
	}
	else if (ptr && size)
	{
		if (!(new = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		ft_memcpy(new, ptr, ft_strlen(ptr));
		free(ptr);
	}
	return ((void *)new);
}

char
	*ft_reset_line_size(char *line, int size, int i)
{
	char *new;

	if (!(new = (void*)ft_realloc((char*)line, size)))
		return (0);
	while (i < size)
		new[i++] = '1';
	new[i] = '\0';
	return (new);
}

int
	ft_check_first_or_last(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int
	ft_check_beginning_and_end(char *line)
{
	int i;

	i = 0;
	if (line[0] != '1')
		return (0);
	while (line[i])
		i++;
	if (line[--i] != '1')
		return (0);
	return (1);
}
