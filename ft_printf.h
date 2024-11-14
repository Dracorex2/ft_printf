/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:16:48 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/14 18:04:24 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define elif else if

typedef struct {
	bool 	minus;
	bool 	plus;
	bool 	space;
	bool 	hash;
	bool 	zero;
	int		first;
	int		sec;
	char	fmt;
	int		size;
} t_flag;

int		ft_putchar(char s);
int 	ft_purstr(char *str);
int 	ft_printf(const char *, ...);
int		ft_atoi(const char *nptr);
t_flag	ft_parse(char *str, va_list ap);
bool	ft_ischarset(char c);
int		ft_string(char *str, t_flag	flag);
int 	ft_fmtset(t_flag	flag, va_list ap);
void	ft_parse2(t_flag *res, char str);
size_t	ft_strlen(const char *str);
int		ft_space(int nb);
int 	ft_min(int a, int b);
int		ft_char(char str, t_flag	flag);
int		ft_nbrlen_i(int nb);
int		ft_nbrlen_u(size_t nb, int base);
int 	ft_put_uintmax_hex(uintmax_t n);
int 	ft_putstr(char *str);
int		ft_putnil(t_flag flag);
int		ft_pointer(uintmax_t ptr, t_flag flag);
int ft_putnchar(char c, int i);

#endif