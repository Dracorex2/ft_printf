/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:16:48 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 20:57:45 by lucmansa         ###   ########.fr       */
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

int					ft_putchar(char s);
int					ft_putstr(char *str);
int					ft_printf(const char *fmt, ...);
int					ft_abs_atoi(const char *nptr);
t_flag				ft_parse(char *str, va_list ap);
bool				ft_ischarset(char c);
int					ft_string(char *str, t_flag	flag);
int					ft_fmtset(t_flag	flag, va_list ap);
void				ft_parse2(t_flag *res, char str);
size_t				ft_strlen(const char *str);
int					ft_space(int nb);
int					ft_min(int a, int b);
int					ft_char(char str, t_flag	flag);
unsigned int		ft_nbrlen_i(long int nb, int base);
int					ft_nbrlen_u(size_t nb, int base);
int 				ft_putnbrbase(unsigned long int n, char *base);
int					ft_putnil(t_flag flag);
int					ft_pointer(uintmax_t ptr, t_flag flag);
int					ft_putnchar(char c, int i);
int					ft_hex(unsigned int nb, t_flag flag);
int					ft_hex_hash(t_flag flag, unsigned int nb);
int					ft_hex_maj(unsigned int nb, t_flag flag);
int					ft_hex_hash_maj(t_flag flag, unsigned int nb);
int					ft_int_dec(int nb, t_flag flag);
int					ft_putnbr(unsigned int n);
int					ft_int_dec_zero(int nb, t_flag flag);
int					ft_int_dec_plus(int nb, t_flag flag);
int					ft_uint(unsigned int nb, t_flag flag);
int 				ft_putnstr(char *str, int n);
int					ft_null(t_flag flag);

#endif