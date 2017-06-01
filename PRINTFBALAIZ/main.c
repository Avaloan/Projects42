/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 02:42:19 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/01 05:45:46 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <locale.h>
#include <limits.h>
#include <string.h>

int main()
{
	int ret1, ret2;
	char c = 0;
	setlocale(LC_ALL, "");
	//ret1 = ft_printf("% 04d\n", 654);
	//ret2 = printf("% 04d\n", 654);
	//printf("ft : %d || printf : %d", ret1, ret2);
	ret2 = ft_printf("%2c\n", 0);
	return (42);
}
