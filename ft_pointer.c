/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:32:00 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 20:57:54 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalen(unsigned long nbr)
{
	int	count;

	count = 0;
	while (nbr >= 16 || nbr % 16 != 0)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

int	ft_pointer(uintmax_t ptr, t_flag flag)
{
	int	printed;

	printed = 0;
	if (!flag.minus && ptr)
		printed += ft_putnchar(' ', flag.first - ft_hexalen(ptr) - 2);
	else if (!flag.minus && !ptr)
		printed += ft_putnchar(' ', flag.first - 5);
	if (!ptr)
			printed += ft_putnstr("(nil)", 5);
	else
	{
		printed += ft_putnstr("0x", 2);
		printed += ft_putnbrbase(ptr, "0123456789abcdef");
	}
	if (flag.minus)
		printed += ft_putnchar(' ', flag.first - printed);
	return (printed);
}
