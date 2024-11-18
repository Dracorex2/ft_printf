/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:37:56 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 19:31:26 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_uint(unsigned int nb, t_flag flag)
{
	int	len;
	int	prnt;

	prnt = 0;
	len = ft_nbrlen_i(nb, 10);
	if (flag.point && ((flag.sec > len) || (!flag.sec && !nb)))
		len = flag.sec;
	flag.zero &= !(flag.point || flag.minus);
	if (!flag.minus && flag.first && !flag.zero)
		prnt += ft_putnchar(' ', flag.first - len);
	if (flag.zero && flag.first - prnt > len)
		len = flag.first - prnt;
	prnt += ft_putnchar('0', len - ft_nbrlen_i(nb, 10));
	if (len != 0)
		prnt += ft_putnbrbase(nb, "0123456789");
	if (flag.minus && flag.first > prnt)
		prnt += ft_putnchar(' ', flag.first - prnt);
	return (prnt);
}
