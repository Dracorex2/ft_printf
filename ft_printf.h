/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:16:48 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/12 19:38:53 by lucmansa         ###   ########.fr       */
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
	char	fmt
} t_flag;

void	ft_putstr(char *s);
int 	ft_printf(const char *, ...);
int		ft_atoi(const char *nptr);
t_flag	ft_parse(char *str, va_list ap);
bool	ft_ischarset(char c);
int		ft_string(char *str, t_flag	flag);


#endif