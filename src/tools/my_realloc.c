/*
** EPITECH PROJECT, 2018
** my_realloc.c
** File description:
** Realloc a string.
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

char	*my_realloc(char *str, int size)
{
	char	*tmp = str;
	int	str_len = strlen(str);
	int	index = 0;

	str = malloc(sizeof(char) * size + 1);
	while (index < str_len) {
		str[index] = tmp[index];
		index = index + 1;
	}
	str[index] = '\0';
	free(tmp);
	return (str);
}
