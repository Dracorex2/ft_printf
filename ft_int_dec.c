/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:52:30 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/15 14:33:35 by lucmansa         ###   ########.fr       */
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

	len = 0;
	if (flag.zero || flag.sec)
		len += ft_int_dec_zero(nb, flag);
	else if (!flag.minus && flag.first && flag.plus)
		len += ft_space(flag.first - ft_nbrlen_i(nb) - 1)
			+ ft_putchar('+') + ft_putnbr(nb);
	else if (flag.minus && flag.first && flag.plus)
		len += ft_putchar('+') + ft_putnbr(nb) + ft_space(flag.first
			- ft_nbrlen_i(nb) - 1) ;
	else if (!flag.minus && flag.first)
		len += ft_space(flag.first - ft_nbrlen_i(nb))
			+ ft_putnbr(nb);
	else if (flag.minus && flag.first)
		len += ft_putnbr(nb) + ft_space(flag.first
			- ft_nbrlen_i(nb)) ;
	else
		len += ft_putnbr(nb);
	return (len);
}
