/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:04:23 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/14 17:52:32 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

int ft_put_uintmax_hex(uintmax_t n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 16)
	{
		write(1, &("0123456789abcdef"[n]), 1);
		return 1;
	}
	return (ft_put_uintmax_hex(n / 16) + ft_put_uintmax_hex(n % 16));

}

int ft_putstr(char *str)
{
	int len;

	len = -1;
	while (str[++len])
		write(1, &str[len], 1);
	return (len);
}

int ft_putnchar(char c, int i)
{
	int len;

	len = i;
	while (i--)
		write(1, &c, 1);
	return (len);
}