/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:25:21 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/26 02:39:27 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "./ft_printf/ft_printf.h"

void		ft_init_struct(t_elem *save)
{
	save->zero = 0;
	save->minus = 0;
	save->precision = NULL;
	save->width = NULL;
	save->neg = 0;
	save->justapoint = 0;
}

void		ft_free_all(t_elem *save, t_final *taille, int i)
{
	if (i == 0)
	{
		if (save->width != NULL)
			free(save->width);
		if (save->precision != NULL)
			free(save->precision);
	}
	else if (i == 1)
	{
		free(save);
		free(taille);
	}
}

int			ft_printf(const char *s, ...)
{
	t_elem			*save;
	t_final			*taille;
	unsigned int	final_length;

	if (!(save = malloc(sizeof(t_elem))))
		return (-1);
	if (!(taille = ft_calloc(sizeof(t_final), 1)))
		return (-1);
	taille->length = 0;
	va_start(save->ap, s);
	if (ft_parsing_general(s, save, taille) == -1)
		return (-1);
	va_end(save->ap);
	final_length = taille->length;
	ft_free_all(save, taille, 1);
	return (final_length);
}
