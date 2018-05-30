/*
** EPITECH PROJECT, 2018
** my_arraylen.c
** File description:
** Get the lenght of an array.
*/

#include <stdlib.h>

int	my_arraylen(char const **array)
{
	int	index = 0;

	while (array && array[index] != NULL)
		index++;
	return (index);
}
