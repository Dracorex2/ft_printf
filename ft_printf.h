/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:16:48 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/14 14:09:00 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

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

#endif