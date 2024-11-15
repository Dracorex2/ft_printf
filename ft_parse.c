/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:27:10 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/15 14:01:14 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse2(t_flag *res, char str)
{
	if (str == '+')
		res->plus = 1;
	else if (str == '-')
		res->minus = 1;
	else if (str == ' ')
		res->space = 1;
	else if (str == '#')
		res->hash = 1;
	else if (str == '0')
		res->zero = 1;
	else if (str == ' ')
		res->space = 1;
}

t_flag	ft_parse(char *str, va_list ap)
{
	t_flag	res;
	int i;
	
	res = (t_flag){0};
	i = -1;
	while (!ft_ischarset(str[++i]))
	{
		ft_parse2(&res, str[i]);
		if (str[i] == '*')
			res.first = va_arg(ap, int);
		else if (str[i] == '.' && str[i + 1] == '*')
			res.sec = va_arg(ap, int);
		else if (str[i] >= '1' && str[i] <= '9')
			res.first = ft_atoi(&str[i]);
		else if (str[i] == '.')
			res.sec = ft_atoi(&str[++i]);
		while (str[i] >= '1' && str[i] <= '9' 
		&& str[i + 1] >= '0' && str[i +1] <= '9')
				i++;
	}
	res.size = i;
	res.fmt = str[i];
	return (res);
}
