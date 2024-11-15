/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:37:56 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/15 14:45:14 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_uint(unsigned int nb, t_flag flag)
{
	int len;

	len = 0;
	if (flag.zero)
		len += ft_putnchar('0', flag.first - ft_nbrlen_u(nb, 10))
			+ ft_put_uintmax_hex(nb, "0123456789");
	else if (!flag.minus && flag.first)
		len += ft_space(flag.first - ft_nbrlen_u(nb, 10))
			+ ft_put_uintmax_hex(nb, "0123456789");
	else if (flag.minus && flag.first)
		len += ft_put_uintmax_hex(nb, "0123456789") + ft_space(flag.first
			- ft_nbrlen_u(nb, 10)) ;

	else if (flag.sec)
		len += ft_putnchar('0', flag.sec - ft_nbrlen_u(nb, 10))
			+ ft_put_uintmax_hex(nb, "0123456789");
	else
		len += ft_put_uintmax_hex(nb, "0123456789");
	return (len);
}