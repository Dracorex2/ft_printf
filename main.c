/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:34:48 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 20:45:14 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ARGS "%29p" , 0xf856c9276eecfe4

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
