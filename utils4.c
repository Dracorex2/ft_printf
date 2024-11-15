/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:11:06 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/15 17:43:12 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnstr(char *str, int n)
{
	int	len;

	len = 0;
	while (n--)
		write(1, &str[len++], 1);
	return (len);
}

int ft_null(t_flag flag)
{
	int	len;

	len = 0;
	if (flag.first)
		len += ft_space(flag.first);
	else
		len += 0;
	return (len);
}