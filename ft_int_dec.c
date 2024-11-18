/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:52:30 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 14:21:44 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_dec_zero(int nb, t_flag flag)
{
	int len;

	len = 0;
	if (nb < 0)
	{
		if (flag.zero)
		len += ft_putchar('-') + ft_putnchar('0', flag.first - ft_nbrlen_i(-nb))
			+ ft_putnbr(-nb);
		else
			len += ft_putchar('-') + ft_putnchar('0', flag.sec
			- ft_nbrlen_i(-nb)) + ft_putnbr(-nb);
	}
	else if (flag.space || flag.plus)
		len += ft_int_dec_plus(nb, flag);
	else if (flag.zero)
		len += ft_putnchar('0', flag.first - ft_nbrlen_i(nb))
			+ ft_putnbr(nb);
	else
		len += ft_putnchar('0', flag.sec - ft_nbrlen_i(nb))
			+ ft_putnbr(nb);
	return (len);
}

int	ft_int_dec_plus(int nb, t_flag flag)
{
	int len;

	len = 0;
	if (flag.zero && flag.space)
		len += ft_putchar(' ') + ft_putnchar('0', flag.first
			- ft_nbrlen_i(nb) - 1) + ft_putnbr(nb);
	else if (flag.zero && flag.plus)
		len += ft_putchar('+') + ft_putnchar('0', flag.first
			- ft_nbrlen_i(nb) - 1) + ft_putnbr(nb);
	else if (flag.sec && flag.space)
		len += ft_putchar(' ') + ft_putnchar('0', flag.sec
			- ft_nbrlen_i(nb)) + ft_putnbr(nb);
	else if (flag.sec && flag.plus)
		len += ft_putchar('+') + ft_putnchar('0', flag.sec
			- ft_nbrlen_i(nb)) + ft_putnbr(nb);
	return (len);
}

int	ft_int_dec(int nb, t_flag flag)
{
	int len;
	int	prnt;

	prnt = 0;
	len - ft_nbrlen_i(nb);
	if (flag.point && ((flag.sec > len) || (flag.sec == 0 && nb == 0)))
		len = flag.sec;
	flag.zero &= !(flag.point || flag.minus);
	flag.space &= !flag.plus;
	return (len);
}
