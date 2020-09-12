/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funct_for_display_01.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:22:33 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/26 01:03:17 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

void	ft_preci_size_put_space(t_elem *save, t_final *taille, int size)
{
	int		i;
	int		new_size;

	if (ft_atoi(save->precision) >= size)
		new_size = ft_atoi(save->width) - size;
	else
		new_size = ft_atoi(save->width) - ft_atoi(save->precision) - size;
	if (new_size <= 0)
		new_size = 0;
	i = 0;
	if (save->neg && new_size > 0)
		new_size--;
	while (i < new_size)
	{
		ft_putchar_fd(' ', 1);
		i++;
		taille->length++;
	}
}

void	ft_preci_size_put_zero(t_elem *save, t_final *taille, int size)
{
	int		i;
	int		new_size;

	if (ft_atoi(save->precision) >= size)
		new_size = ft_atoi(save->width) - size;
	else
		new_size = ft_atoi(save->width) - ft_atoi(save->precision) - size;
	if (new_size <= 0)
		new_size = 0;
	i = 0;
	while (i < new_size)
	{
		ft_putchar_fd('0', 1);
		i++;
		taille->length++;
	}
}

char	*ft_cut_preci(t_elem *save, char *string)
{
	char	*cut;
	int		preci;
	int		n;
	int		i;

	n = 0;
	i = 0;
	preci = ft_atoi(save->precision);
	if (!(cut = malloc(sizeof(char) * (preci) + 1)))
		return (NULL);
	while (n < preci)
		cut[n++] = string[i++];
	cut[n] = '\0';
	free(string);
	return (cut);
}
