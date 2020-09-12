/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display_03_pu.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:28:14 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/26 00:57:01 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

static void		ft_ifs_p_display(t_elem *save, t_final *taille,
				char **str, unsigned int l)
{
	if (save->minus == 1)
	{
		ft_putstr_fd(*str, 1);
		ft_preci_size_put_space(save, taille, l);
	}
	else if (save->minus == 0)
	{
		ft_preci_size_put_space(save, taille, l);
		ft_putstr_fd(*str, 1);
	}
	else
		ft_putstr_fd(*str, 1);
	free(*str);
}

int				ft_p_display(t_elem *save, t_final *taille)
{
	char			*pointer;
	char			*firstpart;
	unsigned int	l;

	firstpart = "0x";
	if (!(pointer = ft_lutoa_base(va_arg(save->ap, long unsigned int), 16,
	"0123456789abcdef")))
		return (-1);
	if (save->precision[0] != '\0')
		if (!(pointer = ft_cut_preci_di(save, pointer)))
			return (-1);
	if (!(pointer = ft_strjoin_free_choose(firstpart, pointer, 2)))
		return (-1);
	taille->length += (l = ft_strlen(pointer));
	ft_ifs_p_display(save, taille, &pointer, l);
	return (0);
}

static void		ft_ifs_u_display(t_elem *save, t_final *taille,
				char **nbr, unsigned int l)
{
	if (save->minus == 1)
	{
		ft_putstr_fd(*nbr, 1);
		ft_preci_size_put_space(save, taille, l);
	}
	else if (save->minus == 0 && save->zero == 1)
	{
		ft_preci_size_put_zero(save, taille, l);
		ft_putstr_fd(*nbr, 1);
	}
	else if (save->zero == 0 && save->width[0] != '\0')
	{
		ft_preci_size_put_space(save, taille, l);
		ft_putstr_fd(*nbr, 1);
	}
	else
		ft_putstr_fd(*nbr, 1);
	free(*nbr);
}

int				ft_u_display(t_elem *save, t_final *taille)
{
	char			*nbr;
	unsigned int	l;

	if (!(nbr = ft_utoa(va_arg(save->ap, unsigned int))))
		return (-1);
	if (save->precision[0] != '\0')
		if (!(nbr = ft_cut_preci_di(save, nbr)))
			return (-1);
	taille->length += (l = ft_strlen(nbr));
	ft_ifs_u_display(save, taille, &nbr, l);
	return (0);
}
