/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:34:48 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/14 19:18:47 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ARGS "|%20s|", "c"

int	main(void)
{
	int i;
	int j;

	i = ft_printf(ARGS);
	printf("\no = %i", i);
	printf("\n");
	j = printf(ARGS);
	printf("\no = %i", j);
}
