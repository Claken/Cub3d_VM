/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:36:48 by sachouam          #+#    #+#             */
/*   Updated: 2021/04/24 16:51:05 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_char_in_charset(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_copy_case_tab(char *str, char *charset)
{
	int i;
	char*tab;

	i = 0;
	while (!(ft_char_in_charset(str[i], charset)) && str[i])
		i++;
	if (!(tab = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (!(ft_char_in_charset(str[i], charset)) && str[i])
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int		ft_count_words(char *str, char *charset)
{
	int nb;
	int	i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (!(ft_char_in_charset(str[i], charset)))
		{
			nb++;
			while (!(ft_char_in_charset(str[i], charset)) && str[i])
				i++;
		}
		else
			i++;
	}
	return (nb);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		nb;
	int		i;
	int		j;

	nb = ft_count_words(str, charset);
	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	while (str[i])
	{
		if (!(ft_char_in_charset(str[i], charset)))
		{
			if (!(tab[j] = ft_copy_case_tab(str + i, charset)))
				return (NULL);
			while (!(ft_char_in_charset(str[i], charset)) && str[i])
				i++;
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}
