/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:30:50 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/26 00:57:36 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

int			ft_parsing_flags(char c, t_elem *save)
{
	if (c == '0')
	{
		save->zero = 1;
		return (1);
	}
	else if (c == '-')
	{
		save->minus = 1;
		return (1);
	}
	return (0);
}

static int	ft_malloc_save(t_elem *save, int i)
{
	if (i == 1)
	{
		if (save->width == NULL)
		{
			if (!(save->width = malloc(sizeof(char))))
				return (-1);
			save->width[0] = '\0';
		}
	}
	else if (i == 2)
	{
		if (save->precision == NULL)
		{
			if (!(save->precision = malloc(sizeof(char))))
				return (-1);
			save->precision[0] = '\0';
		}
	}
	return (0);
}

int			ft_parsing_width(char c, t_elem *save)
{
	int w;

	if (ft_malloc_save(save, 1) == -1)
		return (-1);
	if (c >= '0' && c <= '9')
	{
		if (!(save->width = ft_strjoin_char(save->width, c)))
			return (-1);
		return (1);
	}
	else if (c == '*')
	{
		if ((w = va_arg(save->ap, int)) < 0)
		{
			save->minus = 1;
			w = w * -1;
		}
		if (!(save->width = ft_strjoin_free_choose(save->width, ft_itoa(w), 3)))
			return (-1);
		return (1);
	}
	return (0);
}

static int	ft_if_preci_star(t_elem *save)
{
	int p;

	if ((p = va_arg(save->ap, int)) < 0)
	{
		save->justapoint = 0;
		return (1);
	}
	if (!(save->precision = ft_strjoin_free_choose(save->precision,
		ft_itoa(p), 3)))
		return (-1);
	save->zero = 0;
	save->justapoint = 0;
	return (1);
}

int			ft_parsing_precision(char c, t_elem *save)
{
	if (ft_malloc_save(save, 2) == -1)
		return (-1);
	if (c == '.')
	{
		save->justapoint = 1;
		return (1);
	}
	if (c >= '0' && c <= '9')
	{
		if (!(save->precision = ft_strjoin_char(save->precision, c)))
			return (-1);
		save->zero = 0;
		save->justapoint = 0;
		return (1);
	}
	else if (c == '*')
		return (ft_if_preci_star(save));
	else if (save->justapoint == 1)
	{
		if (!(save->precision = ft_strjoin_char(save->precision, '0')))
			return (-1);
		save->zero = 0;
		return (0);
	}
	return (0);
}
