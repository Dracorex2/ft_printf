/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:43:24 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/13 20:25:59 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strprntchr(t_flag flag, char *str)
{
	int len;
	int	i;

	len = 0;
	i = -1;
	if (flag.sec)
	{
		while (flag.sec--)
			len += ft_putchar(str[++i]);
	}
	else
		while (str[++i])
			len += ft_putchar(str[++i]);
	return (len);
}

int	ft_string(char *str, t_flag	flag)
{
	int	i;
	int	len;
	int	space;

	space = 0;
	if (flag.sec && flag.first)
	{
		if (flag.minus)
		{
			ft_strprnt(flag, str);
			ft_space(flag.first - ft_min(ft_strlen(str), flag.sec));
		}
		else
		{
			
		}
	}
	elif (flag.first)
		space = flag.first - ft_strlen(str);
	else
	

	
	return (len);
}
