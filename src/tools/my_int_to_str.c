/*
** EPITECH PROJECT, 2018
** my_int_to_str
** File description:
** Transform an int into a string.
*/

#include <stdlib.h>
#include "my.h"

char	*my_int_to_str(int nb)
{
	char	*str;
	int	index = 0;

	str = malloc(sizeof(char) * 4);
	if (str == NULL) {
		return (NULL);
	}
	while (nb >= 10) {
		str[index] = (nb % 10) + '0';
		nb = nb / 10;
		index = index + 1;
		if ((index + 1) % 3 == 0) {
			str = my_realloc(str, index + 3);
		}
	}
	str[index] = nb + '0';
	str[index + 1] = '\0';
	str = my_revstr(str);
	return (str);
}
