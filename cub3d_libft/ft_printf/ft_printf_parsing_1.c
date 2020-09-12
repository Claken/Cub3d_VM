/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:30:36 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/26 02:35:24 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

static int	ft_while_parsing(int i, const char *s, t_elem *save)
{
	int j;

	j = 0;
	while ((j = ft_parsing_flags(s[i], save)) == 1)
		i++;
	if (j == -1)
		return (j);
	while ((j = ft_parsing_width(s[i], save)) == 1)
		i++;
	if (j == -1)
		return (j);
	while ((j = ft_parsing_precision(s[i], save)) == 1)
		i++;
	if (j == -1)
		return (j);
	return (i);
}

static void	ft_for_the_norm(int n, t_elem *save, t_final *taille)
{
	if (n == 0)
		ft_preci_size_put_space(save, taille, 1);
	ft_free_all(save, taille, 0);
}

int			ft_parsing_general(const char *s, t_elem *save, t_final *taille)
{
	int i;
	int n;

	i = 0;
	while (s[i])
	{
		n = 0;
		if (s[i] == '%')
		{
			ft_init_struct(save);
			i++;
			if ((i = ft_while_parsing(i, s, save)) == -1)
				return (-1);
			if ((n = ft_parsing_type(s[i], save, taille)) == -1)
				return (-1);
			i += n;
			ft_for_the_norm(n, save, taille);
		}
		else
		{
			ft_putchar_fd(s[i++], 1);
			taille->length++;
		}
	}
	return (0);
}

int			ft_parsing_type(char c, t_elem *save, t_final *taille)
{
	int i;

	i = 0;
	if (c == 'c')
		ft_c_display(save, taille);
	if (c == 's')
		i = ft_s_display(save, taille);
	if (c == 'p')
		i = ft_p_display(save, taille);
	if (c == 'd' || c == 'i')
		i = ft_di_display(save, taille);
	if (c == 'u')
		i = ft_u_display(save, taille);
	if (c == 'x')
		i = ft_little_hexa_display(save, taille);
	if (c == 'X')
		i = ft_big_hexa_display(save, taille);
	if (c == '%')
		ft_percent_display(save, taille);
	if (i == -1)
		return (i);
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
