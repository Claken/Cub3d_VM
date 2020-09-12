/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display_01_csdi.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:27:45 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/26 01:22:02 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

void			ft_c_display(t_elem *save, t_final *taille)
{
	char c;

	c = va_arg(save->ap, int);
	taille->length++;
	if (save->minus == 1)
	{
		ft_putchar_fd(c, 1);
		ft_preci_size_put_space(save, taille, 1);
	}
	else if (save->minus == 0)
	{
		ft_preci_size_put_space(save, taille, 1);
		ft_putchar_fd(c, 1);
	}
	else
		ft_putchar_fd(c, 1);
}

static char		*ft_check_if_null(t_elem *save)
{
	char *p;
	char *string;

	if (!(p = va_arg(save->ap, char*)))
	{
		if (!(string = ft_strdup("(null)")))
			return (NULL);
	}
	else
	{
		if (!(string = ft_strdup(p)))
			return (NULL);
	}
	return (string);
}

int				ft_s_display(t_elem *save, t_final *taille)
{
	char	*string;
	int		l;

	if (!(string = ft_check_if_null(save)))
		return (-1);
	if (save->precision[0] != '\0')
		if (!(string = ft_cut_preci(save, string)))
			return (-1);
	taille->length += (l = ft_strlen(string));
	if (save->minus == 1)
	{
		ft_putstr_fd(string, 1);
		ft_preci_size_put_space(save, taille, l);
	}
	else if (save->minus == 0)
	{
		ft_preci_size_put_space(save, taille, l);
		ft_putstr_fd(string, 1);
	}
	else
		ft_putstr_fd(string, 1);
	free(string);
	return (0);
}

static int		ft_if_di_display(t_elem *save,
				t_final *taille, char **nbr, int l)
{
	if (save->minus == 1)
	{
		ft_put_minus(save, taille);
		ft_putstr_fd(*nbr, 1);
		ft_preci_size_put_space(save, taille, l);
	}
	else if (save->minus == 0 && save->zero == 1)
	{
		ft_put_minus(save, taille);
		if (ft_preci_size_put_zero_di(save, taille, l, nbr) == -1)
			return (-1);
		ft_putstr_fd(*nbr, 1);
	}
	else if (save->zero == 0 && save->width[0] != '\0')
	{
		ft_preci_size_put_space(save, taille, l);
		ft_put_minus(save, taille);
		ft_putstr_fd(*nbr, 1);
	}
	else
	{
		ft_put_minus(save, taille);
		ft_putstr_fd(*nbr, 1);
	}
	return (0);
}

int				ft_di_display(t_elem *save, t_final *taille)
{
	char	*nbr;
	char	*tmp;
	int		l;

	if (!(nbr = ft_itoa(va_arg(save->ap, int))))
		return (-1);
	if (ft_atoi(nbr) < 0)
	{
		tmp = nbr;
		if (!(nbr = ft_substr(nbr, 1, ft_strlen(nbr))))
			return (-1);
		free(tmp);
		save->neg = 1;
	}
	if (save->precision[0] != '\0')
		if (!(nbr = ft_cut_preci_di(save, nbr)))
			return (-1);
	taille->length += (l = ft_strlen(nbr));
	if (ft_if_di_display(save, taille, &nbr, l) == -1)
		return (-1);
	free(nbr);
	return (0);
}
