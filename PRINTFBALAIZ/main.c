/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 02:42:19 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/03 06:01:06 by fdidelot         ###   ########.fr       */
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
	//ret2 = ft_printf("%sbabubububu%cytol\n", "salsalsiali", 0);
	//ft_printf("%.10d", -42);
	ret1 = ft_printf("1 % 03d\n", 0);
	ret2 = printf("2 % 03d\n", 0);
	ret1 = ft_printf("1 %#.O\n", 0);
	ret2 = printf("2 %#.O\n", 0);
	printf("ret1 = %d\nret2 = %d\n", ret1, ret2);
	return (42);
}
