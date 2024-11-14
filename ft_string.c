/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:43:24 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/14 18:59:44 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strprntchr(t_flag flag, char *str)
{
	int len;
	int	i;

	len = 0;
	i = -1;
	if (flag.sec && flag.sec < ft_strlen(str))
	{
		while (flag.sec--)
			len += ft_putchar(str[++i]);
	}
	else
		while (str[++i])
			len += ft_putchar(str[i]);
	return (len);
}

int	ft_putstringmin(t_flag flag, char *str)
{
	int	len;

	len = 0;
	if (flag.sec)
	{
		len += ft_strprntchr(flag, str);
		len += ft_space(flag.first - ft_min(ft_strlen(str), flag.sec));
	}
	else
	{
		len += ft_strprntchr(flag, str);
		len += ft_space(flag.first - ft_strlen(str));
	}
	return (len);
}

int	ft_putstringplus(t_flag flag, char *str)
{
	int	len;

	len = 0;
	if (flag.sec)
	{
		len += ft_space(flag.first - ft_min(ft_strlen(str), flag.sec));
		len += ft_strprntchr(flag, str);
	}
	else
	{
		len += ft_space(flag.first - ft_strlen(str));
		len += ft_strprntchr(flag, str);
	}
	return (len);
}

int	ft_string(char *str, t_flag	flag)
{
	int	len;

	len = 0;
	if (!flag.minus && flag.first)
		 len += ft_putstringplus(flag, str);
	else if (flag.minus && flag.first)
		len += ft_putstringmin(flag, str);
	else
		len += ft_strprntchr(flag, str);
	return (len);
}
