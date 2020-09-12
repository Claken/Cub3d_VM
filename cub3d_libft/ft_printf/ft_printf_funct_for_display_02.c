/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funct_for_display_02.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:36:00 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/26 00:57:13 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

static char		*ft_preci_positif(int preci, char *nbr)
{
	char	*cut;
	int		i;

	if (!(cut = malloc(sizeof(char) * (preci) + 1)))
		return (NULL);
	i = 0;
	while (i < preci)
		cut[i++] = '0';
	cut[i] = '\0';
	if (!(cut = ft_strjoin_free_choose(cut, nbr, 3)))
		return (NULL);
	return (cut);
}

char			*ft_cut_preci_di(t_elem *save, char *nbr)
{
	int		preci;

	preci = ft_atoi(save->precision) - ft_strlen(nbr);
	if (ft_atoi(save->precision) == 0 && nbr[0] == '0')
	{
		free(nbr);
		return (ft_strdup(""));
	}
	if (preci > 0)
	{
		return (ft_preci_positif(preci, nbr));
	}
	if (ft_atoi(save->precision) < ft_strlen(nbr))
	{
		free(save->precision);
		if (!(save->precision = ft_strdup("0")))
			return (NULL);
	}
	return (nbr);
}

int				ft_preci_size_put_zero_di(t_elem *save,
				t_final *taille, int size, char **nbr)
{
	char	*tmp;
	int		n;
	int		new_size;

	if (ft_atoi(save->precision) >= size)
		new_size = ft_atoi(save->width) - size;
	else
		new_size = ft_atoi(save->width) - ft_atoi(save->precision) - size;
	if (new_size <= 0)
		new_size = 0;
	n = 0;
	if (!(tmp = malloc(sizeof(char) * (new_size) + 1)))
		return (-1);
	if (save->neg && new_size > 0)
		new_size--;
	while (n < new_size)
		tmp[n++] = '0';
	tmp[n] = '\0';
	taille->length += n;
	if (!(*nbr = ft_strjoin_free_choose(tmp, *nbr, 3)))
		return (-1);
	return (0);
}

void			ft_put_minus(t_elem *save, t_final *taille)
{
	if (save->neg == 1)
	{
		ft_putchar_fd('-', 1);
		taille->length++;
	}
}
