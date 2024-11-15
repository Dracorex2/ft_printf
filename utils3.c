/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:04:23 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/15 12:21:06 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_put_uintmax_hex(uintmax_t n, char *base)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < ft_strlen(base))
	{
		write(1, &(base[n]), 1);
		return 1;
	}
	return (ft_put_uintmax_hex(n / ft_strlen(base), base) 
		+ ft_put_uintmax_hex(n % ft_strlen(base), base));
}

int ft_putstr(char *str)
{
	int	len;

	len = -1;
	while (str[++len])
		write(1, &str[len], 1);
	return (len);
}

int ft_putnchar(char c, int i)
{
	int	len;

	len = i;
	while (i-- > 0)
		write(1, &c, 1);
	return (len);
}

int ft_putnbr(int n)
{
	if (n == (int)0x80000000)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		return (1 + ft_putnbr(n));
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 10)
	{
		write(1, &("0123456789"[n]), 1);
		return (1);
	}
	return (ft_putnbr(n / 10) + ft_putnbr(n % 10));
}
