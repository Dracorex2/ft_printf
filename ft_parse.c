/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:27:10 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 20:23:57 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse2(t_flag *res, char c)
{
	if (c == '+')
		res->plus = 1;
	else if (c == '-')
		res->minus = 1;
	else if (c == ' ')
		res->space = 1;
	else if (c == '#')
		res->hash = 1;
	else if (c == '0' && !res->point && !res->first)
		res->zero = 1;
	else if (c == ' ')
		res->space = 1;
	else if (c == '.')
		res->point = 1;
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
		if (str[i] == '*' && !res.point && !res.first)
			res.first = va_arg(ap, int);
		else if (str[i] == '*' && res.point && !res.sec)
			res.sec = va_arg(ap, int);
		else if (str[i] >= '1' && str[i] <= '9'  && !res.point && !res.first)
			res.first = ft_abs_atoi(&str[i]);
		else if (str[i] >= '1' && str[i] <= '9' && res.point && !res.sec)
			res.sec = ft_abs_atoi(&str[i]);
		if (res.sec < 0)
			res.point = 0;
		if (res.first < 0)
				res.minus = 1;
		res.first = res.first * (-(res.first < 0) + (res.first > 0));
	}
	res.size = i;
	res.fmt = str[i];
	return (res);
}
