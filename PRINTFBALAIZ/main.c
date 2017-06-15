/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 02:42:19 by fdidelot          #+#    #+#             */
/*   Updated: 2017/06/09 05:50:35 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <locale.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int ret1, ret2;
	char c = 0;
	//setlocale(LC_ALL, "");
	wchar_t ee = 65478;
/*	printf("% o|%+o", 42, 42); //UNDEFINED
	ft_printf("% o|%+o", 42, 42);

	printf("% x|%+x", 42, 42); //UNDEFINED
	ft_printf("% x|%+x", 42, 42);
	
	printf("% p|%+p", 42, 42); //UNDEFINED
	ft_printf("% p|%+p", 42, 42);

	printf("% u|%+u", 42, 42); //UNDEFINED
	ft_printf("% u|%+u", 42, 42);
*/
	printf("%10.20x\n", 65535);
	ft_printf("%.20x\n", 65535);
	/*printf("{%05.S}\n", L"42 c est cool");  //UNDIFINED
	ft_printf("{%05.S}\n", L"42 c est cool");*/
	
	//ret1 = printf("%#.3o\n", 1);
	//ret2 = ft_printf("%#.3o\n", 1);
	
	//printf("%#6o\n", 2500);
	//ft_printf("%#6o\n", 2500);
/*
	printf("{%05.Z}\n", 0);
	ft_printf("{%05.Z}\n", 0);
	
	printf("{%05.%}\n", 0); //UNDEFINED
	ft_printf("{%05.%}\n", 0);
*/
	/*printf("{%05.s}\n", 0); //UNDIFINED
	ft_printf("{%05.s}\n", 0);*/
	return (42);
}
