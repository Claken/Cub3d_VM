/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:59:36 by sachouam          #+#    #+#             */
/*   Updated: 2020/06/04 18:35:36 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define BUFFER_SIZE 15

int	ft_strlen2(const char *s);
char	*ft_strchr2(const char *s, int c);
char	*ft_substr2(char const *s, unsigned int start, size_t len);
char	*ft_strjoin2(char const *s1, char const *s2);
int	get_next_line(int fd, char **line);

#endif
