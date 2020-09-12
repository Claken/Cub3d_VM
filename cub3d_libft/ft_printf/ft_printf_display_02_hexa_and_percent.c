/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display_02_hexa_and_percent.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:27:58 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/26 00:56:10 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

static void		ft_if_hexa_display(t_elem *save,
				t_final *taille, char **hexa, int l)
{
	if (save->minus == 1)
	{
		ft_putstr_fd(*hexa, 1);
		ft_preci_size_put_space(save, taille, l);
	}
	else if (save->minus == 0 && save->zero == 1)
	{
		ft_preci_size_put_zero(save, taille, l);
		ft_putstr_fd(*hexa, 1);
	}
	else if (save->zero == 0 && save->width[0] != '\0')
	{
		ft_preci_size_put_space(save, taille, l);
		ft_putstr_fd(*hexa, 1);
	}
	else
		ft_putstr_fd(*hexa, 1);
	free(*hexa);
}

int				ft_little_hexa_display(t_elem *save, t_final *taille)
{
	char	*hexa;
	int		l;

	if (!(hexa = ft_uitoa_base(va_arg(save->ap, unsigned int), 16,
	"0123456789abcdef")))
		return (-1);
	if (save->precision[0] != '\0')
		if (!(hexa = ft_cut_preci_di(save, hexa)))
			return (-1);
	taille->length += (l = ft_strlen(hexa));
	ft_if_hexa_display(save, taille, &hexa, l);
	return (0);
}

int				ft_big_hexa_display(t_elem *save, t_final *taille)
{
	char	*hexa;
	int		l;

	if (!(hexa = ft_uitoa_base(va_arg(save->ap, unsigned int), 16,
	"0123456789ABCDEF")))
		return (-1);
	if (save->precision[0] != '\0')
		if (!(hexa = ft_cut_preci_di(save, hexa)))
			return (-1);
	taille->length += (l = ft_strlen(hexa));
	ft_if_hexa_display(save, taille, &hexa, l);
	return (0);
}

void			ft_percent_display(t_elem *save, t_final *taille)
{
	char c;

	c = '%';
	taille->length++;
	if (save->minus == 1)
	{
		ft_putchar_fd(c, 1);
		ft_preci_size_put_space(save, taille, 1);
	}
	else if (save->minus == 0 && save->zero == 0)
	{
		ft_preci_size_put_space(save, taille, 1);
		ft_putchar_fd(c, 1);
	}
	else if (save->zero == 1)
	{
		ft_preci_size_put_zero(save, taille, 1);
		ft_putchar_fd(c, 1);
	}
	else
		ft_putchar_fd(c, 1);
}
