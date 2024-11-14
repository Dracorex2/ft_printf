/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:42:12 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/14 19:08:02 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c, t_flag	flag)
{
	int	len;

	len = 0;
	if (!flag.minus && flag.first)
		len += ft_space(flag.first - 1) + ft_putchar(c);
	else if (flag.minus && flag.first)
		len += ft_putchar(c) + ft_space(flag.first - 1);
	else
		len += ft_putchar(c);
	return (len);
}
