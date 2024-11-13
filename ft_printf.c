/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:56:04 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/13 17:27:07 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_fmtset(t_flag	flag, va_list ap)
{
	int i;

	i = 0;
	if (flag.fmt == 's')
		i = ft_string(va_arg(ap, char *), flag);
	elif (flag.fmt == 'd' && flag.fmt == 'i')
		i = ft_string(va_arg(ap, char *), flag);
	elif (flag.fmt == 'c')
		i = ft_string(va_arg(ap, char *), flag);
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
	while (format[++i] != 0)
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
