/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:09:30 by snedir            #+#    #+#             */
/*   Updated: 2018/02/09 04:54:00 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int ants = 100;
	char **map;
	int i = 0;
	int *taille_chemins;
	int nombre_chemins = 0;
	int parcours = 0;
	int *stock_ants;

	char *s = "lolol";
	char *c = "ccolol";
	printf(s);
	printf("Nombre chemins : \n");
	scanf("%d", &nombre_chemins);
	taille_chemins = (int*)malloc(sizeof(int) * nombre_chemins);
	bzero(taille_chemins, nombre_chemins);
	stock_ants = (int*)malloc(sizeof(int) * nombre_chemins);
	bzero(stock_ants, nombre_chemins);
	while (i < nombre_chemins)
	{
		printf("taille chemin [%d] : \n", i);
		scanf("%d", &taille_chemins[i]);
		i++;
	}
	i = 0;
	while (parcours < ants)
	{
		while (i < nombre_chemins)
		{
			stock_ants[i] += 1;
			printf("Fourmis %d chemin %d salle %d | ", parcours, i, stock_ants[i]);
			parcours++;
			i++;
		}
		printf("\n");
		i = 0;
	}
}
