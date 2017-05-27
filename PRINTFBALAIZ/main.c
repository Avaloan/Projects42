/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 02:42:19 by fdidelot          #+#    #+#             */
/*   Updated: 2017/05/28 01:07:03 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <locale.h>
#include <limits.h>

int main()
{
	int ret1, ret2;
//	setlocale(LC_ALL, "");
	//printf("%lld\n", -9223372036854775808);ret1 = ft_printf("%s", NULL);
	ft_printf("@moulinette %s", NULL);
}
