/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** make words in an array
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "tools_minish.h"

static int	my_wordlen(char const *str)
{
	int	count = 0;
	int	word = 0;

	while (str[count] != '\0') {
		if (str[count] == ' ' && str[count + 1] > ' ')
			word = word + 1;
		count = count + 1;
	}
	return (word);
}

static char	*write_in_arr(char **tab, char **str, int count)
{
	int	index = 0;
	int	index2 = 0;

	while (str[0][index] != '\0')
		index++;
	tab[count] = malloc(sizeof(char) * (index + 1));
	if (tab[count] == NULL)
		return (MALLOC_ERROR);
	while (str[0][index2] == ' ' || str[0][index2] == '\t')
		index2 += 1;
	while (index2 != index) {
		tab[count][index2] = str[0][index2];
		index2 = index2 + 1;
	}
	tab[count][index2] = '\0';
	return (*tab);
}

char	**do_double_arr(char *str)
{
	int	count = 0;
	int	word = 0;
	char	**tab;

	word = my_wordlen(str);
	tab = malloc(sizeof(char *) * (word + 2));
	if (tab == NULL)
		return (MALLOC_ERROR);
	while (count <= word) {
		if (write_in_arr(tab, &str, count) == MALLOC_ERROR)
			return (MALLOC_ERROR);
		count = count + 1;
	}
	tab[count] = NULL;
	return (tab);
}
