/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:05:42 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/14 18:07:55 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int ft_hex_hash(t_flag flag, unsigned int nb)
{

}

int	ft_hex(t_flag flag, unsigned int nb)
{
	int len;

	len = 0;
	if (flag.hash)
		len += ft_hex_hash(flag, nb);
	elif (!flag.minus && flag.first && !flag.zero)
		len += ft_space(flag.first - ft_nbrlen_u(nb, 16))
			+ ft_put_uintmax_hex(nb);
	elif (flag.minus && flag.first && !flag.zero)
		len += ft_put_uintmax_hex(nb) + ft_space(flag.first
			- ft_nbrlen_u(nb, 16)) ;
	elif (flag.zero || flag.sec)
		len += ft_putnchar('0', flag.first - ft_nbrlen_u(nb, 16))
			+ ft_put_uintmax_hex(nb);
	else
		len += ft_put_uintmax_hex(nb);
	return (len);
}
 