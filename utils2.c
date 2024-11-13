/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:36:49 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/13 19:44:43 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_space(int nb)
{
	int i;

	i = 0;
	while (nb--)
		i += ft_putchar(' ');
	return (i);
}

int ft_min(int a, int b) 
{
	if (a < b)
		  return a;
	return b;
}
