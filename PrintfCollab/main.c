/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 01:09:20 by fdidelot          #+#    #+#             */
/*   Updated: 2017/05/19 00:29:52 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

void print_grid(char **grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		while (grid[i][j])
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
	ft_putchar('\n');
}

int print(char *format, ...)
	{
		va_list ap;
		t_print *elem = NULL;
		t_print *start;
		
		va_start(ap, format);
		start = analyse(format, elem);
		parcours_liste(start, ap);
		int count = print_list(start, format);
		return (count);
	}

int main()
{
	setlocale(LC_ALL, "");
	char str[] = "%hhX";
	t_print	*elem;
	int i = 0;
	int nb = -185;
	unsigned int nb1 = -10;
	unsigned char hh = -65;
	//char *str23 = ft_itoa_base_maj_signed(-185, 10, 0);
	//printf("%s %zu", str23, ft_strlen(str23));

	elem = NULL;
	/*************************************************************************/
	/*free le mask, fill, strsplit*/
	va_list *ap;
	int haha = 0x7845;

	//while (++i < 1000)
	unsigned char nuu = 9;
	size_t jj = 18;

	//int rere = printf("%d\n",&i);
	print("%C %c %x %X %o %u %d\n%s\n", 0x1234, 'g', 15, 14, 8, 0, 1645, "salut les fils de putes");
	//printf("\n\n");
	//print("%d", ret);
	//printf("%C %c %x %X %o %u %d\n", 0x1234, 'f', 15, 14, 8, 15, -1645);
	//print("%d%u", 1645, 15);
}

