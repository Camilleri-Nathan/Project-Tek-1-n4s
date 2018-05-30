/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** need4stek
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"
#include "get_info.h"
#include "my.h"

void	free_stock(char **stock)
{
	int	count = 0;

	while (stock[count] != NULL) {
		free(stock[count]);
		count++;
	}
	free(stock);
}

int	main(void)
{
	char	**stock = NULL;
	int	end = 0;
	int	quit = 0;

	write(1, "START_SIMULATION\n", 17);
	quit = check_err_parcing(&stock);
	if (atoi(stock[0]) != 1)
		return (84);
	if (quit == 84) {
		return (84);
	}
	while (end == 0) {
		ia(&end, stock);
	}
	free_stock(stock);
	return (0);
}
