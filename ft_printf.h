/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:16:48 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 21:19:34 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_flag
{
	bool	minus;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero;
	int		first;
	int		sec;
	char	fmt;
	int		size;
	bool	point;
}	t_flag;
///////////////////////////////////////////////////////////////////////////////
int					ft_printf(const char *fmt, ...);
t_flag				ft_parse(char *str, va_list ap);
int					ft_string(char *str, t_flag	flag);
int					ft_char(char str, t_flag	flag);
int					ft_pointer(uintmax_t ptr, t_flag flag);
int					ft_hex(unsigned int nb, t_flag flag);
int					ft_int_dec(int nb, t_flag flag);
int					ft_uint(unsigned int nb, t_flag flag);
///////////////////////////////////////////////////////////////////////////////
int					ft_putnstr(char *str, int n);
int					ft_abs_atoi(const char *nptr);
bool				ft_ischarset(char c);
size_t				ft_strlen(const char *str);
unsigned int		ft_nbrlen(long int nb, int base);
int					ft_putnbrbase(unsigned long int n, char *base);
int					ft_putnchar(char c, int i);

#endif