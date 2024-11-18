/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:51:59 by lucmansa          #+#    #+#             */
/*   Updated: 2024/11/18 23:11:12 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    int i;
    int j;
    #define ARG "%#0199x" ,1267767500u

    i = ft_printf(ARG);
    printf("i = %i", i);
    printf("\n");
    j = printf(ARG);
    printf("j = %i", j);
}
