/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:56:04 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/14 17:23:13 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_fmtset(t_flag	flag, va_list ap)
{
	int i;

	i = 0;
	if (flag.fmt == 'c')
		i = ft_char(va_arg(ap, int), flag);
	elif (flag.fmt == 's')
		i = ft_string(va_arg(ap, char *), flag);
	elif (flag.fmt == 'p')
		i = ft_pointer((uintmax_t)va_arg(ap, void *), flag);
	elif (flag.fmt == 'd' && flag.fmt == 'i')
		i = ft_string(va_arg(ap, char *), flag);
	elif (flag.fmt == 'u')
		i = ft_string(va_arg(ap, char *), flag);
	elif (flag.fmt == 'x' && flag.fmt == 'X')
		i = ft_string(va_arg(ap, unsigned int), flag);
	elif (flag.fmt == '%')
		i = ft_putchar('%');
	return (i);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int		i;
	t_flag	flag;
	int		tot;
	
	i = -1;
	tot = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			flag = ft_parse((char *)&format[i + 1], ap);
			i += flag.size + 1;
			tot += ft_fmtset(flag, ap);
		}
		else
			tot += ft_putchar(format[i]);
	}
	va_end(ap);
	return (tot);
}
