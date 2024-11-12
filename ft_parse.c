/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:27:10 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/12 19:33:20 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse2(t_flag res, char str)
{
	if (str == '+')
		res.plus = 1;
	elif (str == '-')
		res.minus = 1;
	elif (str == ' ')
		res.space = 1;
	elif (str == '#')
		res.hash = 1;
	elif (str == '0')
		res.zero = 1;
}

t_flag	ft_parse(char *str, va_list ap)
{
	t_flag	res;
	int i;
	
	res = (t_flag){0};
	i = 0;
	while (!ft_ischarset(str[i]))
	{
		ft_parse2(res, str);
		if (str[i] == '*')
			res.first = va_arg(ap, int);
		elif (str[i] == '.' && str[i + 1] == '*')
			res.sec = va_arg(ap, int);
		elif (str[i] >= '1' && str[i] <= '9')
		res.first = ft_atoi(&str[i]);
		elif (str[i] == '.' && str[i + 1])
		res.sec = ft_atoi(&str[i + 1]);
		i++;
	}
	res.fmt = str[i];
	return (res);
}
