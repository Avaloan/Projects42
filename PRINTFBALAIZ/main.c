/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 02:42:19 by fdidelot          #+#    #+#             */
/*   Updated: 2017/05/30 08:54:03 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <locale.h>
#include <limits.h>

int main()
{
	int ret1, ret2;
	char c = 0;
	setlocale(LC_ALL, "");
	ret1 = ft_printf("%.s", "42");
	printf("ret1 = %d\n", ret1);
	//printf("string %s\n digit %d\n address %p\n perc %%\n lstring %S\n ldigit %D\n digit %i\n oct %o\n \
	loct %O\n unsign %u\n Lunsigned %U\n hex %x\n HEX %X\n char %c\n \
		lchar %C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	//printf("%O\n", 100000);
	//ret1 = printf("%C", 0);
	//char *str = ft_strdup("\0");
	//printf("str %s", str);
	//printf("REAL %hhO, %hhO\n", 0, USHRT_MAX);
	//ft_printf("FAKE %hhO, %hhO\n", 0, USHRT_MAX);
	//write(1, &c, 1);
	//ft_printf("{%-15Z}", 123);
}

