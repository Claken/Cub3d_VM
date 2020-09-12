/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:31:21 by sachouam          #+#    #+#             */
/*   Updated: 2019/10/24 15:31:47 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_skip_beg(char const *s1, char const *set)
{
	int i;
	int k;

	i = 0;
	while (s1[i])
	{
		k = 0;
		while (set[k] && s1[i] != set[k])
			k++;
		if (set[k] == '\0')
			break ;
		i++;
	}
	return (i);
}

static int		ft_skip_end(int i, char const *s1, char const *set)
{
	int j;
	int k;

	j = 0;
	while (s1[j])
		j++;
	j--;
	while (s1[j] != s1[i] && j > 0)
	{
		k = 0;
		while (set[k] && s1[j] != set[k])
			k++;
		if (set[k] == '\0')
			break ;
		j--;
	}
	return (j);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*newstr;

	if (!s1 || !set)
		return (NULL);
	i = ft_skip_beg(s1, set);
	j = 0;
	k = ft_skip_end(i, s1, set);
	l = 0;
	while (i++ <= k)
		l++;
	i = ft_skip_beg(s1, set);
	if (!(newstr = malloc(sizeof(char) * (l + 1))))
		return (NULL);
	while (i <= k)
		newstr[j++] = s1[i++];
	newstr[j] = '\0';
	return (newstr);
}
