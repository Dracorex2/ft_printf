/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:05:42 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/14 18:59:44 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int ft_hex_hash(t_flag flag, unsigned int nb)
{
	int len;

	len = 0;
	if (!flag.minus && flag.first && !flag.zero)
		len += ft_space(flag.first - ft_nbrlen_u(nb, 16) - 2)
			+ ft_putstr("0x") + ft_put_uintmax_hex(nb, "0123456789abcdef");
	else if (flag.minus && flag.first && !flag.zero)
		len += ft_putstr("0x") + ft_put_uintmax_hex(nb, "0123456789abcdef")
		+ ft_space(flag.first - ft_nbrlen_u(nb, 16) -2) ;
	else if (flag.zero)
		len += ft_putstr("0x") + ft_putnchar('0', flag.first
		- ft_nbrlen_u(nb, 16) - 2) + ft_put_uintmax_hex(nb, "0123456789abcdef");
	else if (flag.sec)
		len += ft_putstr("0x") + ft_putnchar('0', flag.sec
		- ft_nbrlen_u(nb, 16) - 2) + ft_put_uintmax_hex(nb, "0123456789abcdef");
	else
		len += ft_putstr("0x") + ft_put_uintmax_hex(nb, "0123456789abcdef");
	return (len);
}
int		ft_hex(unsigned int nb, t_flag flag)
{
	int len;

	len = 0;
	if (flag.hash)
		len += ft_hex_hash(flag, nb);
	else if (!flag.minus && flag.first && !flag.zero)
		len += ft_space(flag.first - ft_nbrlen_u(nb, 16))
			+ ft_put_uintmax_hex(nb, "0123456789abcdef");
	else if (flag.minus && flag.first && !flag.zero)
		len += ft_put_uintmax_hex(nb, "0123456789abcdef") + ft_space(flag.first
			- ft_nbrlen_u(nb, 16)) ;
	else if (flag.zero)
		len += ft_putnchar('0', flag.first - ft_nbrlen_u(nb, 16))
			+ ft_put_uintmax_hex(nb, "0123456789abcdef");
	else if (flag.sec)
		len += ft_putnchar('0', flag.sec - ft_nbrlen_u(nb, 16))
			+ ft_put_uintmax_hex(nb, "0123456789abcdef");
	else
		len += ft_put_uintmax_hex(nb, "0123456789abcdef");
	return (len);
}

int ft_hex_hash_maj(t_flag flag, unsigned int nb)
{
	int len;

	len = 0;
	if (!flag.minus && flag.first && !flag.zero)
		len += ft_space(flag.first - ft_nbrlen_u(nb, 16) - 2)
			+ ft_putstr("0X") + ft_put_uintmax_hex(nb, "0123456789ABCDEF");
	else if (flag.minus && flag.first && !flag.zero)
		len += ft_putstr("0X") + ft_put_uintmax_hex(nb, "0123456789ABCDEF")
		+ ft_space(flag.first - ft_nbrlen_u(nb, 16) -2) ;
	else if (flag.zero)
		len += ft_putstr("0X") + ft_putnchar('0', flag.first 
			- ft_nbrlen_u(nb, 16) - 2)
				+ ft_put_uintmax_hex(nb, "0123456789ABCDEF");
	else if (flag.sec)
		len += ft_putstr("0X") + ft_putnchar('0', flag.sec
		- ft_nbrlen_u(nb, 16) - 2) + ft_put_uintmax_hex(nb, "0123456789ABCDEF");
	else
		len += ft_putstr("0X") + ft_put_uintmax_hex(nb, "0123456789ABCDEF");
	return (len);
}
int		ft_hex_maj(unsigned int nb, t_flag flag)
{
	int len;

	len = 0;
	if (flag.hash)
		len += ft_hex_hash(flag, nb);
	else if (!flag.minus && flag.first && !flag.zero)
		len += ft_space(flag.first - ft_nbrlen_u(nb, 16))
			+ ft_put_uintmax_hex(nb, "0123456789ABCDEF");
	else if (flag.minus && flag.first && !flag.zero)
		len += ft_put_uintmax_hex(nb, "0123456789ABCDEF") + ft_space(flag.first
			- ft_nbrlen_u(nb, 16)) ;
	else if (flag.zero)
		len += ft_putnchar('0', flag.first - ft_nbrlen_u(nb, 16))
			+ ft_put_uintmax_hex(nb, "0123456789ABCDEF");
	else if (flag.sec)
		len += ft_putnchar('0', flag.sec - ft_nbrlen_u(nb, 16))
			+ ft_put_uintmax_hex(nb, "0123456789ABCDEF");
	else
		len += ft_put_uintmax_hex(nb, "0123456789ABCDEF");
	return (len);
}