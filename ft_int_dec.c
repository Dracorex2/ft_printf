/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:52:30 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 19:32:51 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_dec(int nb, t_flag flag)
{
	int	len;
	int	prnt;

	flag.zero &= !(flag.point || flag.minus);
	flag.space &= !flag.plus;
	prnt = 0;
	len = ft_nbrlen_i(nb, 10);
	if (flag.point && ((flag.sec > len) || (flag.sec == 0 && nb == 0)))
		len = flag.sec;
	prnt += ft_putnchar(' ', nb >= 0 && flag.space);
	if (!flag.minus && flag.first && !flag.zero)
		prnt += ft_putnchar(' ', flag.first - (len + prnt
					+ (nb < 0 || flag.plus || flag.space)));
	prnt += ft_putnchar('-', nb < 0);
	prnt += ft_putnchar('+', nb >= 0 && flag.plus);
	if (flag.zero && flag.first - prnt > len)
		len = flag.first - prnt;
	prnt += ft_putnchar('0', len - ft_nbrlen_i(nb, 10));
	if (len)
		prnt += ft_putnbrbase(nb * (-(nb < 0) + (nb > 0)), "0123456789");
	if (flag.minus && flag.first > prnt)
		prnt += ft_putnchar(' ', flag.first - prnt);
	return (prnt);
}
