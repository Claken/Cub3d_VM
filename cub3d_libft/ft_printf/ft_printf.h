/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:04:41 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/26 02:37:36 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_elem
{
	unsigned int	zero;
	unsigned int	minus;
	char			*precision;
	char			*width;
	va_list			ap;
	unsigned int	neg;
	unsigned int	justapoint;
}					t_elem;

typedef struct		s_final
{
	unsigned int	length;
}					t_final;

void				ft_init_struct(t_elem *save);
void				ft_free_all(t_elem *save, t_final *taille, int i);

void				ft_c_display(t_elem *save, t_final *taille);
int					ft_s_display(t_elem *save, t_final *taille);
int					ft_di_display(t_elem *save, t_final *taille);

int					ft_little_hexa_display(t_elem *save, t_final *taille);
int					ft_big_hexa_display(t_elem *save, t_final *taille);
void				ft_percent_display(t_elem *save, t_final *taille);

int					ft_p_display(t_elem *save, t_final *taille);
int					ft_u_display(t_elem *save, t_final *taille);

void				ft_preci_size_put_space(t_elem *save,
					t_final *taille, int size);
void				ft_preci_size_put_zero(t_elem *save,
					t_final *taille, int size);
char				*ft_cut_preci(t_elem *save, char *string);

char				*ft_cut_preci_di(t_elem *save, char *nbr);
int					ft_preci_size_put_zero_di(t_elem *save,
					t_final *taille, int size, char **nbr);
void				ft_put_minus(t_elem *save, t_final *taille);

int					ft_parsing_general(const char *s, t_elem *save,
					t_final *taille);
int					ft_parsing_type(char c, t_elem *save, t_final *taille);

int					ft_parsing_flags(char c, t_elem *save);
int					ft_parsing_width(char c, t_elem *save);
int					ft_parsing_precision(char c, t_elem *save);

char				*ft_strjoin_char(char *s1, char s2);
char				*ft_strjoin_free_reverse(char *s1, char *s2);
char				*ft_strjoin_free_choose(char *s1, char *s2, int c);
char				*ft_lutoa_base(long unsigned int n, int base, char *b);
char				*ft_uitoa_base(unsigned int n, int base, char *b);

char				*ft_utoa(unsigned int nb);

#endif
