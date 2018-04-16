/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** reverse a string
*/

#include <unistd.h>

void	my_putchar(char c);
int	my_strlen(char const *);
int	my_putstr(char const *);

char	*my_revstr(char *str)
{
	int	count = 0;
	char	change_letter = 0;
	int	letter = 0;

	count = my_strlen(str) - 1;
	while (letter <=  (count)) {
		change_letter = str[letter];
		str[letter] = str[count];
		str[count] = change_letter;
		letter = letter + 1;
		count = count - 1;
	}
	my_putstr(str);
	return (str);
}
