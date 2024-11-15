/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:43:24 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/15 18:38:29 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string_null(t_flag	flag)
{
	int	len;

	len = 0;
	if (!flag.minus && flag.first && !flag.sec && !flag.point)
		 len += ft_space(flag.first -  6) + ft_putstr("(null)");
	else if (flag.minus && flag.first && !flag.sec && !flag.point)
		 len += ft_putstr("(null)") + ft_space(flag.first - 6);
	else if (!flag.minus && flag.first && flag.sec > 6)
		 len += ft_space(flag.first - 6) + ft_putstr("(null)");
	else if (flag.minus && flag.first && flag.sec > 6)
		 len += ft_putstr("(null)") + ft_space(flag.first - 6);
	else if (flag.first && flag.sec < 6)
		 len += ft_space(flag.first);
	else if ((flag.sec >=0 && flag.sec < 6) && flag.point)
		len = 0;
	else
		len += ft_putstr("(null)");
	return (len);
}

int	ft_string(char *str, t_flag	flag)
{
	int	len;

	len = 0;
	if (!str)
		len += ft_string_null(flag);
	else if (flag.point && !flag.sec)
		len += ft_null(flag);
	else if (!flag.minus && flag.first && !flag.sec)
		 len += ft_space(flag.first - ft_strlen(str)) + ft_putstr(str);
	else if (flag.minus && flag.first && !flag.sec)
		 len += ft_putstr(str) + ft_space(flag.first - ft_strlen(str));
	else if (!flag.minus && flag.first && flag.sec)
		 len += ft_space(flag.first - ft_min(flag.sec, ft_strlen(str)))
		 	+ ft_putnstr(str, ft_min(flag.sec, ft_strlen(str)));
	else if (flag.minus && flag.first && flag.sec)
		 len += ft_putnstr(str, ft_min(flag.sec, ft_strlen(str)))
		 	+ ft_space(flag.first - ft_min(flag.sec, ft_strlen(str)));
	else if (flag.sec)
		len += ft_putnstr(str, ft_min(flag.sec, ft_strlen(str)));
	else
		len += ft_putstr(str);
	return (len);
}
