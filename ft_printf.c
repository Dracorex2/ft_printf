/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:56:04 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/15 17:30:10 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fmtset(t_flag flag, va_list ap)
{
	int	i;

	i = 0;
	if (flag.fmt == 'c')
		i = ft_char(va_arg(ap, int), flag);
	else if (flag.fmt == 's')
		i = ft_string(va_arg(ap, char *), flag);
	else if (flag.fmt == 'p')
		i = ft_pointer((uintmax_t)va_arg(ap, void *), flag);
	else if (flag.fmt == 'd' || flag.fmt == 'i')
		i = ft_int_dec(va_arg(ap, int), flag);
	else if (flag.fmt == 'u')
		i = ft_uint(va_arg(ap, unsigned int), flag);
	else if (flag.fmt == 'x')
		i = ft_hex(va_arg(ap, unsigned int), flag);
	else if (flag.fmt == 'X')
		i = ft_hex_maj(va_arg(ap, unsigned int), flag);
	else if (flag.fmt == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		i;
	t_flag	flag;
	int		tot;

	va_start(ap, format);
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
