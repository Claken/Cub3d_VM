/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 00:03:37 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/26 02:31:28 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

static int		ft_len(unsigned int nbr)
{
	int		a;
	long	b;

	a = 0;
	b = (long)nbr;
	while (b)
	{
		b /= 10;
		a++;
	}
	return (a);
}

static void		ft_strrev(char *str)
{
	int		a;
	int		b;
	char	c;

	a = 0;
	b = 0;
	while (str[b])
		b++;
	b--;
	while (a < b)
	{
		c = str[a];
		str[a] = str[b];
		str[b] = c;
		a++;
		b--;
	}
}

static void		ft_fill(unsigned int nb, int a, char *s)
{
	char	c;

	while (nb > 0)
	{
		c = ((nb % 10) + '0');
		s[a] = c;
		nb /= 10;
		a++;
	}
	s[a] = '\0';
}

char			*ft_utoa(unsigned int nb)
{
	int		a;
	char	*s;

	a = 0;
	if (nb == 0)
	{
		if (!(s = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	if (!(s = (char *)malloc(sizeof(char) * ft_len(nb) + 1)))
		return (NULL);
	ft_fill(nb, a, s);
	ft_strrev(s);
	return (s);
}
