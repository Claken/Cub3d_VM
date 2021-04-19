/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:44:07 by sachouam          #+#    #+#             */
/*   Updated: 2019/11/18 22:29:04 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s || !(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	if (start < (unsigned int)ft_strlen(s))
		while (i < len && s[i + start])
		{
			substr[i] = s[i + start];
			i++;
		}
	substr[i] = '\0';
	return (substr);
}

static char		*ft_concatenate(char const *s1, char const *s2, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	if (!s1 && s2)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2 && s1)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str = ft_concatenate(s1, s2, str);
	return (str);
}
