/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 02:42:37 by snedir            #+#    #+#             */
/*   Updated: 2016/12/14 13:44:25 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int			i;
	int			words;

	i = 0;
	words = 0;
	while (s[i] == c && s[i])
		i++;
	if (s[i] != '\0')
	{
		words++;
		while (s[i] != '\0')
		{
			if (s[i + 1] != '\0' && s[i] == c && s[i + 1] != c)
				words++;
			i++;
		}
	}
	return (words);
}

static int		*count_letters(char const *s, char c, int *words_numbers)
{
	int			i;
	int			letters;
	int			*array;
	int			j;

	i = 0;
	j = 0;
	letters = 0;
	if (!(array = (int*)malloc(*words_numbers * sizeof(int))))
		return (NULL);
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i++] != c)
			letters++;
		while (s[i] != '\0' && s[i] == c)
			i++;
		array[j] = letters;
		letters = 0;
		j++;
	}
	return (array);
}

static void		dimensional_copy(char const *s, char c, char **dest)
{
	int			i;
	int			j;
	int			z;

	i = 0;
	j = 0;
	z = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != '\0' && s[i] != c)
			dest[z][j++] = s[i++];
		while (s[i] != '\0' && s[i] == c)
			i++;
		i--;
		dest[z][j] = '\0';
		j = 0;
		i++;
		z++;
	}
	dest[z] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		*letters_array;
	int		words_numbers;
	char	**new_strings;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words_numbers = count_words(s, c);
	if (!(letters_array = count_letters(s, c, &words_numbers)))
		return (NULL);
	new_strings = (char**)malloc((words_numbers + 1) * sizeof(char*));
	while (i < words_numbers)
	{
		new_strings[i] = (char*)malloc((letters_array[i] + 1) * sizeof(char));
		i++;
	}
	dimensional_copy(s, c, new_strings);
	free(letters_array);
	return (new_strings);
}
