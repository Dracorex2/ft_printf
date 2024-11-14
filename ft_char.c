/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:42:12 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/14 14:18:22 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char str, t_flag	flag)
{
	int	len;

	len = 0;
	if (!flag.minus && flag.first)
		 len += ft_putstringplus(flag, str);
	elif (flag.minus && flag.first)
		len += ft_putstringmin(flag, str);
	else
		len += ft_strprntchr(flag, str);
	return (len);
}