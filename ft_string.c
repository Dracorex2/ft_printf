/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:43:24 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 19:10:51 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *str, t_flag	flag)
{
	int	len;
	int	prnt;

	prnt = 0;
	if (!str)
	{
		str = "";
			if (!flag.point || flag.sec >= 6)
				str = "(null)";
	}
	len = ft_strlen(str);
	if (flag.point && flag.sec < len)
		len = flag.sec;
	if (!flag.minus && flag.first)
		prnt += ft_putnchar(' ', flag.first - len) + ft_putnstr(str, len);
	else if (flag.minus && flag.first)
		prnt += ft_putnstr(str, len) + ft_putnchar(' ', flag.first - len);
	else
		prnt += ft_putnstr(str, len);
	return (prnt);
}
