/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** make words in an array
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int	my_wordlen(char const *str)
{
	int	count = 0;
	int	word = 0;

	while (str[count]) {
		if (str[count] == ':')
			word = word + 1;
		count = count + 1;
	}
	return (word + 1);
}

static char	*write_in_arr(char **tab, char *str, int count, int *letter)
{
	int	index = *letter;
	int	index3 = 0;

	while (str[index] && str[index] != ':')
		index++;
	tab[count] = malloc(sizeof(char) * ((index - *letter) + 1));
	if (tab[count] == NULL)
		return (NULL);
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
		return (NULL);
	tab[0] = NULL;
	while (count < word) {
		if (write_in_arr(tab, str, count, &letter) == NULL)
			return (NULL);
		count = count + 1;
	}
	tab[count] = NULL;
	return (tab);
}
