/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:32:00 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/15 15:04:37 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnil(t_flag flag)
{
	int	len;

	len = 0;
	if (!flag.minus && flag.first)
		len += ft_space(flag.first - 5) + ft_putstr("(nil)");
	else if (flag.minus && flag.first)
		len += ft_putstr("(nil)") + ft_space(flag.first - 5);
	else
		len += ft_putstr("(nil)");
	return (len);
}

int	ft_pointer(uintmax_t ptr, t_flag flag)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (ft_putnil(flag));
	if (!flag.minus && flag.first)
		len += ft_space(flag.first - ft_nbrlen_u(ptr, 16) - 2)
			+ ft_putstr("0x") + ft_put_uintmax_hex(ptr, "0123456789abcdef");
	else if (flag.minus && flag.first)
		len += ft_putstr("0x") + ft_put_uintmax_hex(ptr, "0123456789abcdef")
			+ ft_space(flag.first - ft_nbrlen_u(ptr, 16) - 2);
	else
		len += ft_putstr("0x") + ft_put_uintmax_hex(ptr, "0123456789abcdef");
	return (len);
}
