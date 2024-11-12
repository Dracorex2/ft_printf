/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:56:04 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/12 19:43:00 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_fmtset(t_flag	flag, va_list ap)
{
	int i;
	if (flag.fmt == 's')
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
	while (format[++i])
	{
		if (format[i] == '%')
			flag = ft_parse(&format[i++], ap);
		while (!ft_ischarset(format[i]))
			i++;
		tot += ft_fmtset(flag, ap);
		write(1, &format[i], 1);
		tot ++;
	}
	va_end(ap);
	return (tot);
}
