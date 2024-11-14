/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:34:48 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/14 17:21:01 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ARGS "|%-*s|", 20, "test"

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
