/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:36:49 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 20:55:23 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_nbrlen_i(long int nb, int base)
{
	if (nb < 0)
		nb = -nb;
	if (nb < base)
		return (1);
	return (1 + ft_nbrlen_i(nb / base, base));
}

int ft_putnbrbase(unsigned long int n, char *base)
{

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n == (unsigned long int)-2147483648)
	{
		write(1, "2147483648", 10);
		return (10);
	}
	if (n < ft_strlen(base))
	{
		write(1, &(base[n]), 1);
		return 1;
	}
	return (ft_putnbrbase(n / ft_strlen(base), base) 
		+ ft_putnbrbase(n % ft_strlen(base), base));
}

int ft_putnchar(char c, int i)
{
	int	len;

	len = -1;
	while (++len < i)
		write(1, &c, 1);
	return (len);
}