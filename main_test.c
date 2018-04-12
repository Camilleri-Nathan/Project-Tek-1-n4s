/*
** EPITECH PROJECT, 2018
** jf
** File description:
** hfdsoq
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
#include "get_info.h"

int	check_end(char **stock)
{
	int index = 0;
	int count = 0;

	while (stock[index])
		index++;
	index--;
	while (stock[index][count] != '\0') {
		if (stock[index][count] == '-' &&
		    stock[index][count + 1] == '1') {
			return (84);
		}
		count++;
	}
	return (0);
}

int	check_err_parcing(void)
{
	char **stock = NULL;

	stock = do_double_arr(get_next_line(0));
	if (stock == NULL)
		return (84);
	if (check_end(stock))
		return (1);
	if (atoi(stock[0]) != 1)
		return (84);
	return (0);
}

int	parcing_captor(info_t *info, char **stock)
{
	info->n_left = (atof(stock[4]) + atof(stock[5])) / 2;
	info->left = (atof(stock[12]) + atof(stock[13])) / 2;
	info->middle = (atof(stock[19]) + atof(stock[20])) / 2;
	info->n_right = (atof(stock[25]) + atof(stock[26])) / 2;
	info->right = (atof(stock[32]) + atof(stock[33])) / 2;
	return (0);
}

int main(int ac, char **av)
{
	int quit= 0;

	write(1, "START_SIMULATION\n", 17);
	quit = check_err_parcing();
	if (quit == 1)
		return (0);
	else if (quit == 84)
		return (84);
	write(1, "ST0P_SIMULATION\n", 16);
	if (quit == 1)
		return (0);
	else if (quit == 84)
		return (84);
	while (1);
	return (20);
}
