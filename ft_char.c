/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:42:12 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 19:06:05 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c, t_flag	flag)
{
	int	prnt;

	prnt = 0;
	if (!flag.minus && flag.first)
		prnt += ft_putnchar(' ', flag.first - 1) + ft_putnchar(c, 1);
	else if (flag.minus && flag.first)
		prnt += ft_putnchar(c, 1) + ft_putnchar(' ', flag.first - 1);
	else
		prnt += ft_putnchar(c, 1);
	return (prnt);
}
