/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:05:42 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/19 00:01:30 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int nb, t_flag flag)
{
	int		prnt;
	int		len;
	char	*base;

	base = "0123456789abcdef";
	if (flag.fmt == 'X')
		base = "0123456789ABCDEF";
	prnt = 0;
	len = ft_nbrlen(nb, 16);
	if (flag.point && ((flag.sec > len) || (!flag.sec && !nb)))
		len = flag.sec;
	flag.zero &= !(flag.minus || flag.point);
	if (!flag.minus && !flag.zero && flag.first > prnt + len)
		prnt += ft_putnchar(' ', flag.first - (prnt + len) - (flag.hash * 2));
	prnt += ft_putnchar('0', nb && flag.hash)
		+ ft_putnchar(flag.fmt, nb && flag.hash);
	if (flag.zero && flag.first > prnt + len)
		len = flag.first - prnt;
	prnt += ft_putnchar('0', len - ft_nbrlen(nb, 16));
	if (len != 0)
		prnt += ft_putnbrbase(nb, base);
	if (flag.minus && flag.first > prnt)
		prnt += ft_putnchar(' ', flag.first - prnt);
	return (prnt);
}
