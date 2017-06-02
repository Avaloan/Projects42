/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 02:42:19 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/02 06:24:16 by snedir           ###   ########.fr       */
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
	ft_printf("%d",ft_atoi("4294967295"));
	//printf("%-10s is a string", "");
	return (42);
}
