/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 00:34:55 by snedir            #+#    #+#             */
/*   Updated: 2017/04/20 06:29:13 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include <stdarg.h>

int sum(int nb, ...)
{
	va_list ap;
	int res = 0;
	int i = 0;
	va_start(ap, nb);
	while (i < nb)
	{
		res += va_arg(ap, int);
		i++;
	}
	va_end(ap);
	return (res);
}

int overflow(int nb, long limite)
{
	int i = 0;
	int inc = 0;
	if (nb > 0)
		while (inc < nb)
		{
			printf("haha %ld\n", limite - 1);
			if (i > limite - 1)
				i = -limite;
			inc++;
			i++;
		}
	else
		while (inc > nb)
		{
			printf("huhu %ld\n", limite - 1);
			if (i < limite)
				i = limite - 1;
			inc++;
			i++;
		}
	return (i);
}

long poww(int nb, int puissance)
{
	if (puissance == 0)
		return (1);
	return (nb * poww(nb, puissance - 1));
}

int main()
{
	setlocale(LC_ALL, "");
	//printf("%C", 916);
	/*int ret = printf("sum = %d %s\n", sum(4,5,6,7,8), "sa");
	printf("%d\n", ret);*/
	char c = 1000;
	printf("itest = %d %hhd\n", c, c);
	long ret = poww(2,(int)sizeof(c) * 8);
	printf("poww = %ld\n", ret);
	//printf("%d\n", overflow(c, poww(2,(long)sizeof(c) * 8)));
	//printf("%hhd\n", c);
	//printf("%lu\n", sizeof(9));

}
