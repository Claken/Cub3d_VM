/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:30:30 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/26 02:31:16 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

char			*ft_strjoin_char(char *s1, char s2)
{
	char			*cat;
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	if (!(cat = malloc(sizeof(char) *
	(ft_strlen(s1) + 2))))
		return (NULL);
	while (s1[i])
	{
		cat[n] = s1[i];
		i++;
		n++;
	}
	cat[n] = s2;
	free(s1);
	cat[n + 1] = '\0';
	return (cat);
}

char			*ft_strjoin_free_reverse(char *s1, char *s2)
{
	char			*cat;
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	if (!(cat = malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s2[i])
	{
		cat[n++] = s2[i];
		i++;
	}
	i = 0;
	while (s1[i])
	{
		cat[n++] = s1[i];
		i++;
	}
	free(s2);
	cat[n] = '\0';
	return (cat);
}

char			*ft_strjoin_free_choose(char *s1, char *s2, int c)
{
	char	*cat;

	if (!(cat = ft_strjoin(s1, s2)))
		return (NULL);
	if (c == 1 || c == 3)
		if (s1)
			free(s1);
	if (c == 2 || c == 3)
		if (s2)
			free(s2);
	return (cat);
}

char			*ft_lutoa_base(long unsigned int n, int base, char *b)
{
	char				*s;
	long unsigned int	i;
	long unsigned int	t;

	if (base < 2 || base > 16)
		return (NULL);
	t = n < 0 ? n * -1 : n;
	i = 1;
	while (t /= base)
		i++;
	t = n < 0 ? n * -1 : n;
	n = (n < 0 && base == 10);
	if ((s = (char*)malloc((i + n + 1) * sizeof(char))))
	{
		s[0] = '-';
		s[i + n] = '\0';
		while (i--)
		{
			s[i + n] = b[t % base];
			t /= base;
		}
	}
	return (s);
}

char			*ft_uitoa_base(unsigned int n, int base, char *b)
{
	char			*s;
	unsigned int	i;
	unsigned int	t;

	if (base < 2 || base > 16)
		return (NULL);
	t = n < 0 ? n * -1 : n;
	i = 1;
	while (t /= base)
		i++;
	t = n < 0 ? n * -1 : n;
	n = (n < 0 && base == 10);
	if ((s = (char*)malloc((i + n + 1) * sizeof(char))))
	{
		s[0] = '-';
		s[i + n] = '\0';
		while (i--)
		{
			s[i + n] = b[t % base];
			t /= base;
		}
	}
	return (s);
}
