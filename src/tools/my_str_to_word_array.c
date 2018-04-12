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
		if (str[count] == ' ' ||
		    str[count] == '\t')
			word = word + 1;
		count = count + 1;
	}
	return (word + 1);
}

static char	*write_in_arr(char **tab, char *str, int count, int *letter)
{
	int	index = *letter;
	int	index3 = 0;

	while (str[index] != ' ' && str[index] != '\0')
		index++;
	tab[count] = malloc(sizeof(char) * ((index - *letter) + 1));
	if (tab[count] == NULL)
		return (MALLOC_ERROR);
	while (*letter < index) {
		tab[count][index3] = str[*letter];
		*letter += 1;
		index3 += 1;
	}
	*letter += 1;
	tab[count][index3] = '\0';
	return (*tab);
}

char	**do_double_arr(char *str)
{
	int	letter = 0;
	int	count = 0;
	int	word = 0;
	char	**tab;

	word = my_wordlen(str);
	tab = malloc(sizeof(char *) * (word + 1));
	if (tab == NULL)
		return (MALLOC_ERROR);
	tab[0] = NULL;
	while (count < word) {
		if (write_in_arr(tab, str, count, &letter) == MALLOC_ERROR)
			return (MALLOC_ERROR);
		count = count + 1;
	}
	tab[count] = NULL;
	return (tab);
}
