/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:27:13 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 21:24:15 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_abs_atoi(const char *nptr)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r')
		|| nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nbr = nbr * 10 + (nptr[i++] - '0');
	return (nbr);
}

bool	ft_ischarset(char c)
{
	const char	*charsert = "cspdiuxX%";
	int			i;

	i = -1;
	while (charsert[++i])
		if (charsert[i] == c)
			return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putnstr(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && (n < 0 || i < n))
		i += ft_putnchar(str[i], 1);
	return (i);
}
