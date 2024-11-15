/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:36:49 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/15 13:41:41 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_space(int nb)
{
	int i;

	i = 0;
	while (nb-- > 0)
		i += ft_putchar(' ');
	return (i);
}

int ft_min(int a, int b) 
{
	if (a < b)
		  return a;
	return b;
}

int ft_max(int a, int b) 
{
	if (a > b)
		  return a;
	return b;
}

int	ft_nbrlen_u(uintmax_t nb, int base)
{
	if (nb < (uintmax_t)base)
		return (1);
	else
		return (1 + ft_nbrlen_u(nb / base, base));
}

int	ft_nbrlen_i(int nb)
{
	if (nb == (int)0x80000000)
		return (11);
	else if (nb < 0)
		return (1 + ft_nbrlen_i(-nb));
	else if (nb > 9)
		return (1 + ft_nbrlen_i(nb / 10));
	else
		return (1);
}
