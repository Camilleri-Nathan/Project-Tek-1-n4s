/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** reverse a string
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>

char	*my_revstr(char *str)
{
	int	count = strlen(str) - 1;
	char	change_letter = 0;
	int	letter = 0;

	while (letter <= (count)) {
		change_letter = str[letter];
		str[letter] = str[count];
		str[count] = change_letter;
		letter = letter + 1;
		count = count - 1;
	}
	printf("%s\n", str);
	return (str);
}
